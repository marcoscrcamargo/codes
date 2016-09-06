#ifndef _ITEM_H_
#define _ITEM_H_

typedef struct item {
	int key;
}Item;


void* new_item(int);
Item* get_item(void*);
void delete_item(Item*);
void delete_void(void*);

#endif