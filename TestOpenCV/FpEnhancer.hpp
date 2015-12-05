#ifndef FP_ENHANCER
#define FP_ENHANCER

#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace std;

//----------------------------------------------------------------------
//Fingerprint (FP) Enhancer
//----------------------------------------------------------------------
class FpEnhancer {
public:
   //constructors & destructor
   
   //getters & setters
   
   //key methods
   void enhance(const cv::Mat& fpImg, const cv::Mat& maskImg, const cv::Mat& enhancedImg);
   
   //operators

private:
   //attributes
   
   //helper (private) methods

};
//----------------------------------------------------------------------
#endif