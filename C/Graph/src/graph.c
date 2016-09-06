/* 	MARCOS CESAR RIBEIRO DE CAMARGO - ICMC - USP
	N USP: 9278045 				DATA: 07/06/2016
	SCC0216 -  MODELAGEM COMPUTACIONAL EM GRAFOS
*/
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "list.h"

/* Declaração das funções para uso interno ao TAD. */

/* Funções para vértices. */

/* Cria um novo vértice com valor o.
	Parâmetros:
		int - valor armazenado no vértice.
	Retorno:
		Vertex* - referência para o vértice criado.
*/
Vertex* new_vertex(int o);

/* Deleta um vértice v, e libera toda a memória necessária.
	Parâmetros:
		void* - vértice a ser deletado.
	Retorno:
		Não há.
*/
void delete_vertex(void* v) ;


/* Atualiza o valor de um vértice v para o.
	Parâmetros:
		Vertex* - referência para o vértice.
		int -  elemento a ser armazenado.
*/
void vertex_set_value(Vertex* v, int o);

/* Retorna o valor armazenado no vértice v.
	Parâmetros:
		Vertex* - referência para o vértice.
	Retorno:
		int - valor armazenado no vértice.
*/
int vertex_get_value(Vertex* v);

/* Funções para arestas. */

/* Cria uma novo aresta com valor o.
	Parâmetros:
		Vertex* - vértices de término da aresta.
		double - valor armazenado na aresta.
	Retorno:
		Edge* - referência para o aresta criado.
*/
Edge* new_edge(Vertex* v, Vertex* w, double o);

/* Deleta um aresta e, e libera toda a memória necessária.
	Parâmetros:
		void* - aresta a ser deletada.
	Retorno:
		Não há.
*/
void delete_edge(void* e);

/* Atualiza o valor de uma aresta e para o.
	Parâmetros:
		Edge* - referência para o aresta.
		double -  elemento a ser armazenado.
*/
void edge_set_value(Edge* e, double o);

/* Retorna o valor armazenado na aresta e.
	Parâmetros:
		Edge* - referência para a aresta.
	Retorno:
		double - valor armazenado na aresta.
*/
double edge_get_value(Edge* e);



/* Funções para adjacentes. */

/* Cria um novo adjacent com ponteiro para aresta e na lista.
	Parâmetros:
		Node* - referência para a aresta na lista
	Retorno:
		Adjacent* - referência para o adjacent criado.
*/
Adjacent* new_adjacent(Node* e);

/* Deleta um adjacent e, e libera toda a memória necessária.
	Parâmetros:
		void* - adjcaent a ser deletado.
	Retorno:
		Não há.
*/
void delete_adjacent(void* a);


/* Declaração das estruturas. */

struct graph{
	List* vertices; // Lista de vértices.
	List* edges;	// Lista de arestas.
};

struct vertex{
	Node* this; // Referência o nó do vértice na lista de vértices.

	int value; // Valor armazenado pelo vértice.
	List* adjacent_edges; // Lista de adjacências.

};

struct edge {
	Node* this; // Referência o nó da aresta na lista de arestas.

	Node* av; // Ponteiro para nó na lista de adjacências do vértice v.
	Vertex* v; // Referência para o vértice v.
	Node* aw; // Ponteiro para nó na lista de adjacências do vértice w.
	Vertex* w; // Referência para o vértice w.
	double element; // Elemento armazenado pela aresta.
};

struct adjacent {
	Node* this; // Referência o nó de adjacencias na lista de adjacencias.

	Node* e; // Referência para a aresta adjacênte.
};

/* Funções dos vértices. */

/* Cria um novo vértice com valor o. */
Vertex* new_vertex(int o){
	Vertex* v = (Vertex*) malloc (sizeof(Vertex));
	v->adjacent_edges = new_list();
	v->value = o;
	return v;	
}

