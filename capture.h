#ifndef CAPTURE_H
#define CAPTURE_H
#endif
#ifndef OPENCV_VIDEOIO_HPP
#include <opencv2/videoio.hpp>
#endif
#ifndef OPENCV_OPENCV_HPP
#include <opencv2/opencv.hpp>
#endif
#ifndef _STRING_H
#include <string>
#endif
#include <thread>

class Capture {
  std::string camera_path;
  std::thread* t;
  cv::VideoCapture cap;
  cv::Mat frame;
  bool isstop;
  void queryframe(){
    while(!Capture::isstop) {
      Capture::cap.read(Capture::frame);
      // std::this_thread::sleep_for(std::chrono::milliseconds(40));
    }
  }

  public:
    Capture(std::string path);
    void start();
    void stop();
    cv::Mat getframe();
    cv::VideoCapture getcap();
};