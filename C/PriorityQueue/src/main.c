#include "priority_queue.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "utils.h"

typedef struct example{
	int index;
	int value;
}example;

int cmp(void* x, void* y){
	example* a = x;
	example* b = y;
	if(a->value == b->value){
		if(a->index == b->index){
			return 3;
		}
		return 0;
	} else if (a->value < b->value){
		return -1;
	} else {
		return 1;
	}
}

void free_void(void* f){
	if(f != NULL){
		free(f);
	}	
}

#define n 10000/**/
#define MAX 100/**/

int main(int argc, char* argv[]){
	int i, exec = 0;

	while(exec < MAX){
		Priority_Queue* PQ = new_priority_queue(cmp);
		srand(time(NULL));
		example** element = (example **) malloc(n*sizeof(example *));
		for(i = 0; i < n; i++){
			element[i] = (example *) malloc (sizeof(example));
//			scanf("%d", element[i]);
			element[i]->index = i ;
			element[i]->value = rand() % 6666 ;
			PQ_push(PQ, element[i]);
		}

		for(i = 0; i < n; i++){
			example* aux = (example *) malloc (sizeof(example));
			aux->index = element[i]->index ;
			aux->value = rand() % 6666 ;
			PQ_swap(PQ, element[i], aux);	
		}

		int* before = PQ_pop(PQ);
		i = 0;
		while(!PQ_empty(PQ)){
			int* elementx = PQ_pop(PQ);
			if(cmp(before, elementx) > 0){
				printf("DEU RUIM");
				printf("\n%d > %d\n", *before, *elementx);
				printf("%d\n", i);

/*				printf("ENTRADAS COM ERROS: \n");
				for(i = 0; i < n; i++){
					printf("%d ", *element[i]);
				}
*/

				// printf("\n\n");
				free(before);
				free(element);
				free(elementx);
				delete_priority_queue(PQ, free_void);
				exit(122);
			}
			i++;
			free(before);
		 	before = elementx;
		}
		free(before);
		free(element);
		delete_priority_queue(PQ, free_void);
		printf("exec = %d\n", ++exec);
	}
	return 0;
}