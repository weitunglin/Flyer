#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <boost/asio.hpp>
#include <unistd.h>
#include "tello.cpp"

using boost::asio::ip::udp;
 
int main(int argc, char ** argv) {

  Tello Tello;
  Tello.Start();
  Tello.Takeoff();
  sleep(5);
  Tello.Down(40);
  sleep(2);
  Tello.Up(40);
  sleep(2);
  Tello.Forward(40);
  sleep(2);
  Tello.Back(40);
  sleep(2);
  Tello.Left(40);
  sleep(2);
  Tello.Right(40);
  sleep(2);
  Tello.Cw(180);
  sleep(4);
  Tello.Ccw(180);
  sleep(4);
  Tello.Land();
  Tello.GetBattery();
  Tello.GetFlightTime();
  Tello.GetSpeed();

  std::cout << "end flight" << std::endl;
}