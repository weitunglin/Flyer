#ifndef _TELLO_H
#define _TELLO_
#include <boost/asio.hpp>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

using boost::asio::ip::udp;

class Tello {
  private: 
    std::string name;
    std::string reqAddr;
    std::string respPort;
    std::string videoPort;
    int seq;
    int throttle;
    bool bouncing;
    float rx, ry, lx, ly;
    boost::asio::io_service io_service;
    udp::socket socket(io_service);
    udp::endpoint endpoint;
    // cmdConn;
    // videoConn;

  public: 
    void Tello::Tello(std::string port);
    void Tello::Start(void);
}