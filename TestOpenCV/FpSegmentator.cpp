#include "FpSegmentator.hpp"
#include <math.h>

//----------------------------------------------------------------------
void computeTwoMeans(const cv::Mat& inImg, const double T, double& m1, double& m2) {
	m1 = m2 = 0;
	double count1 = 0, count2 = 0;
	for (int i = 0; i < inImg.rows; ++i)
		for (int j = 0; j < inImg.cols; ++j) {
			if (inImg.at<uchar>(i, j) > T) {
				m1 += inImg.at<uchar>(i, j);
				count1++;
			}
			else {
				m2 += inImg.at<uchar>(i, j);
				count2++;
			}
		}
	m1 /= count1;
	m2 /= count2;
}

double iterativeThreshold(const cv::Mat& tmpImg, double deltaT = 0, double maxIt = 10) {
	double T = 128, newT;
	double m1, m2;
	//cout << "Initial T = " << T << endl;
	for (int count = 1; count <= maxIt; count++) {
		//steps 2 & 3: perform basic thresholding and compute m1 and m2
		computeTwoMeans(tmpImg, T, m1, m2);
		//steps 4: compute a new value of T 
		newT = (m1 + m2) / 2;
		//cout <<  "Iteration " << count << ": T = " << newT << endl;
		//steps 5: check stop cond 
		if (abs(T - newT) < deltaT || count >= maxIt)
			break;
		T = newT;
	}
	return newT;
}

FpSegmentator::FpSegmentator(const cv::Mat& fpImg, cv::Mat& maskImg) {

	cout << "Stub: fingerprint segmentation" << endl;

	int count_inten = 0;
	cv::Mat tmpImg = fpImg.clone();
	double T = iterativeThreshold(tmpImg, 1, 10);

	/*vector<vector<double>> avg_inten_table;
	vector<double> avg_inten_row;

	for(int i = 0; i < fpImg.cols; i++) {
	for(int j = 0; j < fpImg.rows; j++) {
	if(i % BLOCK_SIZE == 0 || j % BLOCK_SIZE == 0) {
	avg_inten_row.push_back(count_inten);
	count_inten = 0;
	}
	}
	}*/

	for (int i = 0; i < tmpImg.cols; i++) {
		for (int j = 0; j < tmpImg.rows; j++) {
			if (i % BLOCK_SIZE == 0 && j % BLOCK_SIZE == 0) {

				cv::Rect roi(i, j, BLOCK_SIZE, BLOCK_SIZE);
				cv::Mat image_roi = tmpImg(roi);
				cv::Scalar avgPixelIntensity = cv::mean(image_roi);

				//prints out only .val[0] since image was grayscale
				//cout << "Pixel intensity over ROI at " << j << ", " << i << " = " << avgPixelIntensity.val[0] << endl;

				if (avgPixelIntensity.val[0] < 50) {
					//(avgPixelIntensity.val[0] < 50 || avgPixelIntensity.val[0] > 230){
					//if(avgPixelIntensity.val[0] < 50 || (avgPixelIntensity.val[0] > 75 && avgPixelIntensity.val[0] < 163)) {
					cv::Mat black_roi = cv::Mat::zeros(BLOCK_SIZE, BLOCK_SIZE, CV_32F);
					//cv::Mat black_roi = cv::Mat(BLOCK_SIZE, BLOCK_SIZE, CV_32F, cv::Scalar(255));
					black_roi.copyTo(tmpImg(cv::Rect(i, j, BLOCK_SIZE, BLOCK_SIZE)));
				}
			}
		}
	}

	maskImg = tmpImg.clone();     





}
//----------------------------------------------------------------------