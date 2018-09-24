#include "tello.h"

Tello::Tello(void) {
  Tello::reqAddr = "192.168.10.1";
  Tello::respPort = 8889;
  Tello::videoPort = 6038;
}

Tello::Tello(std::string Addr, int port) {
  Tello::reqAddr = reqAddr;
  Tello::respPort = port;
  Tello::videoPort = 6038;
}

void Tello::Start(void) {
  service = boost::make_shared<boost::asio::io_service>();
  socket  = boost::make_shared<boost::asio::ip::udp::socket>(*service);
  endpoint = boost::make_shared<boost::asio::ip::udp::endpoint>(boost::asio::ip::address::from_string(&Tello::reqAddr), Tello::respPort);
  Tello::socket->open(boost::asio::ip::udp::v4());
  
  std::cout << "Tello init ......" << " UDPPort :" << respPort << std::endl;
  std::string resp = Tello::Command("command");
  std::cout << resp << std::endl;
}

bool Tello::Land(void) {
  std::cout << "landing" << std::endl;
  std::string resp = Tello::Command("land");
  return resp == "OK" ? true : false;
}

bool  Tello::Takeoff(void) {
  std::cout << "taking off" << std::endl;
  std::string resp = Tello::Command("takeoff");
  return resp == "OK" ? true : false;
}

bool  Tello::Up(int dis) {
  Tello::mv_dis = dis;
  std::string resp = Tello::Command("up " + std::to_string(dis));
  return resp == "OK" ? true : false;
}

bool  Tello::Down(int dis) {
  Tello::mv_dis = dis;
  std::string resp = Tello::Command("down " + std::to_string(dis));
  return resp == "OK" ? true : false;
}

bool  Tello::Left(int dis) {
  Tello::mv_dis = dis;
  std::string resp = Tello::Command("left " + std::to_string(dis));
  return resp == "OK" ? true : false;
}

bool Tello::Right(int dis) {
  Tello::mv_dis = dis;
  std::string resp = Tello::Command("right " + std::to_string(dis));
  return resp == "OK" ? true : false;
}

bool  Tello::Forward(int dis) {
  Tello::mv_dis = dis;
  std::string resp = Tello::Command("forward " + std::to_string(dis));
  return resp == "OK" ? true : false;
}

bool  Tello::Back(int dis) {
  Tello::mv_dis = dis;
  std::string resp = Tello::Command("back " + std::to_string(dis));
  return resp == "OK" ? true : false;
}

bool  Tello::Cw(int deg) {
  Tello::mv_deg = deg;
  std::string resp = Tello::Command("cw " + std::to_string(deg));
  return resp == "OK" ? true : false;
}

bool  Tello::Ccw(int deg) {
  Tello::mv_deg = deg;
  std::string resp = Tello::Command("ccw " + std::to_string(deg));
  return resp == "OK" ? true : false;
}

std::string Tello::GetBattery(void) {
  std::string resp = Tello::Command("battery?");
  return resp;
}

std::string Tello::GetSpeed(void) {
  std::string resp = Tello::Command("speed?");
  return resp;
}

std::string Tello::GetFlightTime(void) {
  std::string resp = Tello::Command("time?");
  return resp;
}
