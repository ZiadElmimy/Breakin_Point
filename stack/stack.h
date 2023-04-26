#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define Max 30
typedef int stack_entry;
typedef struct{
     stack_entry data[Max];
     int stack_size, top, mid;
}Stack;

void Create_Stack(Stack *s);
int Stack_Full(Stack *s);
void Push(stack_entry element, Stack *s);
stack_entry Stack_mid_element(Stack *s); //stack_size must be odd.
void Traverse_Stack(Stack *s);
stack_entry Retrieve_Stack(Stack *s);
void Destroy_Stack(Stack *s);
void Copy_Stack(Stack *s, Stack *Copy);
int Stack_Size(Stack *s);

#endif // STACK_H_INCLUDED
