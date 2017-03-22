#include<stdio.h> //printf
#include<string.h>    //strlen
#include<stdlib.h>    //malloc
#include<sys/socket.h>    //you know what this is for
#include<arpa/inet.h> //inet_addr , inet_ntoa , ntohs etc
#include<netinet/in.h>
#include<unistd.h>    //getpid
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include<unistd.h>    //usleep
#include<fcntl.h> //fcntl
#include <errno.h>


#include "dns.h"
//List of DNS Servers registered on the system
char dns_servers[10][100];
int dns_server_count = 0;
//Types of DNS resource records :)

static unsigned short dns_id = 0;//0x1122;/**< DNS query id  */
static unsigned char*  dns_buf;
static unsigned char* get_domain_name;
static unsigned long get_domain_ip;/**< Resolved ip address */
static QUERYDATA query_data;/**< Query type */

enum
  {
    T_A=1, //Ipv4 address
    T_NS=2, //Nameserver
    T_CNAME= 5, // canonical name
    T_SOA=6, /* start of authority zone */
    T_PTR=12, /* domain name pointer */
    T_HINFO = 13,
    T_MX=15,
    T_TXT = 16,
    T_RP = 17,
    T_AFSDB = 18,
    T_AAAA  = 28,
    T_LOC = 29,
    T_SRV = 33,
    T_NAPTR = 25,
    T_RRSIG = 46,
    T_NSEC = 47,
    T_DNSKEY = 48
    
  };//Mail server


//DNS header structure
struct DNS_HEADER
{
    unsigned short len;
    unsigned short id; // identification number
 
    unsigned char rd :1; // recursion desired
    unsigned char tc :1; // truncated message
    unsigned char aa :1; // authoritive answer
    unsigned char opcode :4; // purpose of message
    unsigned char qr :1; // query/response flag
 
    unsigned char rcode :4; // response code
    unsigned char cd :1; // checking disabled
    unsigned char ad :1; // authenticated data
    unsigned char z :1; // its z! reserved
    unsigned char ra :1; // recursion available
  //    unsigned char adbit :1;
  
    unsigned short q_count; // number of question entries
    unsigned short ans_count; // number of answer entries
    unsigned short auth_count; // number of authority entries
    unsigned short add_count; // number of resource entries
};
typedef struct DNS_HEADER DNS_H;

struct QUESTION
{
    unsigned short qtype;
    unsigned short qclass;
};
 
//Constant sized fields of the resource record structure
#pragma pack(push, 1)
struct R_DATA
{
    unsigned short type;
    unsigned short _class;
    unsigned int ttl;
    unsigned short data_len;
};
#pragma pack(pop)
 
//Pointers to resource record contents
struct RES_RECORD
{
    unsigned char *name;
    struct R_DATA *resource;
    unsigned char *rdata;
};
 
//Structure of a Query
typedef struct
{
    unsigned char *name;
    struct QUESTION *ques;
} QUERY;


static int dns_parse_reponse(void);/* analyze a response from DNS sever */
static unsigned char * dns_parse_question(unsigned char * cp);/* analyze a question part in resources recode */
static unsigned char * dns_answer(unsigned char *cp);/* analyze a answer part in resources recode */
static int parse_name(char* cp,char* qname, unsigned int qname_maxlen);/* analyze a qname in each part. */

//Function Prototypes
void ChangetoDnsNameFormat (unsigned char*,unsigned char*);
void ReadName(unsigned char* reader,unsigned char* buffer,int* count, unsigned char* dst_buf, size_t data_len, unsigned short type, unsigned char* dns);
int hostname_to_ip(const char *hostname , char *ip);
void parse_ip(unsigned char* data);
void parse_ptr(unsigned char* data, unsigned short data_len, unsigned char* dns);
void parse_soa(unsigned char* data, unsigned short data_len, unsigned char* dns);
void parse_hinfo(unsigned char* data, unsigned short data_len);
void parse_rrsig(unsigned char* data, unsigned short data_len);
unsigned int readString(unsigned char* data, unsigned char* dns_packet_resp, unsigned char* name);
int getName(unsigned char* data, unsigned char* dns_packet_resp);
void parse_ns(unsigned char* data, unsigned char* dns);
void parse_mx(unsigned char* data, unsigned short data_len, unsigned char* dns_packet_resp);
void parse_txt(unsigned char* data, unsigned short data_len);
unsigned int readSOA(unsigned char* data, unsigned char* dns_packet_resp, unsigned char* name);

