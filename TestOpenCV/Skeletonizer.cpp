#include "Skeletonizer.hpp"

//----------------------------------------------------------------------
/**
* Function for thinning the given binary image
*
* Parameters:
* 		binaryImg  The source image, binary with range = [0,255]
* 		skeletonImg  The destination image
*/
Skeletonizer::Skeletonizer(const cv::Mat& binaryImg, cv::Mat& skeletonImg) {

	cout << "Stub: Skeletonzie (thinning)" << endl;
	skeletonImg = binaryImg.clone();
	skeletonImg /= 255;         // convert to binary image

	cv::Mat prev = cv::Mat::zeros(skeletonImg.size(), CV_8UC1);
	cv::Mat diff;

	do {
		thinningIteration(skeletonImg, 0);
		thinningIteration(skeletonImg, 1);
		cv::absdiff(skeletonImg, prev, diff);
		skeletonImg.copyTo(prev);
	} while (cv::countNonZero(diff) > 0);

	skeletonImg *= 255;


}
//----------------------------------------------------------------------
/**
* Perform one thinning iteration.
* Normally you wouldn't call this function directly from your code.
*
* @param  im    Binary image with range = 0-1
* @param  iter  0=even, 1=odd
*/
void Skeletonizer::thinningIteration(cv::Mat& im, int iter)
{
	cv::Mat marker = cv::Mat::zeros(im.size(), CV_8UC1);

	for (int i = 1; i < im.rows - 1; i++)
	{
		for (int j = 1; j < im.cols - 1; j++)
		{
			uchar p2 = im.at<uchar>(i - 1, j);
			uchar p3 = im.at<uchar>(i - 1, j + 1);
			uchar p4 = im.at<uchar>(i, j + 1);
			uchar p5 = im.at<uchar>(i + 1, j + 1);
			uchar p6 = im.at<uchar>(i + 1, j);
			uchar p7 = im.at<uchar>(i + 1, j - 1);
			uchar p8 = im.at<uchar>(i, j - 1);
			uchar p9 = im.at<uchar>(i - 1, j - 1);

			int A = (p2 == 0 && p3 == 1) + (p3 == 0 && p4 == 1) +
				(p4 == 0 && p5 == 1) + (p5 == 0 && p6 == 1) +
				(p6 == 0 && p7 == 1) + (p7 == 0 && p8 == 1) +
				(p8 == 0 && p9 == 1) + (p9 == 0 && p2 == 1);
			int B = p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9;
			int m1 = iter == 0 ? (p2 * p4 * p6) : (p2 * p4 * p8);
			int m2 = iter == 0 ? (p4 * p6 * p8) : (p2 * p6 * p8);

			if (A == 1 && (B >= 2 && B <= 6) && m1 == 0 && m2 == 0)
				marker.at<uchar>(i, j) = 1;
		}
	}

	im &= ~marker;
}


