#include <stdio.h>
#include<stdlib.h>
typedef struct Lnode
{
    int No;//这个环存的数据
    struct Lnode * next;//下一环的位置
}Lnode;

void SetLink(Lnode *h, int n )
{
    Lnode *p=NULL,*q=NULL;
    int i;
    for( i=1; i<n; i++)
    {
        p =(Lnode *)malloc(sizeof(Lnode));
        p->No = i+1;
        p->next = NULL;
        if( h->next == NULL )
        {
            h->next = p;
            q = p;
        }
        else
        {
            q->next = p;
            q = q->next;
        }
    }
}

Lnode * initlist(int len)
{
    Lnode * head = NULL;
    head=(Lnode *)malloc(sizeof(Lnode));
    head->No=1;
    head->next=NULL;
    SetLink(head,len);
    return head;
}

int listget(Lnode * head,int n)
{
    Lnode * p=head;
    int i=1;
    while(i<n)
    {
        p=p->next;
        i++;
    }
    return p->No;
}

int main()
{
    int len;Lnode * head = NULL;
    printf("init your list\nhow long?");
    scanf("%d",&len);
    head=initlist(len);
    printf("the second number in the list is:%d",listget(head,2));
    return 0;
}