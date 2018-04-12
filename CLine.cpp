#include <memory>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Point{
	double x, y, z;
};

class CLine{
  public:
	int m_Color, m_width;
	int m_nPt, SizePt;
	Point *m_Pt;

	CLine(){
		m_nPt = 1;
		SizePt = 10;
		m_Pt = new Point[SizePt];
		m_width = 1;
		m_Color = 1;
		m_Pt[0].x = m_Pt[0].y = m_Pt[0].z = 0;
	};
	~CLine(){
		delete[] m_Pt;
	};

	void SetColor(int c){
		m_Color = c;
	}
	int GetColor(){
		return m_Color;
	}
	void SetWidth(int w){
		m_width = w;
	}
	int GetWidth(){
		return m_width;
	}

	void SetVal(Point* pt, int nPt, int c, int w){
		m_Color = c;
		m_width = w;
		m_nPt = nPt;
		if (m_nPt > SizePt){
			SizePt += 10;
			delete[] m_Pt;
			m_Pt = new Point[SizePt];
			memcpy(m_Pt, pt, m_nPt * sizeof(Point));
		}

	}

	CLine AddPT(Point &pt, int n){
		if (m_nPt + 1 > SizePt){
			SizePt += 10;
			Point *Temp = new Point[SizePt];
			memcpy(Temp, m_Pt, m_nPt * sizeof(Point));
			delete[] m_Pt;
			m_Pt = Temp;
		}

		if (n > m_nPt + 1)
			exit(-1);
		else if (n = m_nPt + 1){
			m_Pt[m_nPt] = pt;
			m_nPt++;
		}
		else if (n >= 0 && n <= m_nPt){
			int i = n - 1;
			int j = m_nPt;
			while (i < j){
				m_Pt[j] = m_Pt[j - 1];
				j--;
			}
			m_Pt[i] = pt;
			m_nPt++;
		}
		else
			exit(-1);

		return *this;
	}

	CLine DeletePt(int n){
		int i = n - 1;
		int tab = 0;
		while (i < m_nPt){
			int j = i;
			while (j < m_nPt - 1){
				m_Pt[j] = m_Pt[j + 1];
				j++;
			}
			tab++;
			m_nPt--;
		}
		if (tab != 0 && SizePt > m_nPt + 10 && m_nPt > 0){
			m_nPt -= 10;
			Point *Temp = new Point[m_nPt];
			memcpy(Temp, m_Pt, m_nPt * sizeof(Point));
			delete[] m_Pt;
			m_Pt = Temp;
		}
		return *this;
	}

	void AlterPt(Point &pt, int n){
		m_Pt[n - 1] = pt;
	}
	int GetPtNumber(){
		return m_nPt;
	}
	Point GetPt(int n){
		return m_Pt[n - 1];
	}
};

int main(){
	system("pause");
	return 0;
}
