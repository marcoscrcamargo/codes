/* 	MARCOS CESAR RIBEIRO DE CAMARGO - ICMC - USP
	N USP: 9278045 				DATA: 07/06/2016
	SCC0216 -  MODELAGEM COMPUTACIONAL EM GRAFOS
*/
#include <stdlib.h>
#include "utils.h"
#include "graph.h"
#include "algorithm.h"
#include "map.h"

/* Função que realiza o algoritmo de floyd warshall. */
void floyd_warshall(Graph* g, Map* map, double** d, int** p){
	int n = num_vertices(g);
	int i, j, k;
	Edge* e = NULL;
	// Inicializando os valores.
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			d[i][j] = UNREACHABLE;
			p[i][j] = NIL;
		}
		d[i][i] = 0;
	}
	// Inicializando o mapa para o floyd warshall
	FW_map_initializate(map);

	// Percorrendo lista de arestas.
	Node* ptr = begin(get_edges(g));		
	do{
		if(ptr != NULL){
			e = (Edge*) get_element(ptr);
			if(e != NULL){
				Vertex* U;
				Vertex* V;
				end_vertices(g, e, &U, &V);
				int u = FWgetID_vertex(map, U),
					v = FWgetID_vertex(map, V);
				d[u][v] = edge_value(g, e);
				d[v][u] = edge_value(g, e);
				p[u][v] = v;
				p[v][u] = u;
			}

		}
	}while(has_next(ptr), ptr = next(ptr));

	for(k = 0; k < n; k++){
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
	            if(d[i][k] + d[k][j] < d[i][j]){
	               d[i][j] = d[i][k] + d[k][j];
	               p[i][j] = p[i][k];
				}
			}
		}
	}
}


/* Função que imprime a distância máxima entre dois vértices v e w. */
void print_distance(Graph* g, Map* m, double** d, Vertex* v, Vertex* w){
	if(g != NULL and m!= NULL and d != NULL and v != NULL and w != NULL){
		int V = FWgetID_vertex(m, v);
		int W = FWgetID_vertex(m, w);
		printf("%.3lf\n", d[V][W]);
	}
}


/* Função que imprime o menor caminho entre o vértice v e w. */
void print_shortest_path(Graph* g, Map* m, int** p, Vertex* v, Vertex* w){
	if(g != NULL and m!= NULL and p != NULL and v != NULL and w != NULL){
		int i = FWgetID_vertex(m, v);
		int j = FWgetID_vertex(m, w);
		if(p[i][j] == NIL){
			printf("0\n");
		} else {
			int parent = p[i][j];
			printf("%d", FWtoID(m, i));
			
			while(parent != j){
				if(parent != NIL)printf(" %d", FWtoID(m, parent));
				parent = p[parent][j];
			} 
			printf(" %d\n", FWtoID(m, j));
		}
	}
}


/* Função que imprime um grafo g utilizando identificadores de um mapa m. */
void print_graph(Graph* g, Map* m){
	if(g != NULL){
		printf("%d\n", num_vertices(g));
		// Percorrendo a lista de vértices.
		Node* ptr = begin(get_vertices(g));		
		do{
			if(ptr != NULL){
				Vertex* v = (Vertex*) get_element(ptr);
				printf("%d %d\n", getID_vertex(m, v), vertex_value(g, v));
			}
		}while(has_next(ptr), ptr = next(ptr));

		printf("%d\n", num_edges(g));
		// Percorrendo a lista de arestas.
		ptr = begin(get_edges(g));		
		do{
			if(ptr != NULL){
				Vertex* U = NULL;
				Vertex* W = NULL;
				Edge* e = (Edge*) get_element(ptr);
				end_vertices(g, e, &U, &W);
				int v = getID_vertex(m, U);
				int w = getID_vertex(m, W);
				if(v < w){
					printf("%d %d %d %.3lf\n", getID_edge(m, e), v, w,  edge_value(g, e));
				} else {
					printf("%d %d %d %.3lf\n", getID_edge(m, e), w, v,  edge_value(g, e));
				}
			}
		}while(has_next(ptr), ptr = next(ptr));

	}	
}


/* Função de decifra um commando, retornando um identificador
	para o comando. */
int decipher(char command[3]){
	if(command[0] == 'C' and command[1] == 'V'){
		return CV;
	}
	if(command[0] == 'C' and command[1] == 'A'){
		return CA;
	}
	if(command[0] == 'D' and command[1] == 'V'){
		return DV;
	}
	if(command[0] == 'D' and command[1] == 'A'){
		return DA;
	}
	if(command[0] == 'T' and command[1] == 'V'){
		return TV;
	}
	if(command[0] == 'T' and command[1] == 'A'){
		return TA;
	}
	if(command[0] == 'F' and command[1] == 'W'){
		return FW;
	}
	if(command[0] == 'I' and command[1] == 'G'){
		return IG;
	}
	if(command[0] == 'I' and command[1] == 'D'){
		return ID;
	}
	if(command[0] == 'I' and command[1] == 'C'){
		return IC;
	}
	return FM;
}



/* Função que aloca memória para a matriz de distâncias e
	parentescos do floyd warshall. */
void allocate_fw(double*** distance, int*** parent, int n){
	int i;
	if(n > 0){
		*distance = (double**) realloc (*distance, sizeof(double*)*n);
		*parent = (int**) realloc (*parent, sizeof(int*)*n);
		for(i = 0; i < n; i++){
			(*distance)[i] = (double*) malloc(sizeof(double)*n);
			(*parent)[i] = (int*) malloc(sizeof(int)*n);
		}
	}
}

/* Função que libera a memória alocada para a matriz de distâncias e
	parentescos do floyd warshall. */
void delete_fw(double** distance, int** parent, int n){
	int i;
	if(distance != NULL and parent != NULL){
		for(i = 0; i < n; i++){
			free(distance[i]);
			free(parent[i]);
		}
		free(parent);
		free(distance);
	}
}



















