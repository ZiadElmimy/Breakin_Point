#include "Queue.h"
#if(Type_of_implementation == Array_based)
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

#elif(Type_of_implementation == Linked_based)
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

#endif
