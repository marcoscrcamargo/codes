#include "item.h"
#include <stdlib.h>
#include <string.h>

void* new_item(int key){
	void* data = (void *) malloc(sizeof(Item));

	Item* i = (Item *) malloc(sizeof(Item));	
	i->key = key;
	memcpy(data, i, sizeof(Item));
	free(i);

	return data;
}

Item* get_item(void* data){
	Item* i = (Item *) malloc(sizeof(Item));	
	memcpy(i, data, sizeof(Item));
	free(data);
	return i;
}

void delete_item(Item* i){
	free(i);
}
void delete_void(void* data){
	free(data);
}