/*
 * Perform a DNS query by sending a packet
 * */
void ngethostbyname(const char *que , const char *server, int query_type, int to)
{
    int s;
    unsigned char name[256] = {0};
    unsigned char buf[65536] = {0};
    struct hostent *he = NULL;
    struct sockaddr_in dest = {0};
 
    DNS_H *dns = NULL;
 
    s = socket(AF_INET , SOCK_STREAM , IPPROTO_TCP);
    if(s<0)
    {
        printf("Conn refused");
        return;
    }
    struct timeval timeout;
    timeout.tv_sec = to;
    timeout.tv_usec = 0;

    if (setsockopt (s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout,
            sizeof(timeout)) < 0) {
        printf("setsockopt failed\n");
    }

    printf("Get host by name\n");
    char server_ip[100] = {0};
    if( hostname_to_ip(server, server_ip) != 0){
      return;
    }
    printf("Nameserver IP: %s\n", server_ip);
    dest.sin_addr.s_addr = inet_addr(server_ip);
    dest.sin_family = AF_INET;
    dest.sin_port = htons(53);

    long arg = 0;
    int res = 0;
    fd_set myset;
    int valopt;

    socklen_t lon;

    if( (arg = fcntl(s, F_GETFL, NULL)) < 0) {
        fprintf(stderr, "Error fcntl(..., F_GETFL) (%s)\n", strerror(errno));
        exit(0);
    }
    arg |= O_NONBLOCK;
    if( fcntl(s, F_SETFL, arg) < 0) {
        fprintf(stderr, "Error fcntl(..., F_SETFL) (%s)\n", strerror(errno));
        exit(0);
    }
    // Trying to connect with timeout
    res = connect(s, (struct sockaddr *)&dest, sizeof(dest));
    if (res < 0) {
        if (errno == EINPROGRESS) {
            fprintf(stderr, "EINPROGRESS in connect() - selecting\n");
            do {
                timeout.tv_sec = to;
                timeout.tv_usec = 0;
                FD_ZERO(&myset);
                FD_SET(s, &myset);
                res = select(s+1, NULL, &myset, NULL, &timeout);
                if (res < 0 && errno != EINTR) {
                    fprintf(stderr, "Error connecting %d - %s\n", errno, strerror(errno));
                    return;
                }
                else if (res > 0) {
                    // Socket selected for write
                    lon = sizeof(int);
                    if (getsockopt(s, SOL_SOCKET, SO_ERROR, (void*)(&valopt), &lon) < 0) {
                        fprintf(stderr, "Error in getsockopt() %d - %s\n", errno, strerror(errno));
                        return;
                    }
                    // Check the value returned...
                    if (valopt) {
                        fprintf(stderr, "Error in delayed connection() %d - %s\n", valopt, strerror(valopt)
                        );
                        return;
                    }
                    break;
                }
                else {
                    fprintf(stderr, "Timeout in select() - Cancelling!\n");
                    return;
                }
            } while (1);
        }
        else {
            fprintf(stderr, "Error connecting %d - %s\n", errno, strerror(errno));
            return;
        }
    }
    // Set to blocking mode again...
    if( (arg = fcntl(s, F_GETFL, NULL)) < 0) {
        fprintf(stderr, "Error fcntl(..., F_GETFL) (%s)\n", strerror(errno));
        return;
    }
    arg &= (~O_NONBLOCK);
    if( fcntl(s, F_SETFL, arg) < 0) {
        fprintf(stderr, "Error fcntl(..., F_SETFL) (%s)\n", strerror(errno));
        return;
    }


    if (connect(s,(struct sockaddr *) &dest, sizeof(dest)) < 0)
    {
        printf("ERROR connecting\n");
        return;
    }

    unsigned char *qname;
    struct QUESTION *qinfo = NULL;
    unsigned char host[128] = {0}; 
      //Set the DNS structure to standard queries

    snprintf(host, 128, "%s", que);
    printf("\nResolving %s\n" , host);

    dns = (struct DNS_HEADER *)&buf;

    dns_id = getpid();
    dns->id = (unsigned short) htons(dns_id);
    dns->qr = 0; //This is a query
    dns->opcode = 0; //This is a standard query
    dns->aa = 0; //Not Authoritative
    dns->tc = 0; //This message is not truncated
    dns->rd = 0; //Recursion Desired
    dns->ra = 0; //Recursion not available! hey we dont have it (lol)
    dns->z = 0;
    dns->ad = 1;
    dns->cd = 0;
    dns->rcode = 0;
    dns->q_count = htons(1); //we have only 1 question
    dns->ans_count = 0;
    dns->auth_count = 0;
    dns->add_count = 0;// htons(1);

    //point to the query portion
    qname =(unsigned char*)&buf[sizeof(struct DNS_HEADER)];
    ChangetoDnsNameFormat(qname , host);
    qinfo =(struct QUESTION*)&buf[sizeof(struct DNS_HEADER) + (strlen((const char*)qname) + 1)]; //fill it
    qinfo->qtype = htons( query_type ); //type of the query , A , MX , CNAME , NS etc
    qinfo->qclass = htons(1);
    dns->len = htons((unsigned int)sizeof(struct DNS_HEADER) + (strlen((const char*)qname)+1) + sizeof(struct QUESTION)-2);
    
    int len = (unsigned int)sizeof(struct DNS_HEADER) + (strlen((const char*)qname)+1) + sizeof(struct QUESTION);
    int n = write(s, (char*)buf, len);
    if (n < 0)
      perror("ERROR writing to socket");

    bzero(buf, 65536);

    enum{BUFSIZE=65536};
    char replyMessage[BUFSIZE] = {0};
    ssize_t numBytesRecv = 0;
    int off = 0;
    int data_length = 0;
    do
      {
	memset(&replyMessage, 0, sizeof(replyMessage));
	numBytesRecv = recv(s, replyMessage, BUFSIZE, 0);
	if(off == 0 && numBytesRecv >= 2)
	  {
	    data_length = ((*(replyMessage) << 8) &0xFF00) | (*(replyMessage+1) & 0xFF);
	  }
	if ( numBytesRecv < 0)
	  {
	    printf("recv() failed\n");
	    close(s);
	    return;
	  }
	memcpy(buf+off, replyMessage, numBytesRecv);    
	off+=numBytesRecv;
	printf("%ld\n", numBytesRecv);
	if(off>=data_length+2 && off != 0)
	  {
	    break;
	  }
      }
    while (numBytesRecv > 0);
    close(s);

    dns_buf = buf;

    dns = (struct DNS_HEADER*) &buf;
    printf("\n n: %d, offset: %d, datalen: %d", n, off, ntohs(dns->len));


    int i , j , stop;
    unsigned char *reader;
    struct sockaddr_in a = {0};

    struct RES_RECORD *answers = NULL;
    struct RES_RECORD *auth = NULL;
    struct RES_RECORD *addit = NULL; //the replies from the DNS server

    
    printf("\nThe response contains : ");
    printf("\n %d Questions.",ntohs(dns->q_count));
    printf("\n %d Answers.",ntohs(dns->ans_count));
    printf("\n %d Authoritative Servers.",ntohs(dns->auth_count));
    printf("\n %d Additional records.\n\n",ntohs(dns->add_count));

    answers = (struct RES_RECORD*)calloc(ntohs(dns->ans_count), sizeof(struct RES_RECORD));
    auth = (struct RES_RECORD*)calloc(ntohs(dns->auth_count), sizeof(struct RES_RECORD));
    addit = (struct RES_RECORD*)calloc(ntohs(dns->add_count), sizeof(struct RES_RECORD));

    //move ahead of the dns header and the query field
    reader = &buf[sizeof(struct DNS_HEADER) + (strlen((const char*)qname)+1) + sizeof(struct QUESTION)];
    
    //Start reading answers
    stop=0;

    for(i=0;i<ntohs(dns->ans_count);i++)
      {
	/*
	printf("name: %02x %02x\n", *(reader), *(reader+1));
	printf("type: %02x %02x\n", *(reader+2), *(reader+3));
	printf("class: %02x %02x\n", *(reader+4), *(reader+5));
	printf("ttl: %02x %02x %02x %02x\n", *(reader+6), *(reader+7), *(reader+8), *(reader+9));
	printf("len: %02x %02x\n", *(reader+10), *(reader+11));
	*/
          unsigned char na[1024] = {0};
          unsigned int name_offset = readSOA(reader, buf+2, na) + 1;
          printf("%s", na);
          //reader += name_offset -2;
	unsigned short class = ((*(reader+2 + name_offset) << 8) &0xFF00) | (*(reader+3 + name_offset) & 0xFF);
	unsigned short type = ((*(reader+name_offset) << 8) &0xFF00) | (*(reader+1 +name_offset) & 0xFF);
	unsigned short name_size = ((*(reader+8+name_offset) << 8) &0xFF00) | (*(reader+9+name_offset) & 0xFF);
	answers[i].resource=(struct R_DATA*)(reader);

	reader+=10 + name_offset;
	
	printf("name_s: %d, ttl: %d, class: %d, type: %d\n", name_size, ntohs(answers[i].resource->ttl), class, type);
	answers[i].rdata = (unsigned char*)malloc(name_size);
	ReadName(reader,buf,&stop,answers[i].rdata, name_size, type, buf + 2);
	reader+=name_size;
      }

    for(i=0; i < ntohs(dns->ans_count); ++i)
    {
        free(answers[i].rdata);
    }
    free(answers);
    return;
}

