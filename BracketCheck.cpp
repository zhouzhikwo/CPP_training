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

/* 定义结构体 */
struct SqStack
{
    ElemType *base; // 栈底指针
    ElemType *top;  // 栈顶指针
    int stacksize;  // 当前栈长
};

/* 初始化栈，构造一个空栈S */
Status InitStack(SqStack &S)
{
    S.base = new ElemType[INIT_SIZE * sizeof(ElemType)];
    if (!S.base) // 分配内存失败
        exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = INIT_SIZE;
}

/* 元素入栈 */
Status Push(SqStack &S, ElemType cha)
{
    if (S.top - S.base >= S.stacksize) // 若栈满，则追加空间
    {
        ElemType *Temp = new ElemType[(S.stacksize + INCREMENT) * sizeof(ElemType)];
        memcpy(Temp, S.base, S.stacksize * sizeof(ElemType));
        delete[] S.base;
        S.base = Temp;
        if (!S.base) // 分配内存失败
            exit(OVERFLOW);
        S.top = S.base + S.stacksize;
        S.stacksize += INCREMENT;
    }

    *S.top = cha;
    S.top++; // 将e添加到栈顶
    return OK;
}

/* 出栈 */
Status Pop(SqStack &S, ElemType &cha)
{
    if (S.top == S.base)
        return ERROR;
    S.top--;
    cha = *S.top;
}

/* 取栈顶元素，但不出栈 */
Status GetTop(SqStack &S, ElemType &cha)
{
    if (S.top == S.base)
        return ERROR;
    S.top--;
    cha = *S.top;
    S.top++;
    return OK;
}

/* 清空栈*/
Status ClearStack(SqStack &S)
{
    S.top = S.base;
    return OK;
}

/* 销毁栈 */
Status DestroyStack(SqStack &S)
{
    delete[] S.base;
    S.top = S.base = NULL;
    S.stacksize = 0;
    return OK;
}

/* 括号匹配函数(对字符串dtr中的文本进行括号匹配检查) */
int BracketMatch(char *str)
{
    SqStack S; // 定义一个栈
    ElemType cha;
    ElemType *p = str;
    InitStack(S);
    while (*p != '\0') // 遍历字符串中的字符
    {
        switch (*p)
        {
        case '{':
        case '[':
        case '(':
            Push(S, *p);
            break; // 出现左括号则一律进栈
        case '}':
            GetTop(S, cha);
            if (cha == '{') // 栈顶左花括号出栈
                Pop(S, cha);
            else
                return ERROR;
            break;
        case ']':
            GetTop(S, cha);
            if (cha == '[') // 栈顶左方括号出栈
                Pop(S, cha);
            else
                return ERROR;
            break;
        case ')':
            GetTop(S, cha);
            if (cha == '(') // 栈顶左圆括号出栈
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
    主函数                        
    若括号匹配正常则返回OK（1）， 
    括号匹配异常则输出ERROR（0），
    内存溢出则返回OVERFLOW（-2）。
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
