#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSDTC_NO_DEPRECATE
#include <iostream>
#include <stdlib.h>
using namespace std;
#define OVERFLOW -2
#define INIT_SIZE 100
#define INCREMENT 10
#define OK 1
#define ERROR 0
typedef char ElemType;
typedef int Status;

/* ����ṹ�� */
struct SqStack
{
    ElemType *base; // ջ��ָ��
    ElemType *top;  // ջ��ָ��
    int stacksize;  // ��ǰջ��
};

/* ��ʼ��ջ������һ����ջS */
Status InitStack(SqStack &S)
{
    S.base = new ElemType[INIT_SIZE * sizeof(ElemType)];
    if (!S.base) // �����ڴ�ʧ��
        exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = INIT_SIZE;
}

/* Ԫ����ջ */
Status Push(SqStack &S, ElemType cha)
{
    if (S.top - S.base >= S.stacksize) // ��ջ������׷�ӿռ�
    {
        ElemType *Temp = new ElemType[(S.stacksize + INCREMENT) * sizeof(ElemType)];
        memcpy(Temp, S.base, S.stacksize * sizeof(ElemType));
        delete[] S.base;
        S.base = Temp;
        if (!S.base) // �����ڴ�ʧ��
            exit(OVERFLOW);
        S.top = S.base + S.stacksize;
        S.stacksize += INCREMENT;
    }

    *S.top = cha;
    S.top++; // ��e��ӵ�ջ��
    return OK;
}

/* ��ջ */
Status Pop(SqStack &S, ElemType &cha)
{
    if (S.top == S.base)
        return ERROR;
    S.top--;
    cha = *S.top;
}

/* ȡջ��Ԫ�أ�������ջ */
Status GetTop(SqStack &S, ElemType &cha)
{
    if (S.top == S.base)
        return ERROR;
    S.top--;
    cha = *S.top;
    S.top++;
    return OK;
}

/* ���ջ*/
Status ClearStack(SqStack &S)
{
    S.top = S.base;
    return OK;
}

/* ����ջ */
Status DestroyStack(SqStack &S)
{
    delete[] S.base;
    S.top = S.base = NULL;
    S.stacksize = 0;
    return OK;
}

/* ����ƥ�亯��(���ַ���dtr�е��ı���������ƥ����) */
int BracketMatch(char *str)
{
    SqStack S; // ����һ��ջ
    ElemType cha;
    ElemType *p = str;
    InitStack(S);
    while (*p != '\0') // �����ַ����е��ַ�
    {
        switch (*p)
        {
        case '{':
        case '[':
        case '(':
            Push(S, *p);
            break; // ������������һ�ɽ�ջ
        case '}':
            GetTop(S, cha);
            if (cha == '{') // ջ�������ų�ջ
                Pop(S, cha);
            else
                return ERROR;
            break;
        case ']':
            GetTop(S, cha);
            if (cha == '[') // ջ�������ų�ջ
                Pop(S, cha);
            else
                return ERROR;
            break;
        case ')':
            GetTop(S, cha);
            if (cha == '(') // ջ����Բ���ų�ջ
                Pop(S, cha);
            else
                return ERROR;
            break;
        }
        p++;
    }
    if (S.top == S.base)
        return OK;
    else
        return ERROR;
}

/*
    ������                        
    ������ƥ�������򷵻�OK��1���� 
    ����ƥ���쳣�����ERROR��0����
    �ڴ�����򷵻�OVERFLOW��-2����
 */
void main()
{
    ElemType str1[] = "{{[[]]()}}#";
    cout << "Check1:" << BracketMatch(str1) << endl;

    ElemType str2[] = "{{[[]])}}#";
    cout << "Check2:" << BracketMatch(str2) << endl;

    system("pause");
    return;
}
