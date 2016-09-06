/* 	MARCOS CESAR RIBEIRO DE CAMARGO - ICMC - USP
	N USP: 9278045 				DATA: 07/06/2016
	SCC0216 -  MODELAGEM COMPUTACIONAL EM GRAFOS
*/
#ifndef _LIST_H_
#define _LIST_H_

#include "utils.h"

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
Node* push_front(List*, void*);
/* Delete and return first element. */
void* pop_front(List*);
/* Add element at the end. */
Node* push_back(List*, void*);
/* Delete and return last element. */
void* pop_back(List*);
/* Delete an element. */
void erase(List*, Node*);
/* Remove element with specific value */
void* remove_list(List*, void*);
/* Search an element with specific value*/
void* find(List* l, void* key, int (*cmp)(void*, void*));


/* Functions to node. */

/* Return begin of list. */
Node* begin(List*);
/* Returns the element of node. */
void* get_element(Node*);
/* Retuns if has next node. */
bool has_next(Node*);
/* Get next node. */
Node* next(Node*);

#endif