#ifndef QUEUE_LIKE_STACK_H
#define QUEUE_LIKE_STACK_H
#include "Linked_queue.h"

void Append_like_Stack(Queue_Entry e, Queue *pq);
void Serve_like_Stack(Queue_Entry *pe, Queue *pq);
void Traverse_Queue_like_Stack(Queue *pq, void (*pf)(Queue_Entry));

#endif