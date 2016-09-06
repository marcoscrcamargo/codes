/* 	MARCOS CESAR RIBEIRO DE CAMARGO - ICMC - USP
	N USP: 9278045 				DATA: 07/06/2016
	SCC0216 -  MODELAGEM COMPUTACIONAL EM GRAFOS
*/
#ifndef _MAP_H_
#define _MAP_H_
#include <stdlib.h>
#include "utils.h"
#include "graph.h"
#include "map.h"

typedef struct map Map;

/* Cria um novo mapa que representa o par (identificador, referência) 
	para os vértices e arestas de um grafo. 
	Parâmetros:
		Não há.
	Retorno:
		Map* - novo mapa criado.
*/
Map* new_map();

/* Deleta completamente um mapa, liberando toda a memória necessária.
	Parâmetros:
		Map* - mapa a ser deletado.	
	Retorno:
		Não há.
*/
void delete_map(Map* m);

/* Adiciona um vértice ao mapa.
	Parametros:
		Map* - mapa a ser adicionado.
		Vertex* - referência para o vértice.
	Retorno:
		Não há.
*/
void MAP_insert_vertex(Map* m, Vertex* v);

/* Adiciona uma aresta ao mapa.
	Parametros:
		Map* - mapa a ser adicionado.
		Vertex* - referência para a aresta.
	Retorno:
		Não há.
*/
void MAP_insert_edge(Map* m, Edge* e);

void MAP_erase_vertex(Map* m, Vertex* v);
void MAP_erase_edge(Map* m, Edge* e);

/* Retorna o identificador a partir da referência de um vértice.
	Parâmetros:
		Map* - mapa com as referências para os vértices.
		Vertex* - refêrencia a ser buscada.
	Retorno:
		int - identificador do vértice.
*/
int getID_vertex(Map* m, Vertex* v);

/* Retorna o identificador a partir da referência de uma aresta.
	Parâmetros:
		Map* - mapa com as referências para as arestas.
		Edge* - refêrencia a ser buscada.
	Retorno:
		int - identificador da aresta.
*/
int getID_edge(Map* m, Edge* e);

/* Retorna a referência de um determinado identificador do vértice.
	Parâmetros:
		Map* - mapa com as referências para os vértices.
		int - identificador do vértice.
	Retorno:
		Vertex* - referência para o vértice.
*/
Vertex* getr_vertex(Map* m, int v);

/* Retorna a referência de um determinado identificador da aresta.
	Parâmetros:
		Map* - mapa com as referências para as arestas.
		int - identificador da aresta.
	Retorno:
		Edge* - referência para a aresta.
*/
Edge* getr_edge(Map* m, int e);

/* Retorna o número de vértices armazenados no mapa.
	Parâmetros:
		Map*- mapa
	Retoro:
		int - número de vértices.
*/
int map_nvertices(Map* m);

/* Retorna o número de arestas armazenados no mapa.
	Parâmetros:
		Map*- mapa
	Retoro:
		int - número de arestas.
*/
int map_nedges(Map* m);

/* Inicializa o mapa com os indices neessários para 
	o algoritmo de Floyd Warshall.
	Parâmetros:
		Map* - mapa
	Retorno:
		Não há.
*/
void FW_map_initializate(Map* m);

/* Retorna o indice da matriz do algoritmod e Floyd Warshall
	a partir da referência de um vértice.
	Parâmetros:
		Map* - mapa
		Vertex* - referência para o vértice.
	Retorno:
		int - indice da matriz. 
*/

int FWgetID_vertex(Map* m, Vertex* v);

/* Retorna o indice do vértice a partir do indice da matriz
	do algoritmo de Floyd Warshall.
	Parâmetros:
		Map* - mapa
		int  - indice armazenado na matriz.
	Retorno:
		int - indice do vértice. 
*/
int FWtoID(Map* m, int fw);

#endif