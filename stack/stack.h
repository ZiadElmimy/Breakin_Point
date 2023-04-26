#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define Max 30
typedef int stack_entry;
typedef struct{
     stack_entry data[Max];
     int stack_size, top;
}Stack;


#endif // STACK_H_INCLUDED
