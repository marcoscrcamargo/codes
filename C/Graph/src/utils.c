/* 	MARCOS CESAR RIBEIRO DE CAMARGO - ICMC - USP
	N USP: 9278045 				DATA: 07/06/2016
	SCC0216 -  MODELAGEM COMPUTACIONAL EM GRAFOS
*/
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

char* readline(FILE* fp){
	int i = 0;
	char c;
	char* string = NULL;
	
	do {
		string = (char *) realloc (string, sizeof(char)*(i+1));
		c = fgetc(fp);
		string[i++] = c;
	}while(c != '\n');
	string[--i] = '\0';
	
	return string;
}


