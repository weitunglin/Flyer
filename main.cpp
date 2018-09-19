//
//  main.cpp
//  Project_cpp
//
//  Created by weitung on 2018/9/16.
//  Copyright © 2018 weitung. All rights reserved.
//

#include <iostream>
#include <string>
#include <thread>
#include "capture.h"
#include "capture.cpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void detectAndDisplay(Mat frame);

String face_cascade_name = "haarcascade_frontalface_default.xml";
String eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
String body_cascade_name = "haarcascade_fullbody.xml";
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;
CascadeClassifier body_cascade;
String window_name = "Face Detection";

int main(int argc, char** argv) {
    Capture capture(argv[1]);
    capture.start();
    Mat frame;
    namedWindow("video capture", WINDOW_NORMAL);
    
    if(!face_cascade.load(face_cascade_name)) { cout << "Error loading face_cascade." << endl; return -1; } 
    if(!eyes_cascade.load(eyes_cascade_name)) { cout << "Error loading eyes_cascade." << endl; return -1; } 
    if(!body_cascade.load(body_cascade_name)) { cout << "Error loading body_cascade." << endl; return -1; } 
    if(!capture.getcap().isOpened()) { cout << "Error loading video capture." << endl; return -1; }
    cout << capture.getcap().get(CAP_PROP_FPS) << endl;

    while(capture.getcap().isOpened()) {
        frame = capture.getframe();
        if(frame.empty()) {
            cout << "No captured frame" << endl;
            break;
        }
        
        detectAndDisplay(frame);

        char c = (char)waitKey(1);
        if(c == 32) { break; }
    }

    destroyAllWindows();
    return 0;
}

void detectAndDisplay(Mat frame) {
    vector<Rect> faces;
    vector<Rect> bodies;
    Mat frame_gray;
    
    cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
    // equalizeHist(frame_gray, frame_gray);
    
    // body_cascade.detectMultiScale(frame_gray, bodies);
    // cout << bodies.size() << endl;
    // for(size_t i = 0; i < bodies.size(); i++) {
    //     rectangle(frame, Point(bodies[i].x, bodies[i].y), Point(bodies[i].width + bodies[i].x, bodies[i].y + bodies[i].height), Scalar(255, 255, 255), 2);
    // }

    face_cascade.detectMultiScale(frame_gray, faces, 1.1, 5, 0, Size(40, 40));
    
    for(size_t i = 0; i < faces.size(); i++) {
        rectangle(frame, Point(faces[i].x, faces[i].y), Point(faces[i].width + faces[i].x, faces[i].y + faces[i].height), Scalar(0, 0, 0), 5);

        // Mat faceROI = frame_gray(faces[i]);
        // vector<Rect> eyes;

        // eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30));

        // for(size_t j = 0; j < eyes.size(); j++) {
        //     Point eye_center(faces[i].x + eyes[j].x + eyes[j].width / 2, faces[i].y + eyes[j].y + eyes[j].height / 2);
        //     int radius = cvRound((eyes[j].width + eyes[j].height) * 0.25);
        //     circle(frame, eye_center, radius, Scalar(255, 0, 0), 4, 8, 0);
        // }
    }
    imshow(window_name, frame);
}

