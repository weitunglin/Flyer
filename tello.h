#ifndef _TELLO_H
#define _TELLO_H
#endif
#include <boost/asio.hpp>
#include <boost/make_shared.hpp>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

using boost::asio::ip::udp;

class Tello {

  private: 
    std::string name;
    std::string reqAddr;
    int videoPort;
    int respPort;
    int seq;
    int throttle;
    bool bouncing;
    float rx, ry, lx, ly;

    boost::shared_ptr<boost::asio::ip::udp::socket> socket;
    boost::shared_ptr<boost::asio::io_service> service;
    boost::shared_ptr<boost::asio::ip::udp::endpoint> endpoint;

    std::string Command(std::string send_msg) {
      udp::endpoint send_endpoint;
      udp::endpoint recv_endpoint = boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(Tello::reqAddr), respPort);
      std::string recv_msg;
      boost::system::error_code err;

      socket->send_to(boost::asio::buffer(send_msg.c_str(), send_msg.size()), recv_endpoint, 0, err);
      socket->receive_from(boost::asio::buffer(recv_msg), send_endpoint);
      std::cout << err.message() << std::endl;
      return recv_msg;
    }
    // cmdConn;
    // videoConn;

  public: 
    explicit Tello(int port);
    void Start(void);
    bool Land(void);
    bool Takeoff(void);
    std::string GetFlightTime(void);

};