/*
 * 
 * */

void ReadName(unsigned char* reader,unsigned char* buffer,int* count, unsigned char* name, size_t data_len, unsigned short type, unsigned char* dns)
{
  switch(type)
    {      
    case T_A:
      parse_ip(reader);
      break;
    case T_NS:
      parse_ns(reader, dns);
      break;
    case T_CNAME:
      break;
    case T_SOA:
      parse_soa(reader, (unsigned short)data_len, dns);
      break;
    case T_PTR:
        parse_ptr(reader, (unsigned short)data_len, dns);
      break;
    case T_HINFO:
      parse_hinfo(reader, (unsigned short)data_len);
      break;
    case T_MX:
        parse_mx(reader, (unsigned short)data_len, dns);
        break;
    case T_TXT:
        parse_txt(reader, data_len);
        break;
    case T_RP:
    case T_AFSDB:
    case T_AAAA:
    case T_LOC:
    case T_SRV:
    case T_NAPTR:
    case T_RRSIG:
      parse_rrsig(reader, (unsigned short) data_len);
      break;
    case T_NSEC:
    case T_DNSKEY:
      break;
    }
}

void parse_ip(unsigned char* data)
{
  printf(" %d.%d.%d.%d \n\n", (int)*data, (int)*(data+1), (int)*(data+2), (int)*(data+3));
}

