#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#define Array_based 0
#define Linked_based 1
#define Type_of_implementation Linked_based

#if(Type_of_implementation == Array_based)
#define Max 100
typedef int List_Entry;
typedef struct{
     List_Entry data[Max];
     int Size;
}List;

#elif(Type_of_implementation == Linked_based)
typedef int List_Entry;
typedef struct listnode
{
    List_Entry value;
    struct listnode *pointer;
}ListNode;

typedef struct _List
{
    ListNode *Head;
    int Size;
}List;

#endif

void Create_List(List *l);
int List_Full(List *l);
void Insert(int pos, List_Entry *element, List *l);
int List_Empty(List *l);
void Delete(int pos, List_Entry *element, List *l);
int List_Size(List *l);
void Retrieve_List(int pos, List_Entry *element, List *l);
void Replace(int pos, List_Entry *element, List *l);
void Traverse_List(List *l, void (*pf)(List_Entry));
void Destroy_List(List *l);

#endif // LIST_H_INCLUDED
