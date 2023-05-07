#include <stdio.h>
#include <stdlib.h>
#include "Linked_queue.h"

void InitializeQueue(Queue *pq)
{
    pq->Front = NULL;
    pq->Rear = NULL;
    pq->Size = 0;
}
int Pre_Append(Queue *pq)
{
    return 0;
}
void Append(Queue_Entry e,Queue *pq)
{
    QueueNode *pn = (QueueNode*)malloc(sizeof(QueueNode));
    pn->pointer = NULL;
    pn->value = e;
    if(!pq->Rear)
        pq->Front = pn;
    else
        pq->Rear->pointer = pn;
    pq->Rear = pn;
    pq->Size++;
}
int Pre_Serve(Queue *pq)
{
    return !pq->Rear;
}
void Serve(Queue_Entry *pe, Queue *pq)
{
    QueueNode *pn = pq->Front;
    *pe = pn->value;
    pq->Front = pn->pointer;
    free(pn);
    if(!pq->Front)
        pq->Rear = NULL;
    pq->Size--;
}
int Queue_Size(Queue *pq)
{
    return pq->Size;
}
void QueueClear(Queue *pq)
{
   QueueNode *pn = pq->Front;
   while (pn)
   {
       pq->Front = pn->pointer;
       free(pn);
   }
   pq->Front = NULL;
   pq->Rear = NULL;
   pq->Size = 0;
}
void Traverse_Queue(Queue *pq, void (*pf)(Queue_Entry))
{
    QueueNode *pn = pq->Front;
    while(pn)
    {
        (*pf)(pn->value);
        pn = pn->pointer;
    }
}
