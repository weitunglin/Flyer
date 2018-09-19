#include "tello.h"

void Tello::Tello(std::string port) {
  Tello::reqAddr = "192.168.10.1:8889";
  Tello::respPort = port;
  Tello::videoPort = "6038";
}

void Tello::Start(void) {
  Tello::endpoint = udp::endpoint(boost::asio::ip::address::from_string(Tello::reqAddr), Tello::respPort);
  socket.open(udp::v4());
}