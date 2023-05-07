#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
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

#endif // QUEUE_H_INCLUDED
