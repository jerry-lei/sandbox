#include <zmq.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main () {

  //  Prepare our context and publisher
  zmq::context_t context (1);
  zmq::socket_t publisher (context, ZMQ_PUB);
  publisher.bind("tcp://*:5556");

  int counter = 0;

  while (true) {

    int msg_id = counter % 1000;

    int msg_num = counter / 1000;


    //  Send message to all subscribers
    zmq::message_t message(20);
    snprintf ((char *) message.data(), 20 ,
    "%03d %s %d", msg_id, "message", msg_num);
    publisher.send(message);

    counter += 1;

  }
  return 0;
}
