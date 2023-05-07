#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
void InitializeQueue(Queue *pq)
{
    pq->Front = 0;
    pq->Rear = -1;
    pq->Size = 0;
}
void Append(Queue_Entry element,Queue *pq)
{
   pq->Rear = (pq->Rear+1) % Max;
   pq->Entry[pq->Rear] = element;
   pq->Size++;

}
void Serve(Queue_Entry *pe, Queue *pq)
{
    *pe = pq->Entry[pq->Front];
    pq->Front = (pq->Front+1) % Max;
    pq->Size--;
}
int QueueIsFull(Queue *pq)
{
    return pq->Size == Max;
}
int QueueIsEmpty(Queue *pq)
{
    return !pq->Size;
}
int QueueSize(Queue *pq)
{
    return pq->Size;
}
void TraverseQueue(Queue *pq , void(*pf)(Queue_Entry))
{
    int pos, s;
    for (pos = pq->Front, s = 0; s<pq->Size; s++)
    {
        (*pf)(pq->Entry[pos]);
        pos = (pos+1) % Max;
    }
}
void QueueClear(Queue *pq)
{
    pq->Front = 0;
    pq->Rear = -1;
    pq->Size = 0;
}
