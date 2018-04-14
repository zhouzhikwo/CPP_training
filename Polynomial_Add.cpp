#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSDTC_NO_DEPRECATE
#include <iostream> 
#include <stdlib.h>
using namespace std;

/* ���嵥������Ľṹ */
struct Node {
	double coef; // ϵ��
	int expn;    // ָ��
	Node *next;  // ָ����
};

/* ���ɴ���ͷ���ĵ�������ͷ�����������n����� */
void CreatPoly(Node *&head, int n) {
	/* ��ʼ��ͷ��� */
	head = new Node[sizeof(Node)];
	head->coef = 0;
	head->expn = 0;
	head->next = NULL; 

	/* ���ɳ�ͷ��������������� */
	cout << "�ֱ�ÿ���������ϵ����ָ����" << endl;
	Node *p = head;

	/* ѭ�����������㲢��ֵ */
	for (int i = 0; i < n; i++) {
		p->next = new Node[sizeof(Node)]; // ������β�������½��
		p = p->next;
		cin >> p->coef >> p->expn;
		p->next = NULL;
	}
}

/* ���һԪ���ζ���ʽ */
void ShowPoly(Node *&head){
	if (head->next == NULL)	                     // �����0ʱֱ�����0 
		cout << '0';
	else {
		for (Node *p = head->next; p != NULL; p = p->next) {
			if (p != head->next && p->coef > 0)  // ��p��������ָ���ϵ��Ϊ��ʱ���'+' 
				cout << '+';

			/* ϵ��Ϊ1��-1ʱ���⴦�� */
			if (p->coef == 1) {
				if (p->expn == 0)                              // �ж���������д��һ��(��ָ���������ֿ�)
					cout << '1';
			}
			else if (p->coef == -1)
				p->expn == 0 ? cout << "-1" : cout << '-';     // ָ��Ϊ��ʱ���-1����Ϊ���������-��
			else
				cout << p->coef;

			/* ָ��Ϊ0��1ʱ���⴦�� */
			switch (p->expn) {
			case 0:
				break;
			case 1:
				cout << 'x';
				break;
			default:
				p->expn < 0 ? printf("x^(%d)", p->expn) : printf("x^%d", p->expn); // ָ��С��0ʱ������ 
				break;
			}
		}
	}
	cout << endl;
}


char Comp(int a, int b){
	if (a > b)
		return '>';
	if (a < b)
		return '<';
	return '=';
}

/* �ϲ�����һԪ���ζ���ʽ */
void AddPolynomial(Node *&pA, Node *&pB){  // �������������ͷָ�� 
	Node *ha = pA;
	Node *hb = pB;
	Node *qa = ha->next;                   // ha, hb�ֱ����qa, qb�ĺ�һλ�� 
	Node *qb = hb->next;                   // qa, qb�ֱ�ָ��Pa, Pb�е�ǰ�Ƚ�Ԫ�� 

	while (qa && qb){
		double sum = 0;
		switch (Comp(qa->expn, qb->expn)) {
		case '<':
			ha = qa;
			qa = qa->next;                 // ��ha = ha->next; 
			break;
		case '=':
			sum = qa->coef + qb->coef;
			if (sum != 0.0) {
				qa->coef = sum;
				ha = qa;
			}
			else {
				if (ha->next != qa)
					cout << "Error: ha->next != qa" << endl;
				ha->next = ha->next->next;       // ɾ����Ϊ0�Ľ�㣬ha���䣬����qa��һλ�� 
				delete[] qa;
			}
			if (hb->next != qb)
				cout << "Error: hb->next != qb" << endl;
			hb->next = hb->next->next;
			delete[] qb;
			qb = hb->next;
			qa = ha->next;
			break;
		case '>':
			hb->next = hb->next->next; // ɾ��qbָ��Ľ�� 
			qb->next = ha->next;       // ��qb����ha��qaǰ 
			ha->next = qb;
			qb = hb->next;             // �� qb = ha->next 
			ha = ha->next;
			break;
		default:
			cout << "Error!" << endl;
			break;
		}
	}
	if (qb)
		ha->next = qb;

	delete[] hb;
}

/* ������ */
void main(void){
	Node *A = NULL, *B = NULL;
	int countA, countB;

	/* ���벿�� */
	cout << "������A��������" << endl;
	cin >> countA;
	CreatPoly(A, countA);                 // ����A��������ΪcountA
	cout << "������B��������" << endl;        
	cin >> countB;
	CreatPoly(B, countB);                 // ����B��������ΪcountB   

	/* ������� */
	cout << " A = ";
	ShowPoly(A);
	cout << " B = ";
	ShowPoly(B);
	AddPolynomial(A, B);    
	cout << "A+B= ";
	ShowPoly(A);            // ִ��AddPolynomial������A = A + B
	cout << endl;

	delete[] A;             // �ͷŽ�� 
	system("pause");
	return;
}
