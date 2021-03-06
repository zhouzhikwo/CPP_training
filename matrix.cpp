// matrix.cpp: 定义控制台应用程序的入口点。
//

#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
class MyMatrix
{
  public:
	T *m_p;
	int m_nRow, m_nCol;
	MyMatrix(T *p, int r = 0, int c = 0)
	{
		//this->a = a;
		m_nRow = r;
		m_nCol = c;
		if (m_nRow == 0 || m_nCol == 0)
			m_p = NULL;
		else
		{
			m_p = new T[m_nRow * m_nCol]; //[m][n];
			for (int i = 0; i < m_nRow; i++)
				for (int j = 0; j < m_nCol; j++)
					*(m_p + i * m_nCol + j) = *(p + i * m_nCol + j); //a[i][j] = s[i][j];
		}
	}
	MyMatrix(MyMatrix &s)
	{ //拷贝构造函数
		m_nRow = s.m_nRow;
		m_nCol = s.m_nCol;
		m_p = new T[m_nRow * m_nCol]; //[m][n];
		for (int i = 0; i < m_nRow; i++)
			for (int j = 0; j < m_nCol; j++)
				*(m_p + i * m_nCol + j) = *(s.m_p + i * m_nCol + j);
	}
	~MyMatrix() //()
	{
		//	for(int i = 0 ; i<m ; i++)
		delete[] m_p; //p[i];
	}
	void display()
	{
		if (m_nRow == 0 || m_nCol == 0)
		{
			cout << "该矩阵没有元素\n";
			return;
		}
		for (int i = 0; i < m_nRow; i++)
		{
			for (int j = 0; j < m_nCol; j++)
				cout << *(m_p + i * m_nCol + j) << "  ";
			cout << endl;
		}
	}
	void SetValPosition(int m, int n, T x)
	{
		*(m_p + n * m_nCol + m) = x;
	}
	void Transpose(MyMatrix &A)
	{
		for (int i = 0; i < m_nRow; i++)
		{
			for (int j = 0; j < m_nCol; j++)
				*(this->m_p + i * m_nCol + j) = *(A.m_p + i + j * m_nRow);
		}
	}
};

template <class T>
void Inputp(T *s, int m, int n)
{
	cout << "请输入" << m << "*" << n << "矩阵:";
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> *(s + i * n + j); //a[i][j];
}

int main()
{
	int m, n;
	cout << "请输入矩阵的行数及列数:";
	cin >> m >> n;
	int *p; //p[m][n];
	p = new int[m * n];
	Inputp(p, m, n);

	MyMatrix<int> A(p, m, n);
	cout << "Matrix a:\n";
	A.display();

	A.SetValPosition(0, 0, 1);
	cout << "定点修改后：\n";
	A.display();

	MyMatrix<int> B(p, n, m);
	B.Transpose(A);
	cout << "转置后：\n";
	B.display();

	delete[] p;
	system("pause");
	return 0;
}
