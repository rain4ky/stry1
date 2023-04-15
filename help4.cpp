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
status CreatBitree(BiTree &T);/*二叉树建立，手动输入节点值,虽然但是不能是-1，因为要用来退出*/
status LRCBitree(BiTree &T,char temp);/*建立左右子树,由CreatBitree调用*/
status PreorderTraverse(BiTree T);/*左序遍历，递归*/
status InorderTraverse(BiTree T);/*中序遍历，递归*/
status PostorderTraverse(BiTree T);/*后序遍历，递归*/
int leafcount(BiTree T);
status DestoryBitre(BiTree &T);/*销毁二叉树*/

int main()
{
    BiTree T;
    CreatBitree(T);
    printf("\n左序遍历结果为:\n");
    PreorderTraverse(T);
    printf("\n中序遍历结果为:\n");
    InorderTraverse(T);
    printf("\n后序遍历结果为:\n");
    PostorderTraverse(T);
    printf("\n节点数为:%d",leafcount(T));
    DestoryBitre(T);
    return 0;
}

status CreatBitree(BiTree &T)
{
    int Val=-1;
    printf("请输入节点的值(-1表示没有叶节点):");
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
        printf("输入%d的左子节点:",T->data);
        T->Lchild=new BitNode;
        t=&(T->Lchild);
    }
    else
    {
        printf("输入%d的右子节点:",T->data);
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
        InorderTraverse(T->Lchild);
        printf("%d  ",T->data);
        InorderTraverse(T->Rchild);
    }
    return 1;
}

status PostorderTraverse(BiTree T)
{
    if(T!=NULL)
    {
        PostorderTraverse(T->Lchild);
        PostorderTraverse(T->Rchild);
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
