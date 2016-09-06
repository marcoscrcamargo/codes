#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_
#include "utils.h"

typedef struct priority_queue Priority_Queue;

/* Create new priority queue. */
Priority_Queue* new_priority_queue(int (*cmp)(void*, void *));
/* Delete a priority queue. */
void delete_priority_queue(Priority_Queue* PQ, void (*free_void)(void*));
/* Test whether contaner is empty. */
bool PQ_empty(Priority_Queue* PQ);
/* Return size. */
int PQ_size(Priority_Queue* PQ);
/* Acess top element. */
void* PQ_top(Priority_Queue* PQ);
/* Insert element. */
void PQ_push(Priority_Queue* PQ, void* element);
/* Remove and return top element. */
void* PQ_pop(Priority_Queue* PQ);
/* Swao contents. */
void PQ_swap(Priority_Queue* PQ, void* origin, void* destiny);


#endif