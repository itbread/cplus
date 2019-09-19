#include <stdlib.h>
#include <stdio.h>

#define DataType int

//顺序表数据结构
typedef struct node
{
    struct Node *next;
    DataType data;
} Node, *Linklist;

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
    int i = 0;
    p = head->next;
    while (p != NULL)
    {
        p = p->next;
        printf("%d=%d ", i++, p->data);
    }
    printf("%==============\n");
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
    p = head->next;
    int pos = 0;

    while (pos < i && p != NULL)
    {
        p = p->next;
        pos++;
    }
    if (p != NULL && p->next != NULL)
    {
        q = malloc(sizeof(Node));
        q->data = x;
        q->next = p->next;
        p->next = q;
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

int GetNode(Linklist head, int i)
{
    int cnt = 0;
    Node *p;
    p = head->next;
    while (p != NULL && p->next != NULL && cnt < i)
    {
        p = p->next;
        cnt++;
    }
    if (cnt < i)
    {
        printf("not found\n");
        return NULL;
    }

    return p;
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
    Insert(list, 1, 1);
    return 0;
}
