#include <stdio.h>
#include <stdlib.h>
#include "Queue_like_Stack.h"

void Append_like_Stack(Queue_Entry e, Queue *pq)
{
    QueueNode *pn = (QueueNode*) malloc(sizeof(QueueNode));
    pn->value = e;
    if(!pq->Front)
    {
        pq->Front = pn;
        pq->Front->pointer = NULL;
    }
    else
        pn->pointer = pq->Rear;
    pq->Rear = pn;
    pq->Size++;
}
void Serve_like_Stack(Queue_Entry *pe, Queue *pq)
{
    QueueNode *pn = pq->Rear;
    *pe = pn->value;
    pn = pn->pointer;
    free(pq->Rear);
    pq->Rear = pn;
    if(!pn->pointer)
       pq->Rear = NULL;
    pq->Size--;   
}
void Traverse_Queue_like_Stack(Queue *pq, void (*pf)(Queue_Entry))
{
    QueueNode *pn = pq->Rear;
    while(pn)
    {
        (*pf)(pn->value);
        pn = pn->pointer;
    }
}
