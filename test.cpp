#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <boost/asio.hpp>
#include <unistd.h>
#include "tello.cpp"

using boost::asio::ip::udp;
 
int main(int argc, char ** argv) {
  std::string send_msg = "";

  Tello Tello(8889);
  Tello.Start();
  Tello.Takeoff();
  sleep(3);
  Tello.Land();

  std::cout << "end flight" << std::endl;
}