/* Deleta um vértice v, e libera toda a memória necessária. */
void delete_vertex(void* v){
	if(v != NULL){
		Vertex* w = (Vertex*) malloc (sizeof(Vertex));
		memcpy(w, v, sizeof(Vertex));

		delete_list(w->adjacent_edges, delete_adjacent);
		
		free(w);
		free(v);
	}

}

/* Atualiza o valor de um vértice v para o. */
void vertex_set_value(Vertex* v, int o){
	if(v != NULL){
		v->value = o;
	}
}

/* Retorna o valor armazenado no vértice v. */
int vertex_get_value(Vertex* v){
	if(v != NULL){
		return v->value;
	}
	return -1;
}

/* Funções das arestas. */

/* Cria uma novo aresta com valor o. */
Edge* new_edge(Vertex* v, Vertex* w, double o){
	Edge* e = (Edge*) malloc (sizeof(Edge));
	e->v = v;
	e->w = w;
	e->element = o;
	return e;
}

/* Deleta um aresta e, e libera toda a memória necessária. */
void delete_edge(void* e){
	if(e != NULL){
		free(e);
	}
}

/* Atualiza o valor de uma aresta e para o. */
void edge_set_value(Edge* e, double o){
	if(e != NULL){
		e->element = o;
	}
}

/* Retorna o valor armazenado na aresta e. */
double edge_get_value(Edge* e){
	if(e != NULL){
		return e->element;
	}
	return 0;	
}

/* Funções para adjacent. */

/* Cria um novo adjacent com ponteiro para aresta e na lista. */
Adjacent* new_adjacent(Node* e){
	if(e != NULL){
		Adjacent* a = (Adjacent*) malloc (sizeof(Adjacent));
		a->e = e;
		return a;
	}
	return NULL;
}

/* Deleta um adjacent e, e libera toda a memória necessária. */
void delete_adjacent(void* a){
	if(a != NULL){
		free(a);
	}
}


/* Funções do grafo. */

/* Cria um novo grafo. */
Graph *new_graph(){
	Graph *g = NULL;
	g = (Graph *)malloc(sizeof(Graph));

	if(g != NULL){
		g->edges = new_list();
		g->vertices = new_list();
	}

	return g;
}

/* Delete o grafo. */
void delete_graph(Graph* g){
	if(g != NULL){
		delete_list(g->vertices, delete_vertex);
		delete_list(g->edges, delete_edge);
		free(g);
	}
}

/* Retorna referências, v e w, para os dois vértices finais da aresta e. */
void end_vertices(Graph* g, Edge* e, Vertex** v, Vertex** w){
	if(g != NULL and e != NULL){
		*v = e->v;
		*w = e->w;
	} else {
		*v = NULL;
		*w = NULL;		
	}
}

/* Retorna a referência  do vértice oposto a v pela aresta e. */
Vertex* opposite(Graph* g, Vertex* v, Edge* e){
	if(v != NULL and e != NULL){
		if(e->v == v){
			return e->w;
		}
		if(e->w == v){
			return e->v;
		}
	}
	return NULL;
}

/* Verifica se dois vértices, v e w, são adjacentes. */
bool are_adjacent(Graph* g, Vertex* v, Vertex* w){
	Node* ptr = NULL;
	if(g != NULL and v != NULL and w != NULL){
		// Pecorrendo a menor lista de adjacências
		if(size(v->adjacent_edges) >= size(w->adjacent_edges)){
			ptr = begin(v->adjacent_edges);		
			do{
				Edge* e = (Edge*) get_element(ptr);
				if(e != NULL){
					// Verifica se são adjacêntes.
					if((e->v == v and e->w == w) or (e->w == v and e->v == w)){
						return true;
					}
				}
			}while(has_next(ptr), ptr = next(ptr));
		} else {
			ptr = begin(w->adjacent_edges);		
			do{
				Edge* e = (Edge*) get_element(ptr);
				if(e != NULL){
					// Verifica se são adjacêntes.
					if((e->v == v and e->w == w) or (e->w == v and e->v == w)){
						return true;
					}
				}
			}while(has_next(ptr), ptr = next(ptr));
		}

	}

	return false;

}

