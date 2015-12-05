#include "Binarizer.hpp"

//----------------------------------------------------------------------
Binarizer::Binarizer(const cv::Mat& fpImg, cv::Mat& binaryImg) {
   cv::threshold(fpImg, binaryImg, 128, 255, cv::THRESH_BINARY | cv::THRESH_OTSU); 
}
//----------------------------------------------------------------------