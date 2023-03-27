#include<iostream>
using namespace std;
#define Status int
#define Elemtype int

class SqList
{
    private:
        int * elem;
        int Length;
        int size;
    public:
        Status InitList_Sq(SqList &l);//初始化，长度为10
        void DestoryList(SqList &l);//销毁顺序表
        void ClearList(SqList &l);//清空顺序表
        int GetLenth(SqList &l);//求长度
        int Isempty(SqList &l);//判断是否为空，空返回1
        int GetElem(SqList &l,int i,Elemtype &e);//获取元素
        int LocateElem(SqList &l,Elemtype e);//查找e    
        Status ListInsert_Sq(SqList &l,int i,Elemtype e);//插入e
        Status ListDelete_Sq(SqList &l,int i);//删除第i个元素
};

Status SqList::InitList_Sq(SqList &l)
{
    l.elem=new Elemtype[10];
        if(!l.elem)cout<<"wrong!"<<endl;//如果分配内存失败则报错
    l.Length=0;
    l.size=10;
    return 1;
}
void SqList::DestoryList(SqList &l)
{
    if(l.elem) delete[]l.elem;
    l.elem=NULL;
}
void SqList::ClearList(SqList &l)
{
    l.Length=0;
}
int SqList::GetLenth(SqList &l)
{
    return l.Length;
}
int SqList::Isempty(SqList &l)
{
    if(l.GetLenth(l)==0)return 1;
    return 0;
}
int SqList::GetElem(SqList &l, int i, Elemtype &e)
{
    if(i<1 || i>l.Length)return 0;
    e=l.elem[i-1];
    return 1;
}
int SqList::LocateElem(SqList &l, Elemtype e)
{
    for(int i=0;i<l.Length;i++)
    {
        if(l.elem[i]==e)return i+1;
    }
    return 0;
}
Status SqList::ListInsert_Sq(SqList &l, int i, Elemtype e)
{
    if(i<1 || i>l.Length+1)return 0;
    if(l.Length>=l.size)return 0;
    for(int j=l.Length-1;j>i-1;j--)
    {
        l.elem[j+1]=l.elem[j];
    }
    l.elem[i-1]=e;
    l.Length++;
    return 1;
}
Status SqList::ListDelete_Sq(SqList &l, int i)
{
    if(i<1 || i>l.Length+1)return 0;
    for(int j=i;j<=l.Length-1;j++)
    {
        l.elem[j-1]=l.elem[j];
    }
    l.Length--;
    return 1;
}

int main()
{
    SqList l;
    l.InitList_Sq(l);
    for(int i=1;i<=10;i++)
    {
        l.ListInsert_Sq(l,i,i);
    }
    cout<<l.LocateElem(l,3)<<endl;
}