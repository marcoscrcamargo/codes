/* 	MARCOS CESAR RIBEIRO DE CAMARGO - ICMC - USP
	N USP: 9278045 				DATA: 07/06/2016
	SCC0216 -  MODELAGEM COMPUTACIONAL EM GRAFOS
*/
#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_
#include <stdlib.h>
#include "utils.h"
#include "graph.h"
#include "map.h"

/* Identificadores para as opçoes. */
#define FM 0
#define CV 1
#define DV 2
#define CA 3
#define DA 4 
#define TV 5
#define TA 6
#define FW 7
#define IG 8
#define ID 9 
#define IC 10


/* Função que realiza o algoritmo de floyd warshall
	Parâmetros:
		Graph* - grafo no qual o algoritmo será executado.
		Map* - referências para os identificadores.
		double** - matriz de distâncias.
		int** - matriz de parentescos.
	Retorno:
		Não há.
*/
void floyd_warshall(Graph* g, Map* map, double** d, int** p);

/* Função que imprime a distância máxima entre dois vértices v e w.
	Parâmetros:
		Graph* - grafo
		Map* - mapa com os identificadores.
		double** - matriz de distâncias.
		Vertex* - referências para os vértices v e w.
	Retorno:
		Não há.
*/
void print_distance(Graph* g, Map* m, double** d, Vertex* v, Vertex* w);

/* Função que imprime o menor caminho entre o vértice v e w.
	Parâmetros:
		Graph* - grafo 
		Map* - mapa com os identificadores.
		int** - matriz de parentescos.
		Vertex* - referências para os vértices v e w
	Retorno:
		Não há.
*/
void print_shortest_path(Graph* g, Map* m, int** p, Vertex* v, Vertex* w);

/* Função que imprime um grafo g utilizando identificadores de um mapa m
	Parâmetros:
		Graph* - grafo a ser impresso.
		Map* - mapa com os vértices e arestas.
	Retorno:
		Não há.
*/
void print_graph(Graph* g, Map* m);

/* Função de decifra um commando, retornando um identificador
	para o comando.
	Parâmetros:
		char[] - string com o comando
	Retorno:
		int - identificador.
*/
int decipher(char command[3]);

/* Função que aloca memória para a matriz de distâncias e
	parentescos do floyd warshall
	Parâmetros:
		double*** - matriz de distâncias.
		int*** - matriz de parentescos.
		int n - tamanho das matrizes.
	Retorno:
		Não há.
*/
void allocate_fw(double*** distance, int*** parent, int n);

/* Função que libera a memória alocada para a matriz de distâncias e
	parentescos do floyd warshall
	Parâmetros:
		double** - matriz de distâncias.
		int** - matriz de parentescos.
		int n - tamanho das matrizes.
	Retorno:
		Não há.
*/
void delete_fw(double** distance, int** parent, int n);

#endif