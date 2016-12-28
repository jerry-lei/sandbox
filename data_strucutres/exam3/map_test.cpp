#include <iostream>
#include <cstdlib>
#include <map>

int main(){
  std::map<int,std::string> map_test;
  map_test.insert(std::make_pair(1,std::string("string1")));
  map_test.insert(std::make_pair(2,std::string("string2")));
  map_test.insert(std::make_pair(3,std::string("string3")));
  std::map<int,std::string>::iterator it = map_test.find(1);
  std::cout << it->second <<  " = " << (*it).second << std::endl;
  it++;
  std::cout << it->second <<  " = " << (*it).second << std::endl;
  it++;
  std::cout << it->second <<  " = " << (*it).second << std::endl;
  it++;
  std::cout << it->second <<  " = " << (*it).second << std::endl;
  it--;
  std::cout << it->second <<  " = " << (*it).second << std::endl;
  it--;
  std::cout << it->second <<  " = " << (*it).second << std::endl;
  it--;
  std::cout << it->second <<  " = " << (*it).second << std::endl;

  return 0;
}
