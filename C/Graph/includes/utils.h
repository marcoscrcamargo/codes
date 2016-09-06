/* 	MARCOS CESAR RIBEIRO DE CAMARGO - ICMC - USP
	N USP: 9278045 				DATA: 07/06/2016
	SCC0216 -  MODELAGEM COMPUTACIONAL EM GRAFOS
*/
#ifndef _UTILS_H_
#define _UTILS_H_
#include <stdio.h>

/* Defines auxiliares. */
#define and &&
#define or ||
#define true 1
#define false 0
#define INF 0x1.fffffffffffffp+1023
#define NIL -1 /* not in list. */



typedef unsigned char bool;

/* Função que lê uma linha inteira de um arquivo.
	Parâmetros:
		FILE* - stream de origem a string.
	Retorno:
		char* - string contendo uma linha inteira lida da stream.
*/
char* readline(FILE *);

#endif