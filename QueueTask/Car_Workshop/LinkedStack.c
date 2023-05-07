#include <stdlib.h>
#include "LinkedStack.h"

void Create_Stack(Stack *ps)
{
    ps->top = NULL;
    ps->stack_size = 0;
    ps->mid = ps->top;
}

int Stack_Full(Stack *ps)
{
    return 0;
}

void Push(stack_entry element, Stack *ps)
{
    StackNode *pn;
    static int c = 0;
    if(!Stack_Full(&ps))
    {
        pn = (StackNode*)malloc(sizeof(StackNode));
        pn->value = element;
        pn->next = ps->top;
        ps->top = pn;
        ps->stack_size++;
        if(ps->stack_size >= 3)
        {
            ps->mid = ps->top;
            for(int i = 0; i < (ps->stack_size/2); i++)
            {
                ps->mid = ps->mid->next;
            }
        }
    }

}

int Stack_Empty(Stack *ps)
{
    if(ps->top == NULL)
        return 1;
    else return 0;
}

void Pop(stack_entry *pe, Stack *ps)
{
    StackNode *pn = ps->top->next;
    if(!Stack_Empty(&ps))
    {
        *pe = ps->top->value;
        free(ps->top);
        ps->top = pn;
        ps->stack_size--;

    }
}

stack_entry Stack_mid_element(Stack *ps)
{
    return ps->mid->value;
}

void Traverse_Stack(Stack *ps, void (*pf)(stack_entry))
{
    StackNode *pt = ps->top;
    while(pt != NULL)
    {

        (*pf)(pt->value);
        pt = pt->next;
    }
}

stack_entry Retrieve_Stack(Stack *ps)
{
    return ps->top->value;
}

int Stack_Size(Stack *ps)
{
    return ps->stack_size;
}

void Destroy_Stack(Stack *ps)
{
    StackNode *pn;
    while(pn)
    {
        pn = ps->top->next;
        free(ps->top);
        ps->top = pn;
    }
    ps->top = NULL;
    ps->mid = ps->top;
    ps->stack_size = 0;
}

void Copy_Stack(Stack *ps, Stack *Copy)
{
    stack_entry arr[ps->stack_size];
    StackNode *pn = ps->top;
    for(int i = 0; i < ps->stack_size; i++)
    {
        arr[i] = pn->value;
        pn = pn->next;
    }
    printf("the element while copying...\n");
    for(int i = 0; i < ps->stack_size; i++)
    {
        printf("%d\t",arr[i]);
    }
    for(int i = 0; i < ps->stack_size; i++)
    {
        Push(arr[(ps->stack_size-1)-i],Copy);
    }
}

