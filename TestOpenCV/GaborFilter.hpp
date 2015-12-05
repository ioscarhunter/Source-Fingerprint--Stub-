#ifndef GABOR_FILTER
#define GABOR_FILTER

#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <cmath>
using namespace std;

//----------------------------------------------------------------------
//Gabor filter
//----------------------------------------------------------------------
class GaborFilter : public cv::Mat {
public:
   //constructors & destructor
   GaborFilter(cv::Mat & kernel, double orientVal, double freqVal);
   
   //getters & setters
   
   
   //key methods
   cv::Mat calculate();

   //operators

private:
   //attributes
	cv::Mat kernel;
	double theta;
	double freqVal;
	double x_theta;
	double y_theta;

	double sigma = 2;

   //helper (private) methods
	
   
};
//----------------------------------------------------------------------
#endif