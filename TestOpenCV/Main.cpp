#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "FpSegmentator.hpp"
#include "FpMatcher.hpp"
#include "OfDetector.hpp"
#include "Binarizer.hpp"
#include "FpEnhancer.hpp"
#include "FpSegmentator.hpp"
#include "GaborFilter.hpp"
#include "Skeletonizer.hpp"

using namespace std;

//----------------------------------------------------------------------
int main() {
   //read fingerprint image 1
   cv::Mat fpImg1 = cv::imread("D:/Desktop/Source Fingerprint (Stub)/FP DB (subset)/2_1.BMP", CV_LOAD_IMAGE_GRAYSCALE);
   cv::imshow("in", fpImg1);
   
   
   cv::Mat segmented;
   FpSegmentator(fpImg1, segmented);
 

   cv::Mat ofImg1/* = segmented.clone()*/;


   //cout << "ker " << kernel << endl;
   
   //cv::filter2D(ofImg1, ofImg1, CV_32F, g.calculate());
   OfDetector of;
   of.detect(segmented, ofImg1,1);
   cv::imshow("fp1", ofImg1);

   //Binarizer(ofImg1, ofImg1);

   /*cv::Mat skeleton1;
   
   Skeletonizer(ofImg1, skeleton1);

   cv::imshow("sk1", skeleton1);*/


   ////read fingerprint image 2
   //cv::Mat fpImg2 = cv::imread("D:/Skydrive/Documents/Visual Studio 2015/Projects/CV Test/x64/Debug/11.BMP", CV_LOAD_IMAGE_GRAYSCALE);
   //cv::imshow("fp2", fpImg1);

   ////match two fingerprint images
   //FpMatcher fpMatcher;
   //double similarity = fpMatcher.match(fpImg1, fpImg2);
   //cout << "Similarity = " << similarity << endl;

   cv::waitKey();
}
//----------------------------------------------------------------------