#ifndef FP_MATCHER
#define FP_MATCHER

#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "FpSegmentator.hpp"
#include "FpEnhancer.hpp"
#include "MnExtractor.hpp"
#include "MnMatcher.hpp"
using namespace std;

//----------------------------------------------------------------------
//Fingerprint (FP) Matcher
//----------------------------------------------------------------------
class FpMatcher {
public:
   //constructors & destructor
   
   //getters & setters
   
   //key methods
   double match(const cv::Mat& fpImg1, const cv::Mat& fpImg2);
  
   //operators

private:
   //attributes
   FpSegmentator  fpSegmentator;
   FpEnhancer     fpEnhancer;
   MnExtractor    mnExtractor;
   MnMatcher      mnMatcher;
 
   //helper (private) methods
   
};
//----------------------------------------------------------------------
#endif