#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MaxSize 50
#define ElemtType int
typedef struct clist
{
    ElemtType data[MaxSize];
    int length;
} SeqList;

bool ListInsert(SeqList *L, int i, ElemtType e)
{
    if (i < 1 || i > L->length + 1)
        return false;

    if (L->length >= MaxSize)
        return false;

    for (int j = L->length; j >= i; j--)
        L->data[j] = L->data[j - 1];

    L->data[i - 1] = e;
    L->length++;
    return true;
}

int main()
{
    printf("%s \n","main fun");
    return 0;

}
