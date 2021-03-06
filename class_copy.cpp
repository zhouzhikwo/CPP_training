// class_copy.cpp: 定义控制台应用程序的入口点。
//

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSDTC_NO_DEPRECATE
#include <iostream>
#include <stdlib.h>
using namespace std;

class CPt {
public:
	CPt() {};
	~CPt() {};
	double m_x, m_y;
	void SetVal(double x, double y) {
		m_x = x;
		m_y = y;
	};
	void copy(CPt &pt) {
		if (this == &pt)
			return;
		*this = pt;
	};
	void show() {
		cout << m_x << ',' << m_y << endl;
	}

};

int main()
{
	CPt pt1, pt2;
	pt2.SetVal(1, 2);
	pt1.show();
	pt2.show();
	pt1.copy(pt1);
	pt1.show();

	system("pause");
    return 0;
}

