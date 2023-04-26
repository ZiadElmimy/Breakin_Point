#include "stack.h"

void Create_Stack(Stack *s)
{
    s->top = 0;
    s->stack_size = 0;
    s->mid = 0;
}

int Stack_Full(Stack *s)
{
    return (s->top-1)>= Max?1:0;
}

void Push(stack_entry element, Stack *s)
{
    if(!Stack_Full(&s))
    {
        s->data[s->top++] = element;
        s->stack_size++;
    }
    if(s->stack_size >= 3)
        s->mid = ((s->stack_size)/2);
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
        Push(s->data[i++],&Copy);
    }
}

int Stack_Size(Stack *s)
{
    return s->stack_size;
}
