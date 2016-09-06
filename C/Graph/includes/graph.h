/* 	MARCOS CESAR RIBEIRO DE CAMARGO - ICMC - USP
	N USP: 9278045 				DATA: 07/06/2016
	SCC0216 -  MODELAGEM COMPUTACIONAL EM GRAFOS
*/
#ifndef _GRAPH_ADJACENCY_LIST_H_
#define _GRAPH_ADJACENCY_LIST_H_
#include <stdlib.h>
#include "list.h"
#include "utils.h"

#define UNREACHABLE 10e6;


typedef struct graph 	Graph;
typedef struct vertex 	Vertex;
typedef struct edge 	Edge;
typedef struct adjacent Adjacent;


/* Grafo. */

/* Cria um novo grafo.
	Parâmetros:
		Não há.
	Retorno :
		Graph* - novo grafo alocado.
*/
Graph* new_graph();

/* Destroi o grafo g, liberando toda a memoria alocada pelo mesmo. 
	Parâmetros:
		Não há.
	Retorno:
		Graph* - grafo a ser apagado.
*/
void delete_graph(Graph* g);

/* Retorna referências, v e w, para os dois vértices finais da aresta e. 
	Parâmetros:
		Graph* - grafo que contém a aresta.
		Edge* - aresta entre os vértices v e w.
		Vertex* - retorno das referencias para os vértices.
	Retorno: Não há.
*/
void end_vertices(Graph* g, Edge* e, Vertex** v, Vertex** w);

/* Retorna a referência  do vértice oposto a v pela aresta e.
	Parâmetros:
		Graph* - grafo que contém os vértices e arestas.
		Vertex* - vértice v.
		Edge* - aresta entre v e seu oposto.
	Retorno:
		Vertex* - vértice oposto a v.	
*/
Vertex* opposite(Graph* g, Vertex* v, Edge* e);

/* Verifica se dois vértices, v e w, são adjacentes.
	Parâmetros:
		Graph* - grafo que contém os vértices e arestas.
		Vertex* - vertices a serem verificados
	Retorno:
		bool - true(1) ou false(0).
 */
bool are_adjacent(Graph* g, Vertex* v, Vertex* w);

/* Substitui o elemento armazenado no vértice v por o.
	Parâmetros:
		Graph* - grafo que contém o vértice.
		Vertex* - vertice que o elemento será trocado.
		int - novo elemento.
*/
void replace_vertex(Graph* g, Vertex* v, int o);

/* Substitui o elemento armazenado na aresta e por o. 
	Parâmetros:
		Graph* - grafo que contém a aresta.
		Edge - aresta que o elemento será trocado.
		double - novo elemento.
*/
void replace_edge(Graph* g, Edge* e, double o);

/* Insere um novo vértice no grafo g, armazenando nele o elemento o, 
	e retorna uma referência para o vértice inserido. 
	Parâmetros:
		Graph* - grafo a ser inserido o vértice.
		int - elemento a ser armazenado no vértice.
	Retorno:
		Vertex* - referência para o novo vértice.
*/
Vertex* insert_vertex(Graph* g, int o);

/* Insere uma nova aresta entre os vértices v e w, armazenando nela o elemento o,
	e retorna uma referência para a aresta inserida.
	Parâmetros:
		Graph* - grafo a ser inserido a aresta.
		Vertex* - vertices no final da aresta.
		double - elemento a ser inserido na aresta.
	Retorno:
		Edge* - referência para a aresta.	
*/
Edge* insert_edge(Graph* g, Vertex* v, Vertex* w, double o);

/* Remove o vertice v (e suas arestas) e retorna o elemento armazenado nele.
	Parâmetros:
		Graph* - grafo que contém o vértice a ser removido.
		Vertex* - referência para o vértice a ser removido.
	Retorno:
		int - elemento armazenado no vértice.
*/
int remove_vertex(Graph* g, Vertex* v);

/* Remove a aresta e, e retorna o elemento armazenado nela.
	Parâmetros:
		Graph* - grafo que contém a aresta a ser removida.
		Edge* - referência para aresta a ser removida.
	Retorno:
		double - elemento armazenado na aresta.
*/
double remove_edge(Graph* g, Edge* e);

/* Retorna o elemento armazenado no vértice v.
	Parâmetros:
		Graph* - grafo que contém o vértice v.
		Vertex* - referência para o vértice v.
	Retorno:
		int - elemento armazenado em v.
*/
int vertex_value(Graph* g, Vertex* v);

/* Retorna o elemento armazenado na aresta e.
	Parâmetros:
		Graph* - grafo que contém a aresta e.
		Edge* - referência para a aresta e.
	Retorno:
		double - elemento armazenado em v.
*/
double edge_value(Graph* g, Edge* e);

/* Retorna a quantidade de vértices de g.
	Parâmetros:
		Graph* - grafo que contém vértices e arestas.
	Retorno:
		int - quantidade de vértices em g.
*/
int num_vertices(Graph* g);

/* Retorna a quantidade de arestas de g.
	Parâmetros:
		Graph* - grafo que contém vértices e arestas.
	Retorno:
		int - quantidade de arestas em g.
*/
int num_edges(Graph*g);



/* Auxiliares. */

/* Retorna um ponteiro para o inicio da lista de vértices,
	usado para percorrer a lista fora do TAD grafo, como
	por exemplo no algoritmo floyd warshall
	Parâmetros:
		Graph* - grafo que será retornado a lista de vértice.
	Retorno:
		List* - lista com os vértices
*/

List* get_vertices(Graph* g);
/* Retorna um ponteiro para o inicio da lista de arestas,
	usado para percorrer a lista fora do TAD grafo, como
	por exemplo no algoritmo floyd warshall
	Parâmetros:
		Graph* - grafo que será retornado a lista de arestas.
	Retorno:
		List* - lista com as arestas.
	
*/
List* get_edges(Graph* g);

#endif