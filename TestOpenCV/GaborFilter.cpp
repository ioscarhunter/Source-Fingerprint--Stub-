#include "GaborFilter.hpp"

//----------------------------------------------------------------------
GaborFilter::GaborFilter(cv::Mat & kernel, double orientVal, double freqVal){
	this->kernel = kernel;
	this->theta = orientVal;
	this->freqVal = freqVal;
	
	//this->calculate();

}

cv::Mat GaborFilter::calculate() {

	//int margin = (kernel.rows - 1) / 2;//cos(0) and sin(0)

	//for (int y = -margin; y <= margin; y++)
	//{
	//	for (int x = -margin; x <= margin; x++)
	//	{
	//		x_theta = x*cos(theta) + y*sin(theta);
	//		y_theta = -x*sin(theta) + y*cos(theta);
	//		kernel.at<float>(margin+x, margin+y) = (float)exp(-0.5* (((pow(x_theta, 2)) / pow(sigma, 2)) + (pow(y_theta, 2)) / pow(sigma, 2))) * cos(2 * CV_PI*x_theta*freqVal);
	//		
	//	}
	//}

	return cv::getGaborKernel(cv::Size(kernel.cols, kernel.rows),sigma, theta, 1 / freqVal, 0.02);

}
//----------------------------------------------------------------------
