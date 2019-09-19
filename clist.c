#include <stdlib.h>
#include <stdio.h>

#define DataType int

//顺序表数据结构
typedef struct node
{
    Node *next;
    DataType data;
} Node, *Linklist;

Linklist InitLinklist()
{
    Linklist head;
    head = malloc(sizeof(Node));
    head->next = NULL;
    return head;
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
    Node *p;
    p = head->next;
    int pos = 0;
    if (i == 1)
    {
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
    if (p->data != x)
    {
    }
}

void Delete(Linklist head, DataType x)
{
    Node *p;
    p = head->next;
}
