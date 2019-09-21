#include <stdlib.h>
#include <stdio.h>

#define DataType int

//顺序表数据结构
typedef struct node
{
    struct Node *next;
    DataType data;
} Node, *Linklist;

Node *GetNode(Linklist head, int i);

Linklist InitLinklist()
{
    Linklist head;
    head = malloc(sizeof(Node));
    head->next = NULL;
    head->data = 0;
    return head;
}

void NodePrint(Linklist head)
{
    Node *p;
    int i = 1;
    p = head->next;
    while (p != NULL)
    {
        printf("index%d=%d ", i++, p->data);
        p = p->next;
    }
    printf("\n==============\n");
}

int GetLength(Linklist head)
{
    int cnt = 0;
    Node *p;
    p = head->next;
    while (p != NULL)
    {
        p = p->next;
        cnt++;
    }

    return cnt;
}

void Insert(Linklist head, DataType x, int i)
{
    Node *p, *q;
    if (i == 1)
        q = head;
    else
        q = GetNode(head, i - 1);

    if (q == NULL)
        printf("not found node\n");
    else
    {
        p = malloc(sizeof(Node));
        p->data = x;
        p->next = q->next;
        q->next = p;
        printf("Insert success\n");
    }
}

int GetPos(Linklist head, DataType x)
{
    int i = 0;
    Node *p;
    p = head->next;
    while (p->data != x && p->next != NULL)
    {
        p = p->next;
        i++;
    }
    if (p != NULL)
    {
        printf("GetPos success\n");
        return i;
    }

    return 0;
}

Node *GetNode(Linklist head, int i)
{
    int cnt = 1;
    Node *p;
    p = head->next;
    while (p != NULL && cnt < i)
    {
        p = p->next;
        cnt++;
    }
    printf("cnt=%d i=%d\n", cnt, i);
    if (cnt == i)
        return p;
    else
        return NULL;
}

void Delete(Linklist head, DataType x)
{
    Node *p, *q;
    p = head->next;
    q = p;
    while (p != NULL && p->next != NULL)
    {
        if (p->data == x)
        {
            q = p;
            q->next = p->next;
            free(p);
            printf("Delete success\n");
            break;
        }

        p = p->next;
    }
}

int main()
{
    Linklist list = InitLinklist();
    NodePrint(list);
    Insert(list, 2, 1);
    NodePrint(list);
    Insert(list, 4, 2);
    Insert(list, 6, 3);
    NodePrint(list);
    return 0;
}
