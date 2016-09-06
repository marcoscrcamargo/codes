/* 	MARCOS CESAR RIBEIRO DE CAMARGO - ICMC - USP
	N USP: 9278045 				DATA: 07/06/2016
	SCC0216 -  MODELAGEM COMPUTACIONAL EM GRAFOS
*/

#include <stdlib.h>
#include "graph.h"
#include "utils.h"
#include "algorithm.h"
#include "map.h"

int main(int argc, char* argv[]){
	Graph* g = new_graph();
	int v, w, e, value, n;
	double element;

	char command[3];
	bool exit = false;
	Map* map = new_map();
	double** distance = NULL;
	int** parent = NULL;

	while(!exit){
		scanf("%s", command);
		switch(decipher(command)){
			case FM:
				exit = true;
				break;

			case CV:
				scanf("%d", &value);
				MAP_insert_vertex(map, insert_vertex(g, value));
				break;

			case DV:
				scanf("%d", &v);
				Vertex* V = getr_vertex(map, v);
				remove_vertex(g, V);
				MAP_erase_vertex(map, V);
				break;

			case CA:
				scanf("%d %d %lf", &v, &w, &element);
				MAP_insert_edge(map, insert_edge(g, getr_vertex(map, v), getr_vertex(map, w), element));
				break;

			case DA:
				scanf("%d", &e);
				Edge* E = getr_edge(map, e);
				remove_edge(g, E);
				MAP_erase_edge(map, E);
				break;
			case TV:
				scanf("%d %d", &v, &value);
				replace_vertex(g, getr_vertex(map, v), value);
				break;

			case TA:
				scanf("%d %lf", &e, &element);
				replace_edge(g, getr_edge(map, e), element);
				break;

			case FW:
				n = num_vertices(g);
				allocate_fw(&distance, &parent, n);
				floyd_warshall(g, map, distance, parent);
				break;

			case IG:
				print_graph(g, map);
				break;

			case ID:
				scanf("%d %d", &v, &w);
				print_distance(g, map, distance, getr_vertex(map, v), getr_vertex(map, w));
				break;

			case IC:
				scanf("%d %d", &v, &w);
				print_shortest_path(g, map, parent, getr_vertex(map, v), getr_vertex(map, w));
				break;

			default:
				//exit = true;
				break;
		}

	}

	delete_fw(distance, parent, n);
	delete_map(map);	
	delete_graph(g);
	return 0;
}