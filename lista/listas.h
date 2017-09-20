#include <stdio.h>
#include <stdlib.h>

typedef struct node		//Estrutura de Nós para se criar uma lista
{
	struct node* next;	//Referência para o próximo nó
	struct node* prev;  //Referência para o nó anterior
	void* val;			//Referência para variável
}Node;

struct list		//Estrutura Lista para armazenar e navegar (cursor) em uma lista
{
	Node* first;  //Aponta para o primeiro nó
	Node* last;	  //Aponta para o último nó
	Node* cursor; //Aponta para o nó cursor
};

typedef struct list List;

void createList(List** l); //cria uma lista vazia IMPORTANTE: ESTA FUNÇÃO RECEBE: (& variável do tipo List), perceba que Lista é declarado como tipo list*

void push_back(List* l, void* val); //insere um elemento no final da List

void push_front(List* l, void* val)/ //insere um elemento no começo da List
	
void* pop_back(List* l);  //retorna a referência para o valor do último nó, e retira o nó da lista

/*void* pop_cursor(List* l); A fazer - Remove o nó cursor da lista e retorna referência para seu valor. */

/*void prt_cursor(List* l); Depende da estrutura, então não dá pra fazer aqui. */

/*void exclui_cursor(List* l); A fazer - Destrui nó cursor e reposiciona o cursor segundo convenção. */

unsigned int list_size(List* l); //retorna a quantidade de elementos na List

void next(List* l);//atualiza o cursor para o próximo nó

void prev(List* l);//atualiza o cursor para o nó anterior

/*void del(List l); A fazer - Deleta toda a lista. */

