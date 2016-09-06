#include "list.h"
#include "utils.h"
#include "item.h"
#include <stdlib.h>

int main(int argc, char* argv[]){
	List* l = new_list();
	void* a = new_item(1);
	void* b = new_item(2);
	void* c = new_item(3);
	void* d = new_item(4);

	push_back(l, a);
	push_back(l, b);
	push_back(l, c);
	push_back(l, d);
	Item *x = get_item(pop_back(l));
	printf("%d\n", x->key);
	delete_item(x);

	delete_list(l, delete_void);

	return 0;
}