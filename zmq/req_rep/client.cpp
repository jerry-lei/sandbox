#include <zmq.hpp>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <unistd.h>


int main(){

  zmq::context_t context(1);
  zmq::socket_t socket(context, ZMQ_REQ);

  socket.connect("tcp://localhost:5555");

  int counter = 0;

  while(true){
    zmq::message_t request(40);


    snprintf((char *) request.data(), 40,
            "%s %04d", "Message number: ", counter);

    std::cout << "Requested: " << static_cast<char*>(request.data()) << std::endl;

    socket.send(request);


    zmq::message_t reply;
    socket.recv(&reply);

    std::cout << "Returned: " << static_cast<char*>(reply.data()) << std::endl;


    counter ++;

    sleep(1);


  }



  return EXIT_SUCCESS;
}
