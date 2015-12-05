#ifndef OF_DETECTOR
#define OF_DETECTOR

#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace std;

//----------------------------------------------------------------------
//Orientation Field (OF) Detector
//----------------------------------------------------------------------
class OfDetector {
public:
   //constructors & destructor
   
   //getters & setters
   
   //key methods
   void detect(const cv::Mat& fpImg, cv::Mat& ofImg,double freq);
   
   //operators

private:
   //attributes
   
   //helper (private) methods

};
//----------------------------------------------------------------------
#endif