/* Substitui o elemento armazenado no vértice v por o. */
void replace_vertex(Graph* g, Vertex* v, int o){
	if(g != NULL and v != NULL){
		vertex_set_value(v, o);
	}
}

/* Substitui o elemento armazenado na aresta e por o. */
void replace_edge(Graph* g, Edge* e, double o){
	if(g != NULL and e != NULL){
		edge_set_value(e, o);
	}
}

/* Insere um novo vértice no grafo g, armazenando nele o elemento o. */
Vertex* insert_vertex(Graph* g, int o){
	Vertex* v = new_vertex(o);
	v->this = push_back(g->vertices, v);
	return v;
}

/* Insere uma nova aresta entre os vértices v e w, armazenando nela o elemento o,
	e retorna uma referência para a aresta inserida. */
Edge* insert_edge(Graph* g, Vertex* v, Vertex* w, double o){
	Adjacent* a;
	Edge* e = new_edge(v, w, o);
	e->this = push_back(g->edges, e);
	// Inserindo na lista de adjacências de ambos os vértices.
	a = new_adjacent(e->this);
	a->this = push_back(v->adjacent_edges, a);
	e->av = a->this;
	a = new_adjacent(e->this);
	a->this = push_back(w->adjacent_edges, a);
	e->aw = a->this;

	return e;
}

/* Remove o vertice v (e suas arestas) e retorna o elemento armazenado nele. */
int remove_vertex(Graph* g, Vertex* v){
	if(g != NULL and v != NULL){
		// Percorrendo adjacentes de v
		Node* ptr = begin(v->adjacent_edges);		
		Node* nxt = NULL;		
		do{
			if(ptr != NULL){
				// Apagando arestas adjacentes.
				Adjacent* a = (Adjacent*) get_element(ptr);
				Edge* e = (Edge*) get_element(a->e);
				nxt = next(ptr);
				remove_edge(g, e);
			}
		}while((ptr = nxt) != NULL);
		// Apagando o vértice.
		int value = vertex_get_value(v);
		erase(g->vertices, v->this);
		delete_vertex((void*)v);
		return value;
	}
	return -1;
}

/* Remove a aresta e, e retorna o elemento armazenado nela. */
double remove_edge(Graph* g, Edge* e){
	if(g != NULL and e != NULL){
		// Deleta a aresta da lista de adjacências de v.
		delete_adjacent(get_element(e->av));
		erase(e->v->adjacent_edges, e->av);
		// Deleta a aresta da lista de adjacências de w.
		delete_adjacent(get_element(e->aw));
		erase(e->w->adjacent_edges, e->aw);
		// Apaga o aresta da lista de arestas.
		erase(g->edges, e->this);
		// Apaga a aresta.
		double element = edge_get_value(e);
		delete_edge(e);
		return element;
	}
	return UNREACHABLE;
}

/* Retorna o elemento armazenado no vértice v. */
int vertex_value(Graph* g, Vertex* v){
	if(g != NULL and v != NULL){
		return vertex_get_value(v);
	}
	return -1;

}

/* Retorna o elemento armazenado na aresta e. */
double edge_value(Graph* g, Edge* e){
	if(g != NULL and e != NULL){
		return edge_get_value(e);
	}
	return UNREACHABLE;
}

/* Retorna a quantidade de vértices de g. */
int num_vertices(Graph* g){
	if(g != NULL){
		return size(g->vertices);
	}
	return 0;
}

/* Retorna a quantidade de arestas de g. */
int num_edges(Graph*g){
	if(g != NULL){
		return size(g->edges);
	}
	return 0;
}

/* Auxiliares.*/
/* Retorna refêrencias para pecorrer a lista de vértices fora do TAD*/
List* get_vertices(Graph* g){
	if(g != NULL){
		return g->vertices;
	}
	return NULL;
}

/* Retorna refêrencias para pecorrer a lista de arestas fora do TAD*/
List* get_edges(Graph* g){
	if(g != NULL){
		return g->edges;
	}
	return NULL;
}
