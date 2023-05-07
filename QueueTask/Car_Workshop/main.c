#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Global.h"
#include "LinkedStack.h"
#include "Linked_Queue.h"
Customer customer;
void Add_new_Customer(Queue *pq)
{
    printf("enter the your name: ");
    scanf(" %[^\n]c",&customer.Name);
    printf("enter your ID: ");
    scanf(" %d",&customer.ID);
    printf("enter the car's year model: ");
    scanf(" %hd",&customer.Year_model);
}
void Display_Customer_List(Queue_Entry c)
{
    printf("Name: %s\t",c.Name);
    printf("Year model: %hd\t",c.Year_model);
    printf("ID: %d\n",c.ID);
    printf("-------------------------------\n");

}
int main()
{
    Queue q;
    Stack s;
    volatile int choice = 0, Size = 0;
    InitializeQueue(&q);
    Create_Stack(&s);
    printf("this is the control panel for the car workshop\n");
        printf("1\)Add a new customer\n");
        printf("2\)Serve a customer\n");
        printf("3\)How many customers are waiting\n");
        printf("4\)Display Customers info\n");
        printf("5\)Display Customers info in most recent order\n");
        printf("6\)Exit");
        printf("\n");

    while(1)
    {
        printf("\nenter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
          case 1:
              Add_new_Customer(&q);
              Append(customer,&q);
              Push(customer,&s);
              break;
          case 2:
              Serve(&customer,&q);
              Pop(&customer,&s);
              printf("there is a customer served");
              break;
          case 3:
              Size = Stack_Size(&s);
              printf("there are %d customers",Size);
              break;
          case 4:
              printf("customers info...\n");
              Traverse_Queue(&q,Display_Customer_List);
              break;
          case 5:
              printf("customers info in the other order...\n");
              Traverse_Stack(&s,Display_Customer_List);
              break;
          case 6:
              printf("Thanks");
              goto Finish;
              break;
          default:
              printf("not valid try another choice");
              break;
        }
    }
    Finish:
         return 0;
}
