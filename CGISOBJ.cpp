// CGISOBJ.cpp: 定义控制台应用程序的入口点。
//

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSDTC_NO_DEPRECATE
#include <iostream>
#include <stdlib.h>
using namespace std;

class CPt
{
public:
	CPt() {};
	~CPt() {};
	double m_x, m_y;
	void SetVal(double x, double y) {
		m_x = x;
		m_y = y;
	}
	double GetX() { return m_x; }
	double GetY() { return m_y; }
};

class CGISOBJ {
public:
	CGISOBJ() {
		m_ptSum = 0;
		m_name[0] = 0;
	};
	~CGISOBJ() {};

	char m_name[16];
	CPt m_pList[100];
	int m_ptSum;
	void SetVal(char *str, CPt *pList, int ptSum) {
		strcpy(m_name, str);  // 字符串应使用 strcpy 函数实现赋值操作
		m_ptSum = ptSum;
		for (int i = 0; i < m_ptSum; i++) {   // 数组应使用循环赋值
			m_pList[i] = pList[i];
		}
	}
	CPt GetCent() {
		CPt cent;
		cent.SetVal(0, 0);
		for (int i = 0; i < m_ptSum; i++) {
			cent.SetVal(m_pList[i].GetX() + cent.GetX(), m_pList[i].GetY() + cent.GetY());
		}
		cent.SetVal(cent.GetX() / m_ptSum, cent.GetY() / m_ptSum);
		return cent;
	}
};

int main()
{
	// 点类 验证
	CPt pt;
	pt.SetVal(1, 1);
	cout << pt.GetX() << ',' << pt.GetY() << endl;

	// GIs目标类验证
	CGISOBJ obj;
	CPt list[3];
	list[0].SetVal(0, 0);
	list[1].SetVal(1, 1);
	list[2].SetVal(2, 2);
	char p1[] = "obj1";
	obj.SetVal(p1, list, 3);
	pt = obj.GetCent();
	cout << "Center is:" << pt.GetX() << ',' << pt.GetY() << endl;

	system("pause");
    return 0;
}

