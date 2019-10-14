#include <stdio.h>
#include <malloc.h>
#define SIZE 100
#define INCREMENT_SIZE 10
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status 代替了 int
typedef int ElemType;

typedef struct LNode
{
    int data;
    LNode *next;
} LNode, *LinkList;

void CreateList_L(LinkList &L, int n)
{
    //逆序输入n个元素的值，建立带表头节点的单链表L
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL; //            先建立一个带头结点的单链表
    int i;
    LinkList p;
    for (i = n; i > 0; --i)
    {
        p = (LinkList)malloc(sizeof(LNode)); //生成新节点
        printf("请输入元素值：");
        scanf("%d", &p->data); //输入元素值
        p->next = L->next;
        L->next = p; //插入到表头
    }
} //CreatList_L

Status ListInsert_L(LinkList &L, int i, ElemType e)
{
    //在带头结点的单链线性表L中第i个位置之前插入元素e
    LinkList p = L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        ++j;
    } //寻找第i-1个节点
    if (!p || j > i - 1)
        return ERROR;
    LinkList s;
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
} //ListInsert_L

Status ListDelete_L(LinkList &L, int i, ElemType &e)
{
    //在带头结点的单链表L中，删除第i个元素，并由e返回其值
    LinkList p;
    LinkList q;
    p = L;
    int j = 0;
    while (p->next && j < i - 1)
    { //寻找第i个节点，并令p指向其前驱
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1)
        return ERROR; //删除位置不合理
    q = p->next;
    p->next = q->next; //删除并释放节点
    e = q->data;
    free(q);
    return OK;

} //ListDelete_L

Status GetElem_L(LinkList L, int i, ElemType &e)
{
    //L为带都节点的单链表的指针
    //当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
    LinkList p;
    p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR;
    e = p->data;
    return OK;
} //GetElem_L

void printL(LinkList L)
{
    LinkList p;
    p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
    LinkList L;
    CreateList_L(L, 4); //创建一个单链表，并指定单链表的长度。
    printL(L);
    printf("\n");
    int insert;
    printf("请输入要插入的元素：");
    scanf("%d", &insert);
    ListInsert_L(L, 1, insert);
    printf("插入后的链表元素为：");
    printL(L);
    printf("\n");
    int a;
    int i;
    printf("请输入要删除第几个元素：");
    scanf("%d", &i);
    ListDelete_L(L, i, a);
    printL(L);
}