#ifndef MN_MATCHER
#define MN_MATCHER

#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "MnSet.hpp"
using namespace std;

//----------------------------------------------------------------------
//Minutiae Matcher
//----------------------------------------------------------------------
class MnMatcher {
public:
   //constructors & destructor
   
   //getters & setters
   
   //key methods
   double match(const MnSet& mnSet1, const MnSet& mnSet2);
   
   //operators

private:
   //attributes
   
   //helper (private) methods

};
//----------------------------------------------------------------------
#endif