#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

#define TELLO_IPADDRESS "192.168.10.1"
#define TELLO_UDPPORT 8889
 
int main(int argc, char ** argv) {
  std::string send_msg = "";

  boost::asio::io_service io_service;
  udp::socket socket(io_service);
  udp::endpoint remote_endpoint = udp::endpoint(boost::asio::ip::address::from_string(TELLO_IPADDRESS), TELLO_UDPPORT);
  socket.open(udp::v4());

  boost::system::error_code err;
  std::size_t sent = socket.send_to(boost::asio::buffer(send_msg), remote_endpoint, 0, err);
  socket.close();

  std::cout << "Reply : " << sent << std::endl;
}