#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define Array_based 0
#define Linked_based 1
#define Type_of_implementation Array_based

#if(Type_of_implementation == Array_based)
#define Max 10
typedef int Queue_Entry;
typedef struct Queue
{
    int Front;
    int Rear;
    int Size;
    Queue_Entry Entry[Max];
}Queue;

// accessing mechanisms
void InitializeQueue(Queue *pq);
void Append(Queue_Entry element,Queue *pq);
void Serve(Queue_Entry *pe, Queue *pq);
int QueueIsFull(Queue *pq);
int QueueIsEmpty(Queue *pq);
int QueueSize(Queue *pq);
void TraverseQueue(Queue *pq , void(*pf)(Queue_Entry));
void QueueClear(Queue *pq);

#elif(Type_of_implementation == Linked_based)
typedef int Queue_Entry;
typedef struct queueNode
{
    Queue_Entry value;
    struct queueNode *pointer;
}QueueNode;
typedef struct _Queue
{
    QueueNode *Front;
    QueueNode *Rear;
    int Size;
}Queue;
void InitializeQueue(Queue *pq);
int Pre_Append(Queue *pq);
void Append(Queue_Entry e,Queue *pq);
int Pre_Serve(Queue *pq);
void Serve(Queue_Entry *pe, Queue *pq);
int Queue_Size(Queue *pq);
void QueueClear(Queue *pq);
void Traverse_Queue(Queue *pq, void (*pf)(Queue_Entry));

#endif

#endif // QUEUE_H_INCLUDED
