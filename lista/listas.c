#include <stdio.h>
#include <stdlib.h>
#include "listas.h"


void createList(List** l){ (*l) = (List*) malloc(sizeof(List)); (*l)->first = NULL; (*l)->last = NULL; (*l)->cursor = NULL; }
void push_back(List* l, void* val)
{
	Node* Nnode;
	Nnode = (Node*) malloc (sizeof(Node));
	Nnode->val = val;
	Nnode->next = NULL;
	if(l->first == NULL)//Se a lista estiver vazia, primeiro nó = último nó = nó cursor.
	{
		l->first = Nnode;
		l->cursor = Nnode;
		Nnode->prev = NULL;
	}
	else
	{
		Nnode->prev = l->last;
		l->last->next = Nnode;
	}
	l->last = Nnode;
}

void push_front(List* l, void* val)
{
	Node* Nnode;
	Nnode = (Node*) malloc(sizeof(Node));
	Nnode->val = val;
	Nnode->prev = NULL;
	if(l->first == NULL)
	{
		l->last = Nnode;
		l->cursor = Nnode;
		Nnode->next = NULL;
	}
	else
	{
		Nnode->next = l->first;
		l->first->prev = Nnode;
	}
	l->first = Nnode;
}

void* pop_back(List* l)
{
	void* ret_value;

	if(l->first == NULL) { printf("\n\n <!><!><!> Lista Vazia! <!><!><!> \n\n"); return NULL; }

	ret_value = l->last->val;

	if (l->first == l->last)
	{
		l = NULL;
		return ret_value;		
	}	
	l->last = l->last->prev;
	l->last->next = NULL;
	return ret_value;
}

void* pop_front(List* l)
{
	void* ret_value;
	if(l->first == NULL) { printf("\n\n <!><!><!> Lista Vazia! <!><!><!> \n\n"); return NULL; }

	ret_value = l->first->val;

	if (l->first == l->last)
	{
		l = NULL;
		return ret_value;		
	}
	l->first = l->first->next;
	l->first->prev = NULL;
	return ret_value;
}

unsigned int list_size(List* l)
{
	unsigned int counter = 1;
	Node* Tnode = l->first;
	if(l->first == NULL)
		return 0;
	while(Tnode != l->last)
		counter++;
	return counter;
}

void next(List* l)
{
	if(l->first == NULL) { printf("\n\n <!><!><!> Lista Vazia! <!><!><!> \n\n");}
	else if(l->cursor->next == NULL)
		printf("\n\n <!> Cursor posicionado no final da lista <!> \n\n");
	else l->cursor = l->cursor->next;
	return;
}

void prev(List* l)
{
	if(l->first == NULL) { printf("\n\n <!><!><!> Lista Vazia! <!><!><!> \n\n");}
	else if(l->cursor->prev == NULL)
		printf("\n\n <!> Cursor posicionado no inicio da lista <!> \n\n");
	else l->cursor = l->cursor->prev;
	return;
}

void printNodeValue(Node* cursor)  //print teste
{
	int* a = (int*)cursor->val;
	printf("%d", *a);
}

int main (void)  // main teste1
{
	List* l;
	int a = 10;
	
	createList(&l);

	push_back(l, &a);

	printNodeValue(l->cursor);

	system("pause");

	return 0;
}
