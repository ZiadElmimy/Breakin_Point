#ifndef LINKED_QUEUE_H_INCLUDED
#define LINKED_QUEUE_H_INCLUDED
#include "Global.h"
typedef Customer Queue_Entry;
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

#endif // LINKED_QUEUE_H_INCLUDED
