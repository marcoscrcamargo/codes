#include "list.h"
#include "utils.h"
#include <stdlib.h>

struct node{
	Node* next;
	Node* previous;

	void* element;
};

struct list{
	Node* begin;
	Node* end;

	int size;

};

/* Creates a new list. */
List* new_list(){
	List* l = NULL;
	l = (List *) malloc (sizeof(List));

	if(l != NULL){
		l->begin = NULL;
		l->end = NULL;
		l->size = 0;
	}

	return l;
}

/* Delete the list. */
void delete_list(List* l, void (*free_void)(void*)){
	if(l != NULL){
		Node* ptr = l->begin;
		while(l->begin != NULL){
			ptr = l->begin->next;
			if(free_void != NULL)free_void(l->begin->element);
			free(l->begin);
			l->begin = ptr;
		}

		free(l);
	}
}


/* Test whether contaainer is empty. */
bool empty(List* l){
	if(l != NULL){
		if(l->size == 0){
			return true;
		}
	}
	return false;
}

/* Return size. */
int size(List* l){
	if(l != NULL){
		return l->size;
	}
	return 0;
}

/* Acess first element. */
void* first(List* l){
	if(l == NULL){
		return NULL;
	}
	return l->begin->element;
}

/* Acess last element. */
void* back(List* l){
	if(l == NULL){
		return NULL;
	}
	return l->end->element;
}

/* Insert element at beginnig. */
void push_front(List* l, void* element){
	if(l != NULL){
		Node* new = (Node *) malloc (sizeof(Node));
		new->previous = NULL;
		new->next = l->begin;
		if(new->next != NULL){
			new->next->previous = new;
		}
		new->element = element;
		l->begin = new;
		if(l->end == NULL){
			l->end = new;
		}
	}
}

/* Delete and return first element. */
void* pop_front(List* l){
	if(l != NULL){
		void* front = l->begin->element;
		erase(l, l->begin);
		return front;
	}
	return NULL;
}

/* Add element at the end. */
void push_back(List* l, void* element){
	if(l != NULL){
		Node* new = (Node *) malloc (sizeof(Node));
		new->next = NULL;
		new->previous = l->end;
		if(new->previous != NULL){
			new->previous->next = new;
		}
		new->element = element;
		l->end = new;
		if(l->begin == NULL){
			l->begin = new;
		}

	}
}

/* Delete and return last element. */
void* pop_back(List* l){
	if(l != NULL){
		void* front = l->end->element;
		erase(l, l->end);
		return front;
	}
	return NULL;
}

/* Delete an element. */
void erase(List* l, Node* ptr){
	if(l != NULL){
		if(ptr != NULL){
			// ptr == begin
			if(ptr == l->begin){
				if(l->begin == l->end){
					free(l->begin);
					l->begin = NULL;
					l->end = NULL;
				} else {
					l->begin = ptr->next;
					l->begin->previous = NULL;
					free(ptr);
				}
			}
			// ptr == end 
			else if(ptr == l->end){ 
				l->end = ptr->previous;
				l->end->next = NULL;
				free(ptr);
			}
			// ptr != end and != begin
			else {

			}

		}
	}
}

/* Remove element with specific value */
void remove_list(List* l, void* element){

}

/* Search an element with specific value*/
void find(List* l, void* element){

}