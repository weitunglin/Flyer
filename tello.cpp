#include "tello.h"

Tello::Tello(int port) :  respPort(8889) {
  Tello::reqAddr = "192.168.10.1";
  Tello::respPort = port;
  Tello::videoPort = 6038;
}

void Tello::Start() {
  service = boost::make_shared<boost::asio::io_service>();
  socket  = boost::make_shared<boost::asio::ip::udp::socket>(*service);
  endpoint = boost::make_shared<boost::asio::ip::udp::endpoint>(boost::asio::ip::address::from_string("192.168.10.1"), 8889);
  Tello::socket->open(boost::asio::ip::udp::v4());
  
  std::string resp = Tello::Command("command");
  std::cout << "Tello init ......" << resp << respPort << std::endl;
}

bool Tello::Land() {
  std::cout << "landing" << std::endl;
  std::string resp = Tello::Command("land");
  if(resp != "OK") { return false; }
  else { return true; }
}

bool Tello::Takeoff() {
  std::cout << "taking off" << std::endl;
  std::string resp = Tello::Command("takeoff");
  if(resp != "OK") { return false; }
  else { return true; }
}

std::string Tello::GetFlightTime() {
  std::string resp = Tello::Command("time?");
  return resp;
}
