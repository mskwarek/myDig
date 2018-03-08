#include <string.h>
#include <sys/socket.h>    //you know what this is for
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h> //fcntl
#include <errno.h>
#include "dns.h"
#include "utils.h"
#include "dns_received_packet_reader.h"

static unsigned short dns_id = 0;//0x1122;/**< DNS query id  */
static unsigned char*  dns_buf;



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

    unsigned short q_count; // number of question entries
    unsigned short ans_count; // number of answer entries
    unsigned short auth_count; // number of authority entries
    unsigned short add_count; // number of resource entries
};
typedef struct DNS_HEADER DNS_H_TCP;

struct DNS_HEADER_UDP
{
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

    unsigned short q_count; // number of question entries
    unsigned short ans_count; // number of answer entries
    unsigned short auth_count; // number of authority entries
    unsigned short add_count; // number of resource entries
};
typedef struct DNS_HEADER_UDP DNS_H_UDP;


struct QUESTION
{
    unsigned short qtype;
    unsigned short qclass;
};

dns_result ngethostbyname(const char *que , const char *server, const char *dst_log_path, int query_type,
    int to, dns_transport_type transport_type)
{
    int s = -1;

    enum
    {
        BUFSIZE=65536,
        HOSTSIZE = 128
    };
    unsigned char buf[BUFSIZE] = {0};
    struct sockaddr_in dest = {0};
    int answers_cnt = 0;
    int dns_header_size = 0;

    printf("%s %s\n", que, server);

    unsigned char *qname = NULL;
    struct QUESTION *qinfo = NULL;
    char host[HOSTSIZE] = {0};
      //Set the DNS structure to standard queries

    snprintf(host, HOSTSIZE, "%s", que);
    printf("\nResolving %s\n" , host);
    dns_id = getpid();


    if(TRANSPORT_TYPE_UDP == transport_type)
    {
        DNS_H_UDP *dns = NULL;
        dns = (struct DNS_HEADER_UDP *)&buf;

        dns->id = (unsigned short) htons(dns_id);
        dns->qr = 0; //This is a query
        dns->opcode = 0; //This is a standard query
        dns->aa = 0; //Not Authoritative
        dns->tc = 0; //This message is not truncated
        dns->rd = 1; //Recursion Desired
        dns->ra = 0; //Recursion not available! hey we dont have it (lol)
        dns->z = 0;
        dns->ad = 0;
        dns->cd = 0;
        dns->rcode = 0;
        dns->q_count = htons(1); //we have only 1 question
        dns->ans_count = 0;
        dns->auth_count = 0;
        dns->add_count = 0;// htons(1);

        //point to the query portion
        qname =(unsigned char*)&buf[sizeof(struct DNS_HEADER_UDP)];
        ChangetoDnsNameFormat(qname , (unsigned char*)host);
        qinfo =(struct QUESTION*)&buf[sizeof(struct DNS_HEADER_UDP) + (strlen((const char*)qname) + 1)]; //fill it
        qinfo->qtype = htons( query_type ); //type of the query , A , MX , CNAME , NS etc
        qinfo->qclass = htons(1);

        int i = 0;
        s = socket(AF_INET , SOCK_DGRAM , IPPROTO_UDP); //UDP packet for DNS queries
        dest.sin_family = AF_INET;
        dest.sin_port = htons(53);
        dest.sin_addr.s_addr = inet_addr(server);

        struct timeval tv;
        tv.tv_sec = to;
        int setopterr = setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char*)&tv, sizeof(tv));
        if (setopterr < 0) {
            //perror("Error");
            //printf("err: %d\n", setopterr);
            printf("setsockopt failed");
            return DNS_RESULT_ERR;
        }

        int len = (unsigned int)sizeof(struct DNS_HEADER_UDP) + (strlen((const char*)qname)+1) + sizeof(struct QUESTION);

        printf("\nSending Packet...");
        if( 0 > sendto(s,(char*)buf,len,0,(struct sockaddr*)&dest,sizeof(dest)) )
        {
            printf("sendto failed");
            return DNS_RESULT_ERR;
        }
        printf("Done");

        //Receive the answer
        i = sizeof dest;
        printf("\nReceiving answer...");
        if(recvfrom (s,(char*)buf , 65536 , 0 , (struct sockaddr*)&dest , (socklen_t*)&i ) < 0)
        {
            //perror("recvfrom failed");
            printf("recvfrom failed");
            return DNS_RESULT_ERR;
        }
        printf("Done");

        dns_buf = buf;
        dns = (struct DNS_HEADER_UDP*) &buf;

        answers_cnt = ntohs(dns->ans_count);
        dns_header_size = sizeof(struct DNS_HEADER_UDP);
    }
    else
    {
        DNS_H_TCP *dns = NULL;

        dns = (struct DNS_HEADER *)&buf;
        dns->id = (unsigned short) htons(dns_id);
        dns->qr = 0; //This is a query
        dns->opcode = 0; //This is a standard query
        dns->aa = 0; //Not Authoritative
        dns->tc = 0; //This message is not truncated
        dns->rd = 1; //Recursion Desired
        dns->ra = 0; //Recursion not available! hey we dont have it (lol)
        dns->z = 0;
        dns->ad = 0;
        dns->cd = 0;
        dns->rcode = 0;
        dns->q_count = htons(1); //we have only 1 question
        dns->ans_count = 0;
        dns->auth_count = 0;
        dns->add_count = 0;// htons(1);

        //point to the query portion
        qname =(unsigned char*)&buf[sizeof(struct DNS_HEADER)];
        ChangetoDnsNameFormat(qname , (unsigned char*)host);
        qinfo =(struct QUESTION*)&buf[sizeof(struct DNS_HEADER) + (strlen((const char*)qname) + 1)]; //fill it
        qinfo->qtype = htons( query_type ); //type of the query , A , MX , CNAME , NS etc
        qinfo->qclass = htons(1);
        dns->len = htons((unsigned int)sizeof(struct DNS_HEADER)+(strlen((const char*)qname)+1) + sizeof(struct QUESTION)-2);


        s = socket(AF_INET , SOCK_STREAM , IPPROTO_TCP);
        if(s<0)
        {
            printf("Conn refused");
            return DNS_RESULT_ERR;
        }
        struct timeval timeout;
        timeout.tv_sec = to;
        timeout.tv_usec = 0;

        if (setsockopt (s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout,
                sizeof(timeout)) < 0) {
            printf("setsockopt failed\n");
        }

        // printf("Nameserver IP: %s\n", server);
        dest.sin_addr.s_addr = inet_addr(server);
        dest.sin_family = AF_INET;
        dest.sin_port = htons(53);

        long arg = 0;
        int res = 0;
        fd_set myset = {{0}};
        int valopt = 0;

        socklen_t lon = {0};

        if( (arg = fcntl(s, F_GETFL, NULL)) < 0) {
            fprintf(stderr, "Error fcntl(..., F_GETFL) (%s)\n", strerror(errno));
            return DNS_RESULT_ERR;
            // exit(0);
        }
        arg |= O_NONBLOCK;
        if( fcntl(s, F_SETFL, arg) < 0) {
            fprintf(stderr, "Error fcntl(..., F_SETFL) (%s)\n", strerror(errno));
            return DNS_RESULT_ERR;
        }
        // Trying to connect with timeout
        res = connect(s, (struct sockaddr *)&dest, sizeof(dest));
        if (res < 0) {
            if (errno == EINPROGRESS) {
                // fprintf(stderr, "EINPROGRESS in connect() - selecting\n");
                do {
                    timeout.tv_sec = to;
                    timeout.tv_usec = 0;
                    FD_ZERO(&myset);
                    FD_SET(s, &myset);
                    res = select(s+1, NULL, &myset, NULL, &timeout);
                    if (res < 0 && errno != EINTR) {
                        fprintf(stderr, "Error connecting %d - %s\n", errno, strerror(errno));
                        close(s);
                        return DNS_RESULT_ERR;
                    }
                    else if (res > 0) {
                        // Socket selected for write
                        lon = sizeof(int);
                        if (getsockopt(s, SOL_SOCKET, SO_ERROR, (void*)(&valopt), &lon) < 0) {
                            fprintf(stderr, "Error in getsockopt() %d - %s\n", errno, strerror(errno));
                            close(s);
                            return DNS_RESULT_ERR;
                        }
                        // Check the value returned...
                        if (valopt) {
                            fprintf(stderr, "Error in delayed connection() %d - %s\n", valopt, strerror(valopt)
                            );
                            close(s);
                            return DNS_RESULT_ERR;
                        }
                        break;
                    }
                    else {
                        fprintf(stderr, "Timeout in select() - Cancelling!\n");
                        close(s);
                        return DNS_RESULT_ERR;
                    }
                } while (1);
            }
            else {
                fprintf(stderr, "Error connecting %d - %s\n", errno, strerror(errno));
                close(s);
                return DNS_RESULT_ERR;
            }
        }
        // Set to blocking mode again...
        if( (arg = fcntl(s, F_GETFL, NULL)) < 0) {
            fprintf(stderr, "Error fcntl(..., F_GETFL) (%s)\n", strerror(errno));
            close(s);
            return DNS_RESULT_ERR;
        }
        arg &= (~O_NONBLOCK);
        if( fcntl(s, F_SETFL, arg) < 0) {
            fprintf(stderr, "Error fcntl(..., F_SETFL) (%s)\n", strerror(errno));
            close(s);
            return DNS_RESULT_ERR;
        }


        if (connect(s,(struct sockaddr *) &dest, sizeof(dest)) < 0)
        {
            printf("ERROR connecting\n");
            close(s);
            return DNS_RESULT_ERR;
        }


        int len = (unsigned int)sizeof(struct DNS_HEADER) + (strlen((const char*)qname)+1) + sizeof(struct QUESTION);
        int n = write(s, (char*)buf, len);
        if (n < 0) {
            perror("ERROR writing to socket");
        }
        bzero(buf, BUFSIZE);

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
    	    return DNS_RESULT_ERR;
    	  }
    	memcpy(buf+off, replyMessage, numBytesRecv);
    	off+=numBytesRecv;
    	// printf("%ld\n", numBytesRecv);
    	if(off>=data_length+2 && off != 0)
    	  {
    	    break;
    	  }
          }
        while (numBytesRecv > 0);
        close(s);
        dns_buf = buf;

        dns = (struct DNS_HEADER*) &buf;
        answers_cnt = ntohs(dns->ans_count);
        dns_header_size = sizeof(struct DNS_HEADER);
    }

    //printf("\ndatalen: %d\n", ntohs(dns->len));


    int i =0;
    unsigned char *reader = NULL;

    enum { FILENAME_SIZE = 512 };

    char filename[FILENAME_SIZE] = {0};
    snprintf(filename, FILENAME_SIZE, "%s/%s_%s.axfr", dst_log_path, que, server);
    //printf(" %s\n", filename);

    if(answers_cnt <= 0)
    {
        //printf("answers: %d", answers_cnt);
	    return DNS_RESULT_ERR;
    }

    if(TRANSPORT_TYPE_TCP == transport_type)
    {
        unsigned short dnsIdFromPacket = ((*(buf+2) << 8) &0xFF00) | (*(buf+3) & 0xFF);

        if(dns_id != dnsIdFromPacket)
        {
            printf("dnsId from resp does not match");
            return DNS_RESULT_ERR;
        }
    }
    FILE *f = fopen(filename, "w");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        return DNS_RESULT_ERR;
    }
    //
    // printf("\nThe response contains : z15AiYOM71wL8wTF");
    // printf("\n %d Answers.", answers_cnt);
    //

    struct RES_RECORD *answers = NULL;
    answers = (struct RES_RECORD*)calloc(answers_cnt, sizeof(struct RES_RECORD));
    if(answers == NULL)
    {
        fclose(f);
        return DNS_RESULT_NO_MEMORY;
    }

    //move ahead of the dns header and the query field
    reader = &buf[dns_header_size + (strlen((const char*)qname)+1) + sizeof(struct QUESTION)];

    readAnswers(transport_type, reader, answers, buf, f, answers_cnt);

    fclose(f);
    for(i=0; i < answers_cnt; ++i)
    {
        if(answers[i].rdata!=NULL)
            free(answers[i].rdata);
    }
    if(answers!=NULL)
        free(answers);
    return DNS_RESULT_OK;
}
