#include "utils.h"
#include "priority_queue.h"
#include <stdlib.h>


#define PARENT(c) (int)((c-1)/2.0)
#define LCHILD(p) (int)((p*2) + 1)
#define RCHILD(p) (int)((p*2) + 2)

struct priority_queue{
	int size;
	void** element;
	int (*cmp)(void*, void *);
};


Priority_Queue* new_priority_queue(int (*cmp)(void*, void *)){
	Priority_Queue* PQ = (Priority_Queue*) malloc (sizeof(Priority_Queue));
	if(PQ != NULL){
		PQ->size = 0;
		PQ->element = NULL;
		PQ->cmp = cmp;
	}
	return PQ;
}

void delete_priority_queue(Priority_Queue* PQ, void (*free_void)(void*)){
	if(PQ != NULL){
		if(free_void != NULL){
			int i;
			for(i = 0; i < PQ->size; i++){
				free(PQ->element[i]);
			}
		}
		free(PQ->element);
		free(PQ);
	}
}

bool PQ_empty(Priority_Queue* PQ){
	if(PQ != NULL){
		if(PQ->size == 0){
			return true;
		}
	}
	return false;
}

int PQ_size(Priority_Queue* PQ){
	if(PQ != NULL){
		return PQ->size;
	}
	return 0;
}

void swap(void** vector, int x, int y){
	if(vector != NULL){
		void* aux = vector[x];
		vector[x] = vector[y];
		vector[y] = aux;
	}
}

void fix_down(void** vector, int size, int (*cmp)(void*, void*), int start){
	int parent = start;
	int child = (parent*2) + 1;

	while(child < size){
		// Escolhendo o menor/maior dos filhos
		if((child + 1) < size and ( cmp(vector[child+1], vector[child]) < 0 ) ){
			child++;
		}

		parent = (int)((child-1)/2.0);
		// Se o pair for menor/maior que o filho, então troca.
		if( cmp(vector[child], vector[parent]) < 0){
			swap(vector, parent, child);
			child = (child*2) + 1;
		} else break;
	}
}

void fix_up(void** vector, int size, int (*cmp)(void*, void*), int start){
	int child = start;
	int parent = (int)((child-1)/2.0);

	while( child > 0 and ( cmp(vector[child], vector[parent]) < 0 ) ){
/*		if( (child + 1 < size) and ( cmp(vector[child+1], vector[child]) < 0 ) ){
			//child++;
		}
*/		swap(vector, child, parent);
		child = parent;
		parent = (int)((child-1)/2.0);
	}
}

void* PQ_top(Priority_Queue* PQ){
	if(PQ != NULL){
		return PQ->element[0];
	}
	return NULL;
}

void PQ_push(Priority_Queue* PQ, void* element){
	if(PQ != NULL){
		PQ->element = (void **) realloc (PQ->element, (PQ->size+1)*sizeof(void*));
		if(PQ->element != NULL){
			PQ->element[PQ->size] = element;
			fix_up(PQ->element, PQ->size, PQ->cmp, PQ->size);
			PQ->size++;
		}
	}
}

void* PQ_pop(Priority_Queue* PQ){
	if(PQ != NULL){
		if(PQ->element != NULL and PQ->size > 0){
			void* tmp = PQ->element[0];
			PQ->element[0] = PQ->element[PQ->size - 1];
			PQ->size--;
			fix_down(PQ->element, PQ->size, PQ->cmp, 0);
			PQ->element = (void **) realloc (PQ->element, (PQ->size)*sizeof(void*));
			return tmp;
		}
	}
	return NULL;
}

void PQ_swap(Priority_Queue* PQ, void* old, void* new){
	if(PQ != NULL){
		int i, index = -1;

/*		for(i = 0; i < PQ->size; i++){
			if(PQ->cmp(old, PQ->element[i]) == 3){
				index = i;
				break;
			}
		}
*/
		for(i = 0; i < PQ->size; i++){
			if(old == PQ->element[i]){
				index = i;
				break;
			}
		}

		if(index != -1){		
			void* aux = PQ->element[index];
			PQ->element[index] = new;
			free(aux);
			fix_up(PQ->element, PQ->size, PQ->cmp, index);
			fix_down(PQ->element, PQ->size, PQ->cmp, index);
		}
	}
	return;
}


