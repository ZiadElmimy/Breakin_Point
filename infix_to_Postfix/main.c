#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main()
{
    Stack s,t;
    Create_Stack(&s);

    Create_Stack(&t);
    char *expression = "12*4%3-1";
    char arr[10] = {0};
    volatile int c = 0, i = 0;
    while(expression[i] != 0)
    {
        Push(*(expression+i),&s);
        if(s.data[i] == '+'|| s.data[i] == '-'|| s.data[i] == '*'|| s.data[i] == '/'|| s.data[i] == '%')
        {
            arr[c] = s.data[i];
            c++;
        }
        i++;
    }
    printf("the expression is: ");
    Traverse_Stack(&s);

    printf("\nthe expression prepared, and the size of the first stack = %d\n",Stack_Size(&s));
    printf("the elements of the array are: ");
    for(int i = 0 ; i <= c; i++)
        printf("%c ",arr[i]);

    for(int i = 0; i < s.stack_size; i++)
    {
        if(s.data[i] == '+'|| s.data[i] == '-'|| s.data[i] == '*'|| s.data[i] == '/'|| s.data[i] == '%'|| s.data[i] == '('|| s.data[i] == ')')
            continue;
        else Push(s.data[i],&t);
    }
    for(int i = 0 ; i <= c; i++)
        Push(arr[i], &t);
    printf("\nthe expression is done, and the size of the final stack = %d\n",Stack_Size(&t));
    printf("the postfix expression: ");
    Traverse_Stack(&t);
    return 0;
}
