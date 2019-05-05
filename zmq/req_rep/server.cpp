#include <zmq.hpp>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <unistd.h>


int main(){

  zmq::context_t context(1);
  zmq::socket_t socket(context, ZMQ_REP);
  socket.bind("tcp://*:5555");



  while(true){
    zmq::message_t request;

    socket.recv(&request);
    std::cout << "Received: " << static_cast<char*>(request.data()) << std::endl;


    zmq::message_t reply(256);
    memcpy (reply.data(), request.data(), request.size());

    std::cout << "Returning: " << static_cast<char*>(reply.data()) << std::endl;
    socket.send(reply); //message disapears post send
    std::cout << "Returned: " << static_cast<char*>(reply.data()) << std::endl;



  }



  return EXIT_SUCCESS;
}
