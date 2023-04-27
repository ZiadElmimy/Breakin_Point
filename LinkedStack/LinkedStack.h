#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED
typedef int stack_entry;
typedef struct node{
   stack_entry value;
   struct node *next;
}StackNode;

typedef struct{
   StackNode *top;
   int stack_size;
   StackNode *mid;
}Stack;

void Create_Stack(Stack *ps);
int Stack_Full(Stack *ps);
void Push(stack_entry element, Stack *ps);
stack_entry Stack_mid_element(Stack *ps); //stack_size must be odd.
void Traverse_Stack(Stack *ps);
stack_entry Retrieve_Stack(Stack *ps);
int Stack_Size(Stack *ps);
void Destroy_Stack(Stack *ps);
void Copy_Stack(Stack *ps, Stack *Copy);
#endif // LINKEDSTACK_H_INCLUDED
