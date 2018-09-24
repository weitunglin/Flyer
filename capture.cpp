#ifndef CAPTURE_H
#include "capture.h"
#endif
#include <thread>

using namespace std;

Capture::Capture(std::string path) {
  Capture::isstop = false;
  Capture::camera_path = path;
  Capture::cap = cv::VideoCapture(path);
}

void Capture::start() {
  t = new thread(&Capture::queryframe, this);
  std::cout << "capture started" << std::endl;
}

void Capture::stop() {
  Capture::isstop = true;
  Capture::cap.release();
  Capture::t->join();
  std::cout << "capture stopped" << std::endl;
}

cv::VideoCapture Capture::getcap() {
  return Capture::cap;
}

cv::Mat Capture::getframe() {
  return Capture::frame;
}