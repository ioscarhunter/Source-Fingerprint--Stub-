#include "OfDetector.hpp"
#include "GaborFilter.hpp"
#include "Binarizer.hpp"

#include <cmath>
#define PI 3.14159265

//----------------------------------------------------------------------
void OfDetector::detect(const cv::Mat& fpImg, cv::Mat& ofImg, double freq) {


	cout << "Stub: orietation field (OF) detection" << endl;


	cv::Mat absGx, absGy, M;

	double seta = 0;
	int size = 16;
	int margin = 0;/*(size ) / 2;*/
	ofImg = cv::Mat(fpImg.rows, fpImg.cols, CV_8U);
	int len = (size / 2) - 1;

	for (int x = margin; x < fpImg.cols - margin; x += size)
	{
		for (int y = margin; y < fpImg.rows - margin; y += size)
		{
			//copy
			//cv::Mat blocktemp = cv::Mat(size, size, CV_32F);
			float theta = 0;
			float result1 = 0;
			float result2 = 0;

			//cv::Mat px = cv::Mat(size, size, CV_32F);
			//cv::Mat py = cv::Mat(size, size, CV_32F);

			cv::Mat kernel = cv::Mat(3, 3, CV_32F);


			cv::Mat gx, gy;

			//fpImg.copyTo(blocktemp(cv::Rect(x, y, size, size)));

			//cv::Mat sum;

			/*for (int i = 0; i < blocktemp.cols; i++) {
				for (int j = 0; j < blocktemp.rows; j++) {
					blocktemp.at<float>(i, j) = fpImg.at<uchar>(x + i, y + j);
					sum += blocktemp.at<float>(i, j);
				}
			}*/

			cv::Mat tmpImg = fpImg.clone();
			cv::Rect roi(y, x, size, size);
			cv::Mat blocktemp = tmpImg(roi);
			cv::Scalar sum = cv::sum(blocktemp);
			//cv::reduce(blocktemp, sum, 0, CV_REDUCE_SUM, CV_32S);


			if (sum.val[0] > 0) {
				//sobel
				//compute gratitude
				cv::Sobel(blocktemp, gy, CV_32F, 1, 0, 15, 1, 0, cv::BORDER_DEFAULT);
				cv::Sobel(blocktemp, gx, CV_32F, 0, 1, 15, 1, 0, cv::BORDER_DEFAULT);

				for (int r = 0; r < gy.rows; r++) {
					for (int c = 0; c < gx.cols; c++) {
						result1 += 2 * gx.at<float>(r, c)*gy.at<float>(r, c);
						result2 += (pow(gx.at<float>(r, c), 2) + pow(gy.at<float>(r, c), 2));
						//result1 = gx.at<float>(c, r);
						//result2 = gy.at<float>(c, r);
						/*theta.at<float>(c, r) = 0.5*atan(result1 / result2) * 180 / PI;*/
						//px = cos(2 * theta.at<float>(c, r));
						//py = sin(2 * theta.at<float>(c, r));
					}

				}


				//Vx = result1;
				//Vy = result2;

				if (result1 != 0 && result2 != 0) {
					theta = 90 + (0.5*atan(result1 / result2) * (180 / PI));
				}



				// Perform low-pass filtering

				//lowPassX = cos(2 * theta);
				//lowPassY = sin(2 * theta);


				////for (int u = 0; u < size; u++)
				////{
				////	for (int v = 0; v < size; v++)
				////	{
				////		lowPassX2 += blocktemp.at<float>(u, v) * lowPassX;
				////		lowPassY2 += blocktemp.at<float>(u, v) * lowPassY;
				////	}
				////}

				//float calc2 = 0.0;

				//if (lowPassX != 0 && lowPassY != 0)
				//{
				//	calc2 = 0.5 * atan(lowPassY / lowPassX) * 180 / PI;
				//}

				//cout << "x " << gx << "y " << gy << endl;
				cout << "the " << theta << endl;
				seta = theta;
				cv::Mat tempfreq = cv::Mat(size, size, CV_32F);

				for (double i = 0.1; i <= 1; i += 0.05) {

					cv::Mat tmp = cv::Mat(3, 3, CV_32F);
					GaborFilter g = GaborFilter(tmp, theta, i);
					g.calculate();

					cv::filter2D(blocktemp, tempfreq, CV_32F, g.calculate());

					cv::Scalar avgPixelIntensity = cv::mean(tempfreq);

					//prints out only .val[0] since image was grayscale
					//cout << "Pixel intensity over ROI at " << j << ", " << i << " = " << avgPixelIntensity.val[0] << endl;

					if (avgPixelIntensity.val[0] < 100 && avgPixelIntensity.val[0] < 200) {
						break;
					}
				}

				cv::convertScaleAbs(tempfreq, tempfreq);
				//Binarizer(tempfreq, tempfreq);

				cv::Point P1(size / 2, size / 2);

				cv::Point P2;

				P2.x = P1.x + len*cos((0 + theta) * PI / 180);
				P2.y = P1.y + len*sin((0 + theta) * PI / 180);
				cv::Point P3(-P2.x, -P2.y);

				cv::line(tempfreq, P1, P2, cv::Scalar(255, 255, 255));
				//seta = 0.5 *( atan2(result1 , result2) * 180 / PI);


				for (int i = 0; i < blocktemp.cols; i++) {
					for (int j = 0; j < blocktemp.rows; j++) {
						ofImg.at<uchar>(x - margin + i, y - margin + j) = tempfreq.at<uchar>(i, j);
					}
				}

			}
		}


	}

}
//----------------------------------------------------------------------