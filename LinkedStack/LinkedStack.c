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

stack_entry Pop(Stack *ps)
{
    StackNode *pn = ps->top->next;
    stack_entry element;
    if(!Stack_Empty(&ps))
    {
        element = ps->top->value;
        free(ps->top);
        ps->top = pn;
        ps->stack_size--;
        return element;
    }
}

stack_entry Stack_mid_element(Stack *ps)
{
    return ps->mid->value;
}

void Traverse_Stack(Stack *ps)
{
    StackNode *pt = ps->top;
    while(pt != NULL)
    {
        printf("%d\t",pt->value);
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
        Push(arr[(ps->stack_size)-i],&Copy);
    }
}

int Check_String(char *str, Stack *ps)
{
    char i = 0, flag_1 = 0, flag_2 = 0, flag_3 = 0, c = 0;
    char e;
    StackNode *p_0 = ps->top->value;
    while(str[i++]);
    str[i-1] = '\0';
    i = 0;
    while(str[i]!= '\0')
    {
        Push(str[i],&ps);
        i++;
    }
    printf("the string pushed to the stack\n");
    i = 0;
    while(ps->stack_size)
    {
        e = Pop(&ps);
        ps->stack_size--;
        if(i = 0 && (e == '[' || e == '{' || e == '(' ) )
            return 0;
        else{
            if(e == ']' && (i || i == 0))
                flag_1 = i;
            if(e == '}' && (i || i == 0))
                flag_2 = i;
            if(e == ')' && (i || i == 0))
                flag_3 = i;
            if(e == '[')
            {
                if(c > flag_1)
                    flag_1 = 1;
                else return 0;
            }
            if(e == '{')
            {
                if(c > flag_2)
                    flag_2 = 1;
                else return 0;
            }
            if(e == '(')
            {
                if(c > flag_3)
                    flag_3 = 1;
                else return 0;
            }

        }
        i++;
        c++;
    }
    if(flag_1 && flag_2 && flag_3)
        return 1;
}
