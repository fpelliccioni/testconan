// http://docs.conan.io/en/latest/examples/zmq_protobuf.html

#include <string>
#include <iostream>

#include <boost/regex.hpp>

#include <google/protobuf/text_format.h>

#include "zmq.hpp"
#include "message.pb.h"

int main () {
    boost::regex const e("(\\r\\n\\r\\n|\\n\\r\\n|\\r\\n\\n|\\n\\n)");


    zmq::context_t context (1); //  Prepare our context and socket
    zmq::socket_t socket(context, ZMQ_PAIR);
    socket.bind ("tcp://*:5555");

    while (true) {
        zmq::message_t request;
        socket.recv (&request); //  Wait for next request from client
        std::cout << "Received" << std::endl;
        tutorial::Person person;
        std::string msg_str(static_cast<char*>(request.data()), request.size());
        person.ParseFromString(msg_str);
        std::string text_str;
        google::protobuf::TextFormat::PrintToString(person, &text_str);
        std::cout << text_str << std::endl;
    }
    return 0;
}
