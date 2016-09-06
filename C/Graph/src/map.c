/* 	MARCOS CESAR RIBEIRO DE CAMARGO - ICMC - USP
	N USP: 9278045 				DATA: 07/06/2016
	SCC0216 -  MODELAGEM COMPUTACIONAL EM GRAFOS
*/
#include <stdlib.h>
#include "utils.h"
#include "list.h"
#include "map.h"


typedef struct triple{
	Node* this;

	int key;
	int fwindex;
	void* value;
}Triple;


Triple* new_triple(int key, void* value){
	Triple* t = (Triple*) malloc (sizeof(Triple));
	if(t != NULL){
		t->key = key;
		t->value = value;
		t->fwindex = NIL;
	}
	return t;
}

void delete_triple(void* t){
	if(t != NULL){
		free(t);
	}
}

int cmp_key(void* a, void* b){
	if(a != NULL and b != NULL){
		Triple* t = (Triple*) b;
		int* key = (int*) a;
		if(t->key == *key){
			return 0;
		}
	}
	return -1;
}

int cmp_fw(void* a, void* b){
	if(a != NULL and b != NULL){
		Triple* t = (Triple*) b;
		int* fw = (int*) a;
		if(t->fwindex == *fw){
			return 0;
		}
	}
	return -1;
}

int cmp_value(void* a, void* b){
	if(a != NULL and b != NULL){
		Triple* t = (Triple*) b;
		if((void*)(t->value) == a){
			return 0;
		}
	}
	return -1;
}

struct map{
	List* vertices;
	List* edges;
};


Map* new_map(){
	Map* m = (Map*) malloc(sizeof(Map));
	if(m != NULL){
		m->vertices = new_list();
		m->edges = new_list();
	}
	return m;
}

void delete_map(Map* m){
	if(m != NULL){
		delete_list(m->vertices, delete_triple);
		delete_list(m->edges, delete_triple);
		free(m);
	}
}


void MAP_insert_vertex(Map* m, Vertex* v){
	if(m != NULL and v != NULL){
		Triple* t = new_triple(size(m->vertices) + 1, (void*)v);
		t->this = push_back(m->vertices, t);
	}
}

void MAP_insert_edge(Map* m, Edge* e){
	if(m != NULL and e != NULL){
		Triple* t = new_triple(size(m->edges) + 1, (void*)e);
		t->this = push_back(m->edges, t);
	}
}

void MAP_erase_vertex(Map* m, Vertex* v){
	if(m != NULL and v != NULL){
		Triple* t = (Triple*)find(m->vertices, v, cmp_value);
		if(t != NULL){
			erase(m->vertices, t->this);
			delete_triple(t);
		}
	}
}

void MAP_erase_edge(Map* m, Edge* e){
	if(m != NULL and e != NULL){
		Triple* t = find(m->edges, e, cmp_value);
		if(t != NULL){
			erase(m->edges, t->this);
			delete_triple(t);
		}
	}
}

int getID_vertex(Map* m, Vertex* v){
	if(m != NULL and v != NULL){
		Triple* t = (Triple*)find(m->vertices, v, cmp_value);
		if(t != NULL){
			return t->key;
		}
	}
	return -1;
}

int getID_edge(Map* m, Edge* e){
	if(m != NULL and e != NULL){
		Triple* t = find(m->edges, e, cmp_value);
		if(t != NULL){
			return t->key;
		}
	}
	return -1;
}

Vertex* getr_vertex(Map* m, int v){
	if(m != NULL){
		Triple* t = find(m->vertices, &v, cmp_key);
		if(t != NULL){
			return t->value;
		}
	}
	return NULL;
}

Edge* getr_edge(Map* m, int e){
	if(m != NULL){
		Triple* t = find(m->edges, &e, cmp_key);
		if(t != NULL){
			return t->value;
		}
	}
	return NULL;
}

int map_nvertices(Map* m){
	if(m != NULL){
		return size(m->vertices);
	}
	return 0;
}

int map_nedges(Map* m){
	if(m != NULL){
		return size(m->edges);
	}
	return 0;
}


void FW_map_initializate(Map* m){
	if(m != NULL){
		int i = 0;
		Node* ptr = begin(m->vertices);		
		do{
			if(ptr != NULL){
				Triple* t = (Triple*) get_element(ptr);
				if(t != NULL){
					t->fwindex = i++;
				}
			}
		}while(has_next(ptr), ptr = next(ptr));
	}
}

int FWgetID_vertex(Map* m, Vertex* v){
	if(m != NULL and v != NULL){
		Triple* t = (Triple*)find(m->vertices, v, cmp_value);
		if(t != NULL){
			return t->fwindex;
		}
	}
	return NIL;
}

int FWtoID(Map* m, int fw){
	if(m != NULL ){
		Triple* t = find(m->vertices, &fw, cmp_fw);
		if(t != NULL){
			return t->key;
		}
	}
	return NIL;
}
