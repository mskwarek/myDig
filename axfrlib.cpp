//
// Created by marcin on 27.07.16.
//

#include "Scanner/axfrLookup.h"
#include "Scanner/AxfrDatabase.hpp"
#include "Scanner/InputReader.h"

extern "C"
{
  #include "digUtils/dig_parser.h"
  axfrLookup* axfrLookup_new()
  {
    return new axfrLookup();
  }
  
  void axfrLookup_performLookup(axfrLookup* lookup, const char* domain, const char* ns)
  {
    lookup->performLookup(domain, ns);
  }

  std::vector<ScanningResult*>* axfrLookup_getResult(axfrLookup* lookup)
  {
    return lookup->get_domains();
  }
  void print_data(std::vector<ScanningResult*>* data)
  {
    if(data == NULL)
      return;
    std::cout<<data->size()<<std::endl;
    for(int i = 0; i<data->size(); ++i)
      std::cout<<"costam "<<data->size()<<" "<<i<<std::endl;
  }

  void axfrLookup_destroy(axfrLookup* lookup)
  {
    delete lookup;
  }
}
