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
    std::string reqAddr;
    int videoPort;
    int respPort;
    int mv_dis;
    int mv_deg;

    boost::shared_ptr<boost::asio::ip::udp::socket> socket;
    boost::shared_ptr<boost::asio::io_service> service;
    boost::shared_ptr<boost::asio::ip::udp::endpoint> endpoint;

    std::string Command(std::string send_msg) {
      std::cout << send_msg << "  ";
      udp::endpoint send_endpoint;
      udp::endpoint recv_endpoint = boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(Tello::reqAddr), Tello::respPort);
      char recv_msg[128];
      boost::system::error_code err;

      socket->send_to(boost::asio::buffer(send_msg.c_str(), send_msg.size()), recv_endpoint);
      socket->receive_from(boost::asio::buffer(recv_msg, 128), send_endpoint);
      
      std::cout << std::string(recv_msg) << std::endl;
      return std::string(recv_msg);
    }

  public:
    Tello(void);
    Tello(std::string Addr, int port);
    void Start(void);
    bool Land(void);
    bool Takeoff(void);
    bool Up(int dis);
    bool Down(int dis);
    bool Right(int dis);
    bool Left(int dis);
    bool Forward(int dis);
    bool Back(int dis);
    bool Cw(int deg);
    bool Ccw(int deg);
    std::string GetBattery(void);
    std::string GetSpeed(void);
    std::string GetFlightTime(void);

};