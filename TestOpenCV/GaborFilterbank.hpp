#ifndef GABOR_FILTERBANK
#define GABOR_FILTERBANK

#include <iostream>
#include <vector>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "OfDetector.hpp"
#include "GaborFilter.hpp"
using namespace std;

//----------------------------------------------------------------------
//Gabor filterbank
//----------------------------------------------------------------------
class GaborFilterbank {
public:
   //constructors & destructor
   
   //getters & setters
   
   //key methods
   void filter(const cv::Mat& fpImg, const cv::Mat& ofImg, cv::Mat& filteredImg);
   
   //operators

private:
   //attributes
   vector<GaborFilter> gbs;
   //helper (private) methods

};
//----------------------------------------------------------------------
#endif