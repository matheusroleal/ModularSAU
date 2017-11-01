#include <stdio.h>
#include <stdlib.h>
#include"listas.h"

void printNodeValue(Node* cursor)  //print para testes
{
	int* a = (int*)cursor->val;
	printf("%d", *a);
}

int main (void)  // main teste1
{
	List* l;
	int a[3] = {10,120,570};
	void* b;
	int* c;

	createList(&l);

	push_back(l, &(a[0]));
	push_front(l, &(a[1]));
	push_back(l, &(a[2]));

	get_val_cursor(l, &b);
	c = (int*) b;
	next(l);
	printNodeValue(l->cursor);
    printf("\n%d", *c);
	prev(l);
	prev(l);
	printf("\n");
	printNodeValue(l->cursor);

	system("pause");

	return 0;
}
