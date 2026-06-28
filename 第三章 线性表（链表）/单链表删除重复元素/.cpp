#include <malloc.h>
#include <stdio.h>
typedef int ElemType;
typedef struct node
{    ElemType data;        //数据域
    struct node *next;    //指针域
} SLinkNode;                //单链表类型
void InitList(SLinkNode *&L)                //L作为引用型参数
{    L=(SLinkNode *)malloc(sizeof(SLinkNode));    //创建头结点*L
    L->next=NULL;
}
void DestroyList(SLinkNode *&L)
{    SLinkNode *pre=L,*p=pre->next;
    while (p!=NULL)
    {    free(pre);
        pre=p; p=p->next;    //pre、p同步后移
    }
    free(pre);
}
int InsElem(SLinkNode *&L,ElemType x,int i)    //插入结点值为x的结点
{    int j=0;
    SLinkNode *p=L,*s;
    if (i<=0) return 0;            //参数i错误返回0
    while (p!=NULL && j<i-1)    //查找第i-1个结点*p
    {    j++;
        p=p->next;
    }
    if (p==NULL)
        return 0;                //未找到第i-1个结点时返回0
    else                        //找到第i-1个结点*p
    {    s=(SLinkNode *)malloc(sizeof(SLinkNode));
        s->data=x;                //创建存放元素x的新结点*s
        s->next=p->next;        //将*s结点插入到*p结点之后
        p->next=s;
        return 1;                //插入运算成功,返回1
    }
}
void createL(SLinkNode *&L,ElemType a[],int n)
{
    for(int i=1;i<=n;i++)
    InsElem(L,a[i-1],i);    
}
void DispList(SLinkNode *L)        //输出单链表
{    SLinkNode *p=L->next;
    while (p!=NULL)
    {    printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void deletF(SLinkNode *&L,ElemType x) //删除所有x
{
    
SLinkNode *p = L->next; // p指向第一个数据结点
SLinkNode *pre = L; // pre指向p的前驱（头结点）
while (p != NULL)
{
if (p->data == x)
{
pre->next = p->next; // 跳过p结点，删除p
free(p); // 释放p的内存
p = pre->next; // p指向下一个结点（原p的下一个结点）
}
else
{
pre = p; // pre后移
p = p->next; // p后移
}
}

}
int main()
{
    SLinkNode *L;
    InitList(L);
    ElemType x=2;
    ElemType a[]={3,2,5,6,2,9};
    int n=sizeof(a)/sizeof(a[0]);
    createL(L,a,n);
    DispList(L)    ;
//    scanf("%d",&x);
    deletF(L,x);
    DispList(L)    ;
    return 0;
}