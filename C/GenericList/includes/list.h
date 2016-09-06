#ifndef _LIST_H_
#define _LIST_H_

#include "utils.h"
#include "item.h"

typedef struct node Node;
typedef struct list List;

/* Creates a new list. */
List* new_list();
/* Delete the list. */
void delete_list(List*, void (*free_void)(void*));
/* Test whether contaainer is empty. */
bool empty(List*);
/* Return size. */
int size();
/* Acess first element. */
void* first(List*);
/* Acess last element. */
void* back(List*);
/* Insert element at beginnig. */
void push_front(List*, void*);
/* Delete and return first element. */
void* pop_front(List*);
/* Add element at the end. */
void push_back(List*, void*);
/* Delete and return last element. */
void* pop_back(List*);
/* Delete an element. */
void erase(List*, Node*);
/* Remove element with specific value */
void remove_list(List*, void*);
/* Search an element with specific value*/
void find(List* l, void* element);

#endif