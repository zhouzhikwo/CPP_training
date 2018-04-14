#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSDTC_NO_DEPRECATE
#include <iostream> 
#include <stdlib.h>
using namespace std;

/* 定义单向链表的结构 */
struct Node {
	double coef; // 系数
	int expn;    // 指数
	Node *next;  // 指针域
};

/* 生成带表头结点的单链表，除头结点外另生成n个结点 */
void CreatPoly(Node *&head, int n) {
	/* 初始化头结点 */
	head = new Node[sizeof(Node)];
	head->coef = 0;
	head->expn = 0;
	head->next = NULL; 

	/* 生成除头结点以外的其他结点 */
	cout << "分别每行输入各项系数及指数：" << endl;
	Node *p = head;

	/* 循环生成链表结点并赋值 */
	for (int i = 0; i < n; i++) {
		p->next = new Node[sizeof(Node)]; // 在链表尾部生成新结点
		p = p->next;
		cin >> p->coef >> p->expn;
		p->next = NULL;
	}
}

/* 输出一元二次多项式 */
void ShowPoly(Node *&head){
	if (head->next == NULL)	                     // 结果是0时直接输出0 
		cout << '0';
	else {
		for (Node *p = head->next; p != NULL; p = p->next) {
			if (p != head->next && p->coef > 0)  // 当p非首项且指向的系数为正时输出'+' 
				cout << '+';

			/* 系数为1或-1时特殊处理 */
			if (p->coef == 1) {
				if (p->expn == 0)                              // 判断条件不能写在一起(跟指数处理区分开)
					cout << '1';
			}
			else if (p->coef == -1)
				p->expn == 0 ? cout << "-1" : cout << '-';     // 指数为零时输出-1，不为零则输出‘-’
			else
				cout << p->coef;

			/* 指数为0或1时特殊处理 */
			switch (p->expn) {
			case 0:
				break;
			case 1:
				cout << 'x';
				break;
			default:
				p->expn < 0 ? printf("x^(%d)", p->expn) : printf("x^%d", p->expn); // 指数小于0时加括号 
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

/* 合并两个一元二次多项式 */
void AddPolynomial(Node *&pA, Node *&pB){  // 传进两个链表的头指针 
	Node *ha = pA;
	Node *hb = pB;
	Node *qa = ha->next;                   // ha, hb分别跟在qa, qb的后一位置 
	Node *qb = hb->next;                   // qa, qb分别指向Pa, Pb中当前比较元素 

	while (qa && qb){
		double sum = 0;
		switch (Comp(qa->expn, qb->expn)) {
		case '<':
			ha = qa;
			qa = qa->next;                 // 非ha = ha->next; 
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
				ha->next = ha->next->next;       // 删除和为0的结点，ha不变，还在qa后一位置 
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
			hb->next = hb->next->next; // 删除qb指向的结点 
			qb->next = ha->next;       // 将qb插入ha后qa前 
			ha->next = qb;
			qb = hb->next;             // 非 qb = ha->next 
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

/* 主函数 */
void main(void){
	Node *A = NULL, *B = NULL;
	int countA, countB;

	/* 输入部分 */
	cout << "请输入A的项数：" << endl;
	cin >> countA;
	CreatPoly(A, countA);                 // 生成A链表，长度为countA
	cout << "请输入B的项数：" << endl;        
	cin >> countB;
	CreatPoly(B, countB);                 // 生成B链表，长度为countB   

	/* 输出部分 */
	cout << " A = ";
	ShowPoly(A);
	cout << " B = ";
	ShowPoly(B);
	AddPolynomial(A, B);    
	cout << "A+B= ";
	ShowPoly(A);            // 执行AddPolynomial函数后：A = A + B
	cout << endl;

	delete[] A;             // 释放结点 
	system("pause");
	return;
}
