#include <stdlib.h>
#include <stdio.h>

#define DataType int

typedef struct node
{
    struct node *next;
    DataType data;
} Node, *LinkList;

void PrintLinkList(LinkList head)
{
    Node *p;
    int i = 0;
    p = head->next;
    while (p != NULL)
    {
        printf("%d=%d ", i++, p->data);
        p = p->next;
    }
    printf("\n==============\n");
}

LinkList InitiateLinkList()
{
    LinkList head;
    head = malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

int LengthLinkList(LinkList head)
{
    Node *p = head;
    int cnt = 0;
    while (p->next != NULL)
    {
        p = p->next;
        cnt++;
    }
    return cnt;
}

Node *GetLinkList(LinkList head, int i)
{
    Node *p;
    p = head->next;
    int c = 1;
    while (c < i && p != NULL)
    {
        p = p->next;
        c++;
    }
    if (i == c)
        return p;
    else
        return NULL;
}

int LocateLinkList(LinkList head, DataType x)
{
    Node *p = head;
    p = p->next;
    int i = 0;
    while (p != NULL && p->data != x)
    {
        i++;
        p = p->next;
    }
    if (p != NULL)
        return i + 1;
    else
        return 0;
}

void InsertLinkList(LinkList head, DataType x, int i)
{
    Node *p, *q;
    if (i == 1)
        q = head;
    else
        q = GetLinkList(head, i - 1);

    if (q == NULL)
    {
        printf("fail to  InsertLinkList");
    }
    else
    {
        p = malloc(sizeof(Node));
        p->data = x;
        p->next = q->next;
        q->next = p;
    }
}

void DeleteLinkList(LinkList head, int i)
{
    Node *p, *q;
    if (i == 1)
        q = head;
    else
        q = GetLinkList(head, i - 1);
    if (q != NULL && q->next != NULL)
    {
        p = q->next;
        q->next = p->next;
        free(p);
    }
    else
    {
        exit("not found pos to del");
    }
}

//remove duplicate data
void PurgeLinkList(LinkList head)
{
    Node *p, *q, *r;
    q = head->next;
    int i=0;
    while (q != NULL)
    {
        p = q;
         i=1;
        while (p->next != NULL)
        {
            if (p->next->data == q->data)
            {
                printf("del %d =%d \n",q->data,i++);
                r = p->next;
                p->next = r->next;
                free(r);
            }
            else
            {
                p = p->next;
            }
        }
        q = q->next;
    }
}

LinkList CreateLinkList()
{
    LinkList head;
    int x, i;
    head = InitiateLinkList();
    i = 1;
    scanf("%d", &x);
    while (x != 0)
    {
        InsertLinkList(head, x, i);
        i++;
        scanf("%d", &x);
    }
    return head;
}

LinkList CreateLinkList2()
{
    LinkList head;
    Node *q, *t;
    int x;
    head = malloc(sizeof(Node));
    q = head;

    scanf("%d", &x);
    while (x != 0)
    {
        t = malloc(sizeof(Node));
        t->data = x;
        q->next = t;
        q = t;
        scanf("%d", &x);
    }
    q->next = NULL;
    return head;
}

LinkList CreateLinkList3()
{
    LinkList head;
    Node *p;
    int x;
    head = malloc(sizeof(Node));
    head->next = NULL;
    scanf("%d", &x);
    while (x != 0)
    {
        p = malloc(sizeof(Node));
        p->data = x;
        p->next = head->next;
        head->next = p;
        scanf("%d", &x);
    }
    return head;
}

int main()
{
    // LinkList head = CreateLinkList();
    // PrintLinkList(head);
    // LinkList head2=CreateLinkList2();
    // PrintLinkList(head2);
    LinkList head3 = CreateLinkList2();
    PrintLinkList(head3);
    PurgeLinkList(head3);
    return 0;
}