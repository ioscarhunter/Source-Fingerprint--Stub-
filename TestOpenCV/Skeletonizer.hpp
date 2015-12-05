#ifndef SKELETONIZER
#define SKELETONIZER

#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace std;

//----------------------------------------------------------------------
//Skeletonizer
//----------------------------------------------------------------------
class Skeletonizer {
public:
   //constructors & destructor
   
   //getters & setters
   
   //key methods
   Skeletonizer(const cv::Mat& binaryImg, cv::Mat& skeletonImg);
   static void thinningIteration(cv::Mat& im, int iter);
   //operators

private:
   //attributes
   
   //helper (private) methods

};
//----------------------------------------------------------------------
#endif