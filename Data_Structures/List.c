#include "List.h"

#if(Type_of_implementation == Array_based)
void Create_List(List *l)
{
    l->Size = 0;
}

int List_Full(List *l)
{
    return l->Size == Max;
}

void Insert(int pos, List_Entry *element, List *l)
{
    for(int i = l->Size-1; i >= p; i--)
           l->data[i+1] = l->data[i];
    l->data[pos] = *element;
    l->Size++;
}

int List_Empty(List *l)
{
    return !l->Size;
}

void Delete(int pos, List_Entry *element, List *l)
{
    *element = l->data[pos];
    for(int i = pos+1; i <= l->Size-1; i++)
        l->data[i-1] = l->data[i];
    l->Size--;
}

int List_Size(List *l)
{
    return l->Size;
}

void Retrieve_List(int pos, List_Entry *element, List *l)
{
    *element = l->data[pos];
}

void Replace(int pos, List_Entry *element, List *l)
{
    l->data[pos] = *element;
}

void Traverse_List(List *l, void (*pf)(List_Entry))
{
    for(int i = 0; i <= l->Size; i++)
        (*pf)(l->data[i]);
}

void Destroy_List(List *l)
{
    l->Size = 0;
}

#elif(Type_of_implementation == Linked_based)
void Create_List(List *l)
{
    l->Head = NULL;
    l->Size = 0;
}

int List_Full(List *l)
{
    return 0;
}

int List_Empty(List *l)
{
    return !l->Head;
}

int List_Size(List *l)
{
    return l->Size;
}

void Insert(int pos,List_Entry e,List *l)
{
    ListNode *p, *q;
    int i;

   p = (ListNode*) malloc(sizeof(ListNode))
        p->value = e;
    p->pointer = NULL;

    if(pos == 0)
    {
        l->Head = p;
    }
    else
    {
        for(q=l->Head, i = 0; i < pos-1; i++)
        {
            q= q->pointer;

        }
        p->pointer = q->pointer;
        q->pointer = p;
    }
    l->Size++;

}

void Delete(int pos,List_Entry *pe,List *l)
{
    ListNode *q, *tmp;
    int i;
    if(pos == 0)
    {
        *pe = l->Head->value;
        tmp = l->Head->pointer;
        free(l->Head);
        l->Head = tmp;
    }
    else
    {
        for(q=l->Head, i = 0; i < pos-1; i++)
        {
            q=q->pointer;
        }
        *pe = q->pointer->value;
        tmp = q->pointer->pointer;
        free(q->pointer);
        q->pointer = tmp;
        l->Size--;
    }
}

void Retrieve_List(int pos, List_Entry *pe, List *l)
{
    ListNode *q;
    int i;
    for(q=l->Head, i = 0; i<pos;i++)
    {
        q = q->pointer;
    }
    *pe = q->value;
}

void Replace(int pos, List_Entry e, List *l)
{
    ListNode *q;
    int i;
    for(q=l->Head, i = 0; i < pos; i++)
    {
        q = q->pointer;
    }
    q->value = e;
}

void Traverse_List(List *l, void (*pf) (List_Entry))
{
    ListNode *pn = l->Head;
    while(pn)
    {
        (*pf)(pn->value);
        pn = pn->pointer;
    }
}

void Destroy(List *l)
{
    ListNode *q;
    while(l->Head)
    {
        q = l->Head->pointer;
        free(l->Head);
        l->Head = q;
    }
    l->Head = NULL;
    l->Size = 0;
}

#endif