void parse_ns(unsigned char* data, unsigned char* dns)
{
  printf("NS: ");
  getName(data, dns);
    printf("\n\n");
}

void parse_ptr(unsigned char* data, unsigned short data_len, unsigned char* dns)
{
  printf("PTR: ");
  getName(data, dns);// These types all consist of a single domain name
    printf("\n\n");
}

void parse_soa(unsigned char* data, unsigned short data_len, unsigned char* dns)
{
    printf("SOA: ");

    // TODO
    unsigned char name[1024] = {0};
    unsigned int p = 0;

    p = readSOA(data, dns, name);
    printf(" %s ", name);
    memset(name, 0, 1024);
    p = readSOA(data+p+1, dns, name);
    printf("%s ", name);

    unsigned int serial_no = (unsigned int)data+p;
    unsigned int refresh = 0;
    unsigned int retry = 0;
    unsigned int expire = 0;
    unsigned int min_ttl = 0;
    printf("\n\n");
}

void parse_hinfo(unsigned char* data, unsigned short data_len)
{
  int len_cpu = (int)*data;
  int len_os = (int)*(data + len_cpu + 1);

  printf("cpu len: %d os len: %d", len_cpu, len_os);
    printf("\n\n");
}

void parse_mx(unsigned char* data, unsigned short data_len, unsigned char* dns_packet_resp)
{
    unsigned short preference = ((*(data) << 8) &0xFF00) | (*(data+1) & 0xFF);
    getName(data+2, dns_packet_resp);
    printf("\n\n");
}

void parse_txt(unsigned char* data, unsigned short data_len)
{
    unsigned int i = 0;
    unsigned char *txt= NULL;

    txt = (unsigned char*)malloc(data_len);
    data++;
    while(i<data_len-1)
    {
        txt[i++]=*data++;
    }

    printf("%s", txt);
    printf("\n\n");
    free(txt);
}

