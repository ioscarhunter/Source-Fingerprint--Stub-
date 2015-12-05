#include "MnExtractor.hpp"

void MnExtractor::extract(const cv::Mat& enhancedImg, MnSet& mnSet) {

	cout << "Stub: minutaie extraction" << endl;
	// minutiae extraction

	cv::Mat marker = cv::Mat::zeros(enhancedImg.size(), CV_8UC1);

	for (int i = 1; i < enhancedImg.rows - 1; i++)
	{
		for (int j = 1; j < enhancedImg.cols - 1; j++)
		{
			uchar p2 = enhancedImg.at<uchar>(i - 1, j);
			uchar p3 = enhancedImg.at<uchar>(i - 1, j + 1);
			uchar p4 = enhancedImg.at<uchar>(i, j + 1);
			uchar p5 = enhancedImg.at<uchar>(i + 1, j + 1);
			uchar p6 = enhancedImg.at<uchar>(i + 1, j);
			uchar p7 = enhancedImg.at<uchar>(i + 1, j - 1);
			uchar p8 = enhancedImg.at<uchar>(i, j - 1);
			uchar p9 = enhancedImg.at<uchar>(i - 1, j - 1);
			int numcos = (p2 == 0 && p3 == 1) + (p3 == 0 && p4 == 1) +
				(p4 == 0 && p5 == 1) + (p5 == 0 && p6 == 1) +
				(p6 == 0 && p7 == 1) + (p7 == 0 && p8 == 1) +
				(p8 == 0 && p9 == 1) + (p9 == 0 && p2 == 1);
			cout << "Crossing Number = " << numcos << endl;
			if (numcos <= 3) mnSet.push_back(Minutiae(cv::Point2f(i, j), numcos));
		}
	}





}
//----------------------------------------------------------------------