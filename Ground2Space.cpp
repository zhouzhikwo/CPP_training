#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

#define PI 3.1415926

/**********************************************************
*	此程序实现大地坐标系坐标和空间直角坐标系坐标的转换。  *
*	参考椭球体为2000国家大地坐标系椭球（CGCS-2000）。     *
*	Author:Zhouzhikwo.                                    *
*	Date:2018/3/8 14:53:31                                *
**********************************************************/

// 空间直角坐标系结构
typedef struct tagSpace {
	double x;
	double y;
	double z;
}Space;
typedef Space *pSpace;

// 大地坐标系结构
typedef struct tagGround {
	double longitude;
	double latitude;
	double height;
}Ground;
typedef Ground *pGround;

// 度分秒转换为弧度
void DMS_RAD(double DMS, double *Rad) {
	*Rad = DMS / 180.0*PI;

	return;
}

// 弧度转换为度分秒
void RAD_DMS(double Rad, double *DMS) {
	int Deg, Min;
	double Sec;
	double AR, AM;
	AR = Rad;
	if (Rad < 0)
		AR = -Rad;
	AR = AR + 1.0e-10;
	AR = AR * 180.0 / PI;
	Deg = (int)AR;
	AM = (AR - Deg)*60.0;
	Min = (int)AM;
	Sec = (AM - Min) * 60;
	*DMS = Deg + Min / 100.0 + Sec / 10000.0;
	if (Rad < 0)
		*DMS = -*DMS;
	return;
}

// 空间直角坐标系转换为大地坐标系
bool Space2Ground(pSpace pS, pGround pG, double a, double f) {
	double B0, R, N;
	double B_, L_;
	double X = pS->x;
	double Y = pS->y;
	double Z = pS->z;

	double b = a - f * a;
	double e = sqrt((a*a - b * b) / (a * a));

	R = sqrt(X*X + Y * Y);
	B0 = atan2(Z, R);
	while (1) {
		N = a / sqrt(1.0 - e * e*sin(B0)*sin(B0));
		B_ = atan2(Z + N * e*e*sin(B0), R);
		if (fabs(B_ - B0) < 1.0e-10)
			break;
		B0 = B_;
	}
	L_ = atan2(Y, X);

	pG->height = R / cos(B_) - N;
	RAD_DMS(B_, &pG->latitude);
	RAD_DMS(L_, &pG->longitude);

	return true;
}

// 大地坐标系转换为空间直角坐标系
bool Ground2Space(pGround pG, pSpace pS, double a, double f) {
	double N, B_, L_;
	double B = pG->latitude;
	double L = pG->longitude;
	double H = pG->height;

	double b = a - f * a;
	double e = sqrt((a*a - b * b) / (a * a));

	DMS_RAD(B, &B_);
	DMS_RAD(L, &L_);

	N = a / sqrt(1.0 - e*e*sin(B_)*sin(B_));
	pS->x = (N + H)*cos(B_)*cos(L_);
	pS->y = (N + H)*cos(B_)*sin(L_);
	pS->z = (N*(1.0 - e*e) + H)*sin(B_);
	return true;
}

// 主函数：实现空间直角坐标系和大地坐标系的相互转换
void main() {
	pSpace pS = new Space;
	pGround pG = new Ground;

	// 将数据进行输入
	// B=30.30.18.4323  L=114.24.23.1455  H=54.662
	double rad;
	rad = (30 * 3600 + 30 * 60 + 18.4323) / 3600;
	pG->latitude = rad;
	rad = (114 * 3600 + 24 * 60 + 23.1455) / 3600;
	pG->longitude = rad;
	pG->height = 20.258;

	// 2000国家大地坐标系参数
	double a = 6378137;
	double f = 1 / 298.257222101;

	cout << std::fixed;

	// 将结果打印到屏幕上
	cout << "转换前已知的大地坐标：" << endl;
	cout << "H(高程)=" << pG->height << "   " << "L(经度)=" << pG->longitude << "   " << "B(纬度)=" << pG->latitude << endl;

	Ground2Space(pG, pS, a, f);
	cout << endl;

	cout << "转换后的空间直角坐标系：";
	cout << "x=" << pS->x << "   " << "y=" << pS->y << "   " << "z=" << pS->z << "   " << endl;

	Space2Ground(pS, pG, a, f);
	cout << endl;

	cout << "由转换后的坐标还原为大地坐标：" << endl;
	cout << "H(高度)=" << pG->height << "   " << "L(经度)=" << pG->longitude << "   " << "B(纬度)=" << pG->latitude << endl;
	cout << endl;

	system("pause");
	return;
}