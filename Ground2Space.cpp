#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

#define PI 3.1415926

/**********************************************************
*	�˳���ʵ�ִ������ϵ����Ϳռ�ֱ������ϵ�����ת����  *
*	�ο�������Ϊ2000���Ҵ������ϵ����CGCS-2000����     *
*	Author:Zhouzhikwo.                                    *
*	Date:2018/3/8 14:53:31                                *
**********************************************************/

// �ռ�ֱ������ϵ�ṹ
typedef struct tagSpace {
	double x;
	double y;
	double z;
}Space;
typedef Space *pSpace;

// �������ϵ�ṹ
typedef struct tagGround {
	double longitude;
	double latitude;
	double height;
}Ground;
typedef Ground *pGround;

// �ȷ���ת��Ϊ����
void DMS_RAD(double DMS, double *Rad) {
	*Rad = DMS / 180.0*PI;

	return;
}

// ����ת��Ϊ�ȷ���
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

// �ռ�ֱ������ϵת��Ϊ�������ϵ
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

// �������ϵת��Ϊ�ռ�ֱ������ϵ
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

// ��������ʵ�ֿռ�ֱ������ϵ�ʹ������ϵ���໥ת��
void main() {
	pSpace pS = new Space;
	pGround pG = new Ground;

	// �����ݽ�������
	// B=30.30.18.4323  L=114.24.23.1455  H=54.662
	double rad;
	rad = (30 * 3600 + 30 * 60 + 18.4323) / 3600;
	pG->latitude = rad;
	rad = (114 * 3600 + 24 * 60 + 23.1455) / 3600;
	pG->longitude = rad;
	pG->height = 20.258;

	// 2000���Ҵ������ϵ����
	double a = 6378137;
	double f = 1 / 298.257222101;

	cout << std::fixed;

	// �������ӡ����Ļ��
	cout << "ת��ǰ��֪�Ĵ�����꣺" << endl;
	cout << "H(�߳�)=" << pG->height << "   " << "L(����)=" << pG->longitude << "   " << "B(γ��)=" << pG->latitude << endl;

	Ground2Space(pG, pS, a, f);
	cout << endl;

	cout << "ת����Ŀռ�ֱ������ϵ��";
	cout << "x=" << pS->x << "   " << "y=" << pS->y << "   " << "z=" << pS->z << "   " << endl;

	Space2Ground(pS, pG, a, f);
	cout << endl;

	cout << "��ת��������껹ԭΪ������꣺" << endl;
	cout << "H(�߶�)=" << pG->height << "   " << "L(����)=" << pG->longitude << "   " << "B(γ��)=" << pG->latitude << endl;
	cout << endl;

	system("pause");
	return;
}