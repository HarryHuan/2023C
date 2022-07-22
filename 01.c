#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define IniSize 10 // 默认的最大长度
typedef struct
{
    int *data;
    int MaxSize;
    int length;
} SeqList;

void InitList(SeqList *L)
{
    L->data = (int *)malloc(IniSize * sizeof(int));
    L->length = 0;
    L->MaxSize = IniSize;
}

void IncreaseSize(SeqList *L, int len)
{
    int *p = L->data;
    L->data = (int *)malloc((L->MaxSize + len) * sizeof(int));
    for (int i = 0; i < L->length; i++)
    {
        L->data[i] = p[i];
    }
    L->MaxSize = L->MaxSize + len;
    free(p);
}

bool ListInsert(SeqList *L, int i, int e)
{
    if (i < 1 || i > L->length + 1)
    {
        return false;
    }
    if (L->length >= IniSize)
    {
        return false;
    }
    for (int j = L->length; j >= i; j--)
    {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;
    return true;
}

bool ListDelete(SeqList *L, int i, int *e)
{
    if (i < 1 || i > L->length)
    {
        return false;
    }
    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++)
    {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return true;
}

int main()
{
    SeqList L;
    InitList(&L);
    // printf("%d\n", L.length);
    ListInsert(&L, 1, 5);
    // printf("%d\n", L.data[0]);

    int e = -1;
    if (ListDelete(&L, 1, &e))
    {
        printf("已删除第1个元素，删除元素值为%d\n", e);
    }
    else
    {
        printf("位序i不合法，删除失败\n");
    }

    return 0;
}