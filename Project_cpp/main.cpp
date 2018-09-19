//
//  main.cpp
//  Project_cpp
//
//  Created by weitung on 2018/9/16.
//  Copyright © 2018 weitung. All rights reserved.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, const char * argv[]) {
    
    VideoCapture cap(0);
    if(!cap.isOpened()) return -1;
    
    Mat frame;
    namedWindow("camera", 1);
    
    for(;;) {
        cap >> (frame);
        imshow("camera", frame);
        if(waitKey(30) >= 0) break;
    }
    
    destroyAllWindows();
    system("PAUSE");
    return 0;
}
