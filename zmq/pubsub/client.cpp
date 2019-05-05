//
//  Weather update client in C++
//  Connects SUB socket to tcp://localhost:5556
//  Collects weather updates and finds avg temp in zipcode
//
//  Olivier Chamoux <olivier.chamoux@fr.thalesgroup.com>
//
#include <zmq.hpp>
#include <iostream>
#include <sstream>

int main (int argc, char *argv[])
{
  zmq::context_t context (1);

  //  Socket to talk to server
  std::cout << "Collecting updates from server...\n" << std::endl;
  zmq::socket_t subscriber (context, ZMQ_SUB);
  subscriber.connect("tcp://localhost:5556");

  const char *filter = (argc > 1)? argv [1]: "001";
  subscriber.setsockopt(ZMQ_SUBSCRIBE, filter, strlen (filter));

  while(true){
    zmq::message_t ping;
    subscriber.recv(&ping);

    std::cout << "Received msg: " << static_cast<char*>(ping.data())ç << std::endl;

  }

  return 0;
}
