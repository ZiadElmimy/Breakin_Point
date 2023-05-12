#include "Stack.h"

#if(Type_of_implementation == Array_based)
void Create_Stack(Stack *s)
{
    s->top = 0;
    s->stack_size = 0;
    s->mid = 0;
}

int Stack_Full(Stack *s)
{
    return (s->top-1)>= Max? 1:0;
}

void Push(stack_entry element, Stack *s)
{
    if(!Stack_Full(s))
    {
        s->data[s->top++] = element;
        s->stack_size++;
    }
    if(s->stack_size >= 3)
        s->mid = ((s->stack_size)/2);
}

int Stack_Empty(Stack *s)
{
    return (s->top) == 0? 1:0;
}

void Pop(stack_entry *element, Stack *s)
{
    if(!Stack_Empty(s))
        *element = s->data[--s->top];
    s->stack_size--;
}

stack_entry Stack_mid_element(Stack *s)
{
    return s->data[s->mid];
}

void Traverse_Stack(Stack *s)
{
    for(int i = s->top-1; i >= 0; i--)
    {
        printf("%d\t",s->data[i]);
    }
}

stack_entry Retrieve_Stack(Stack *s)
{
    return s->data[s->top-1];
}

void Destroy_Stack(Stack *s)
{
    s->top = 0;
    s->mid = 0;
    s->stack_size = 0;
}

void Copy_Stack(Stack *s, Stack *Copy)
{
    int i = 0;
    while(i < s->top)
    {
        Push(s->data[i++],Copy);
    }
}

int Stack_Size(Stack *s)
{
    return s->stack_size;
}

#elif(Type_of_implementation == Linked_based)
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

#endif
