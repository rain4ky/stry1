#include<iostream>
#define status int
#define MaxSize 100
using namespace std;
typedef int TelemType;

typedef struct BitNode
{
        TelemType data;
        struct BitNode *Lchild,*Rchild;
}BitNode,*BiTree;
status CreatBitree(BiTree &T);/*�������������ֶ�����ڵ�ֵ,��Ȼ���ǲ�����-1����ΪҪ�����˳�*/
status LRCBitree(BiTree &T,char temp);/*������������,��CreatBitree����*/
status PreorderTraverse(BiTree T);/*����������ݹ�*/
status InorderTraverse(BiTree T);/*����������ݹ�*/
status PostorderTraverse(BiTree T);/*����������ݹ�*/
int leafcount(BiTree T);
status DestoryBitre(BiTree &T);/*���ٶ�����*/

int main()
{
    BiTree T;
    CreatBitree(T);
    printf("\n����������Ϊ:\n");
    PreorderTraverse(T);
    printf("\n����������Ϊ:\n");
    InorderTraverse(T);
    printf("\n����������Ϊ:\n");
    PostorderTraverse(T);
    printf("\n�ڵ���Ϊ:%d",leafcount(T));
    DestoryBitre(T);
    return 0;
}

status CreatBitree(BiTree &T)
{
    int Val=-1;
    printf("������ڵ��ֵ(-1��ʾû��Ҷ�ڵ�):");
    scanf("%d",&Val);
    if(Val==-1)
    {
        T=NULL;
        return 1;
    }
    else
    {
        T=new BitNode;
        T->data=Val;
        LRCBitree(T,'L');
        LRCBitree(T,'R');
    }
    return 1;
}

status LRCBitree(BiTree &T,char temp)
{
    int Val=-1;
    BiTree *t;
    if(temp=='L')
    {
        printf("����%d�����ӽڵ�:",T->data);
        T->Lchild=new BitNode;
        t=&(T->Lchild);
    }
    else
    {
        printf("����%d�����ӽڵ�:",T->data);
        T->Rchild=new BitNode;
        t=&(T->Rchild);
    }
    scanf("%d",&Val);
    if(Val==-1)
    {
        *t=NULL;
        return 1;
    }
    else
    {
        (*t)->data=Val;
        LRCBitree(*t,'L');
        LRCBitree(*t,'R');
    }
    return 1;
}

status PreorderTraverse(BiTree T)
{
    if(T!=NULL)
    {
        printf("%d  ",T->data);
        PreorderTraverse(T->Lchild);
        PreorderTraverse(T->Rchild);
    }
    return 1;
}

status InorderTraverse(BiTree T)
{
    if(T!=NULL)
    {
        PreorderTraverse(T->Lchild);
        printf("%d  ",T->data);
        PreorderTraverse(T->Rchild);
    }
    return 1;
}

status PostorderTraverse(BiTree T)
{
    if(T!=NULL)
    {
        PreorderTraverse(T->Lchild);
        PreorderTraverse(T->Rchild);
        printf("%d  ",T->data);
    }
    return 1;
}

int leafcount(BiTree T)
{
    static int num=0;
    if(T)
    {
        num++;
        leafcount(T->Lchild);
        leafcount(T->Rchild);
    }
    return num;
}

status DestoryBitre(BiTree &T)
{
    if(T)
    {
        DestoryBitre(T->Lchild);
        DestoryBitre(T->Rchild);
        delete T;
    }
    return 1;
}