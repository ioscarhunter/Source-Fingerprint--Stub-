#ifndef FP_SEGMENTATOR
#define FP_SEGMENTATOR

#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace std;

//----------------------------------------------------------------------
const int FP_AREA             = 0;
const int NON_FP_AREA         = 255;

const int BLOCK_SIZE          = 16;
//----------------------------------------------------------------------
//Fingerprint (FP) Segmentator
//----------------------------------------------------------------------
class FpSegmentator {
public:
   //constructors & destructor
   
   //getters & setters
   
   //key methods
   FpSegmentator(const cv::Mat& fpImg, cv::Mat& maskImg);

   //operators

private:
   //attributes
   
   //helper (private) methods
   
};
//----------------------------------------------------------------------
#endif