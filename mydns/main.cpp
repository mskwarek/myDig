#include <iostream>
#include <fstream>

extern "C"{
#include"dns.h"
}

#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <stdlib.h>
#include <algorithm>

char* getCmdOption(char ** begin, char ** end, const std::string & option)
{
    char ** itr = std::find(begin, end, option);
    if (itr != end && ++itr != end)
    {
        return *itr;
    }
    return 0;
}

bool cmdOptionExists(char** begin, char** end, const std::string& option)
{
    return std::find(begin, end, option) != end;
}

template<typename Out>
void split(const std::string &s, char delim, Out result) {
  std::stringstream ss;
  ss.str(s);
  std::string item;
  while (std::getline(ss, item, delim)) {
    *(result++) = item;
  }
}

std::vector<std::string> split(const std::string &s, char delim) {
  std::vector<std::string> elems;
  split(s, delim, std::back_inserter(elems));
  return elems;
}

int getQueryTypeIdByName(const char* query_type)
{
    return 1;
}

int getTimeout(const char* timeout)
{
    if(timeout)
        return atoi(timeout);
    else
        return 5;
}

dns_transport_type getTransportProtocolIdByName(const char* protocol_name)
{
    if(!protocol_name)
        return TRANSPORT_TYPE_TCP;
    else if(0 == strcmp(protocol_name, "UDP"))
        return TRANSPORT_TYPE_UDP;
    else
        return TRANSPORT_TYPE_TCP;
}

void printHelpPrompt()
{
    std::cout << "Scaner usage:"<<std::endl
            << "\t-o\toutput folder [mandatory]" << std::endl
            << "\t-t\ttimeout in ms [default 5s]" << std::endl
            << "\t-d\tdomain to scan [optional; scan only one domain]" << std::endl
            << "\t-n\tNS IP address [optional; needed by one-domain-scan mode]" << std::endl
            << "\t-q\tQuery type [A, AAAA, NS, TXT, AXFR, (...); default AXFR]" << std::endl
            << "\t-p\tTransport protocol used in scanner [default TCP]" << std::endl
            << "\t-l\tlist with records to scan in format domain_address|ns_ip [optional]" << std::endl;
}

int main(int argc, char* argv[]){
  std::string line;
  int i=0;

  static const char* output_arg = "-o";
  static const char* timeout_arg = "-t";
  static const char* domain_arg = "-d";
  static const char* ns_ip_arg = "-n";
  static const char* query_type_arg = "-q";
  static const char* transport_protocol_arg = "-p";
  static const char* input_list_arg = "-l";

  char *output_dir = getCmdOption(argv, argv + argc, output_arg);
  char *timeout = getCmdOption(argv, argv + argc, timeout_arg);
  char *domain = getCmdOption(argv, argv + argc, domain_arg);
  char *nameserver_ip = getCmdOption(argv, argv + argc, ns_ip_arg);
  char *query_type = getCmdOption(argv, argv + argc, query_type_arg);
  char *transport_protocol_name = getCmdOption(argv, argv + argc, transport_protocol_arg);
  char *path_to_input_list = getCmdOption(argv, argv + argc, input_list_arg);

  if(cmdOptionExists(argv, argv + argc, "-h")
        || !cmdOptionExists(argv, argv + argc, output_arg)
        || (!cmdOptionExists(argv, argv + argc, input_list_arg)
                && (!cmdOptionExists(argv, argv + argc, domain_arg) && !cmdOptionExists(argv, argv + argc, ns_ip_arg))))
  {
      printHelpPrompt();
      return 0;
  }

  if(cmdOptionExists(argv, argv + argc, domain_arg) && cmdOptionExists(argv, argv + argc, ns_ip_arg))
  {
      if(strlen(domain) > 0 && strlen(nameserver_ip) > 0)
      {
    // std::cout<<"Main args: "<<argv[1]<<" " <<argv[2]<<std::endl;
        ngethostbyname(domain, nameserver_ip, output_dir,
            getQueryTypeIdByName(query_type), getTimeout(timeout),
            getTransportProtocolIdByName(transport_protocol_name));
    }
  }
  else
  {
      std::string filename = path_to_input_list;
      std::ifstream inputFile(filename.c_str());
      while(std::getline(inputFile, line)){
          std::cout<<i++<<std::endl;
          std::vector<std::string> x = split(line, '|');
          ngethostbyname(x[0].c_str(), x[1].c_str(), output_dir,
                    getQueryTypeIdByName(query_type), getTimeout(timeout),
                    getTransportProtocolIdByName(transport_protocol_name));
      }
      inputFile.close();
  }
  return 0;
}