void parse_rrsig(unsigned char* data, unsigned short data_len)
{
    unsigned short type = ((*(data) << 8) &0xFF00) | (*(data+1) & 0xFF);
    unsigned char algorithm = *data + 2;
    unsigned char labels = *data + 3;
    unsigned int ttl = 0;
    unsigned int timestamp_exp = 0;
    unsigned int timestamp_inc = 0;
    unsigned short key_tag = type = ((*(data + 16) << 8) &0xFF00) | (*(data+17) & 0xFF);
    unsigned char name[1024] = {0};
    unsigned int p = 0;
    while(*data != 0x00)
    {
        name[p++]=*data++;
    }

    unsigned char signature[1024] = {0};
    printf("\n\n");
}
 
int getName(unsigned char* data, unsigned char* dns_packet_resp)
{
    unsigned char name[1024] = {0};
    unsigned int i = 0, j = 0, p = 0;

    p = readString(data, dns_packet_resp, name);
    //now convert 3www6google3com0 to www.google.com
    for(i=0;i<(int)strlen((const char*)name);i++)
    {
        p=name[i];
        for(j=0;j<(int)p;j++)
        {
            name[i]=name[i+1];
            i=i+1;
        }
        name[i]='.';
    }
    name[i-1]='\0'; //remove the last dot

    printf(" %s ", name);
    return strlen(name);
}

unsigned int readString(unsigned char* data, unsigned char* dns_packet_resp, unsigned char* name)
{
    unsigned int p = 0;
    printf("name data: %02x %02x  ", *data, *(data+1));
  
    while(*data != 0x00)
    {
        if((uint8_t)(*data) >= 192)
        {
            unsigned short name_offset = (((*(data) << 8) &0xFF00) | (*(data+1) & 0xFF)) - 49152;
            printf("from pointer: %02x %02x offset: %d ", *data, *(data+1), name_offset);
            p+=readString(dns_packet_resp + name_offset, dns_packet_resp, name+p);
            break;
        }

        name[p++]=*data++;
    }
    name[p] = '\0';
    return p;
}

unsigned int readSOA(unsigned char* data, unsigned char* dns_packet_resp, unsigned char* name)
{
    unsigned int p = 0, all = 0, i = 0, j = 0;
    printf("name data: %02x %02x  ", *data, *(data+1));

    while(*data != 0x00)
    {
        if((uint8_t)(*data) >= 192)
        {
            unsigned short name_offset = (((*(data) << 8) &0xFF00) | (*(data+1) & 0xFF)) - 49152;
            printf("from pointer: %02x %02x offset: %d ", *data, *(data+1), name_offset);
            all+=readString(dns_packet_resp + name_offset, dns_packet_resp, name+p);
            p+=1;
            break;
        }
        ++all;
        name[p++]=*data++;
    }
    name[all] = '\0';

    //now convert 3www6google3com0 to www.google.com
    for(i=0;i<(int)strlen((const char*)name);i++)
    {
        all=name[i];
        for(j=0;j<(int)all;j++)
        {
            name[i]=name[i+1];
            i=i+1;
        }
        name[i]='.';
    }
//    name[i-1]='\0'; //remove the last dot

    return p;
}


/*
 * This will convert www.google.com to 3www6google3com 
 * got it :)
 * */
void ChangetoDnsNameFormat(unsigned char* dns,unsigned char* host) 
{
    int lock = 0 , i;
    strcat((char*)host,".");
     
    for(i = 0 ; i < strlen((char*)host) ; i++) 
    {
        if(host[i]=='.') 
        {
            *dns++ = i-lock;
            for(;lock<i;lock++) 
            {
                *dns++=host[lock];
            }
            lock++; //or lock=i+1;
        }
    }
    *dns++='\0';
}

int hostname_to_ip(const char *hostname , char *ip)
{
  int sockfd;
  struct addrinfo hints, *servinfo, *p;
  struct sockaddr_in *h;
  int rv;

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC; // use AF_INET6 to force IPv6
  hints.ai_socktype = SOCK_STREAM;

  if ( (rv = getaddrinfo( hostname , NULL , NULL , &servinfo)) != 0)
    {
      fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
      return 1;
    }

  // loop through all the results and connect to the first we can
  for(p = servinfo; p != NULL; p = p->ai_next)
    {
      h = (struct sockaddr_in *) p->ai_addr;
      strcpy(ip , inet_ntoa( h->sin_addr ) );
      if(strcmp(ip, "0.0.0.0") != 0)
	{
	  freeaddrinfo(servinfo);
	  return 0;
	}
      printf("IP: %s\n", ip);
    }

  freeaddrinfo(servinfo); // all done with this structure
  return 0;
}
