#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat gambar_a = imread("A1.jpg"); Mat gambar_b = imread("B1.jpg");
	Mat out;
	Point minloc, maxloc;
	double min, max;
	int x_tmp = gambar_a.cols / 3;
	int y_tmp = gambar_a.rows / 3;
	for (;;)
	{
		if (gambar_a.empty() || gambar_b.empty()) break;
		Mat a_hasil = gambar_a.clone();
		Mat b_hasil = gambar_b.clone();
		imshow("B", b_hasil);
		imshow("A", a_hasil);
		for (int i = 0; i<3; i++) //kebawah
		{
			for (int j = 0; j<3; j++) //nyamping
			{
				Rect kotak(j*x_tmp, i*y_tmp, x_tmp, y_tmp);
				rectangle(gambar_a, Rect(j*x_tmp, i*y_tmp, x_tmp, y_tmp), Scalar(0, 0, 0), 2);
				Mat tmp = gambar_a(kotak);
				matchTemplate(gambar_b, tmp, out, TM_CCOEFF_NORMED);
				minMaxLoc(out, NULL, &max, NULL, &maxloc);
				//printf("Posisi = %d,%d\n", maxloc.x,maxloc.y);
				//printf("Nilai = %f\n", max);
				if (max > 0.7)
				{
					int lokasi_ax = j*x_tmp; //lokasi x di A
					int lokasi_ay = i*y_tmp; //lokasi y di A
					int tmpx = maxloc.x; //lokasi x di B
					int tmpy = maxloc.y; //lokasi y di B
					int hasilx = lokasi_ax - tmpx; //lokasi x di hasil
					int hasily = lokasi_ay - tmpy; //lokasi y di hasil
					Mat hasil = Mat::zeros(Size(hasilx + b_hasil.cols, hasily + b_hasil.rows), CV_8UC3);
					rectangle(gambar_b, Rect(maxloc.x, maxloc.y, x_tmp, y_tmp), Scalar(255, 0, 0), 2);
					a_hasil.copyTo(hasil(Rect(0, 0, a_hasil.cols, a_hasil.rows)));
					b_hasil.copyTo(hasil(Rect(hasilx, hasily, b_hasil.cols, b_hasil.rows)));
					//cout << hasilx << " " << hasily << endl;
					imshow("hasil", hasil);
					imwrite("Hasil.jpg", hasil);
					waitKey(0);
				}
				//imshow("tmp", tmp);
				//imshow("B", gambar_b);
				//imshow("A", gambar_a);
				//waitKey(0);
			}
		}
	}
	return 0;
}