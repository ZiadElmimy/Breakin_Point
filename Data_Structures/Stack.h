#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define Array_based 0
#define Linked_based 1
#define Type_of_implementation Linked_based

#if(Type_of_implementation == Array_based)
#define Max 30
typedef int stack_entry;
typedef struct{
     stack_entry data[Max];
     int stack_size, top, mid;
}Stack;

void Create_Stack(Stack *s);
int Stack_Full(Stack *s);
void Push(stack_entry element, Stack *s);
int Stack_Empty(Stack *s);
void Pop(stack_entry *element, Stack *s);
stack_entry Stack_mid_element(Stack *s); //stack_size must be odd.
void Traverse_Stack(Stack *s);
stack_entry Retrieve_Stack(Stack *s);
void Destroy_Stack(Stack *s);
void Copy_Stack(Stack *s, Stack *Copy);
int Stack_Size(Stack *s);

#elif(Type_of_implementation == Linked_based)
typedef Customer stack_entry;
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
int Stack_Empty(Stack *ps);
void Pop(stack_entry *pe, Stack *ps);
stack_entry Stack_mid_element(Stack *ps); //stack_size must be odd.
void Traverse_Stack(Stack *ps, void (*pf)(Queue_Entry));
stack_entry Retrieve_Stack(Stack *ps);
int Stack_Size(Stack *ps);
void Destroy_Stack(Stack *ps);
void Copy_Stack(Stack *ps, Stack *Copy);

#endif


#endif // STACK_H_INCLUDED
