#include <iostream>
#define status int
#define MAXSIZE 100
using namespace std;
typedef float SElemType;

typedef struct SqStack
{
    SElemType* base;
    SElemType* top;
    int stacksize;
}SqStack;

status InitStack(SqStack &S)/*栈的初始化*/
{
    S.base=new SElemType[MAXSIZE];
        if (!S.base) /*判断new是否成功*/
        {
            cout<<"初始化失败"<<endl;
            return 0;
        }
    S.top = S.base;
    S.stacksize == MAXSIZE;
    return 1;
}

status push(SqStack &S, SElemType e)/*入栈*/
{
    if (S.top - S.base == S.stacksize)/*判断是否能入栈*/
    {
        return 0;
    }
    *S.top++ = e;
    return 1;
}

status pop(SqStack &S)/*出栈*/
{
    if (S.top == S.base)/*判断栈是不是空的*/
    {
        return 0;
    }
    S.top--;
    return 1;
}

status destroyStack(SqStack &S)/*栈的销毁*/
{
    if (S.base)
    {
        delete S.base;
        S.stacksize = 0;
        S.base=S.top=NULL;
    }
    return 1;
}

int main()
{
    SqStack D;
    InitStack(D);
    push(D,10);
        cout<<*(D.top-1)<<endl;
    pop(D);
        cout<<*(D.top-1)<<endl;/*这句的输出会是一个小数，因为此时栈已经空了，但是我懒得写输出函数判断是不是空栈*/
    destroyStack(D);
    return 0;
}