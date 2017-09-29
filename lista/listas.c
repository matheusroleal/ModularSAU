/***************************************************************************
*
*  $MCI Módulo de definição: Módulo Lista
*
*  Arquivo gerado:              listas.c
*  Letras identificadoras:      LIS
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 4
*  Autores:   mrol - Matheus Rodrigues de Oliveira Leal
*             SaintL - Leonardo Abreu Santos
*	      	  ngtgmp - Felipe Nogueira de Souza
	          LL - Clayton Lucas Mendes Lima
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       0.01   ngtgmp   10/09/2017 Início do desenvolvimento
*		0.02   ngtgmp   21/09/2017 Implementação de mais funções
*		0.03   ngtgmp   27/09/2017 Preparo para os testes automatizados e revisão do código
*
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include"listas.h"
/***********************************************************************
*
*  $TC Tipo de dados: LIS Descritor de Lista
*
*
*  $ED Descrição do tipo
*     Descreve a organização dos Nós em uma Lista
*
***********************************************************************/
typedef struct node
{
	struct node* next;	//Aposta para o próximo nó
	struct node* prev;  //Aponta para o nó anterior
	void* val;			//Aponta para variável
}Node;
/***********************************************************************
*
*  $TC Tipo de dados: LIS Descritor de Lista
*
*
*  $ED Descrição do tipo
*     Descreve a organização de uma Lista pelo cabeçalho. Pode-se fazer Listas de Listas.
*
***********************************************************************/
typedef struct list
{
	Node* first;  //Aponta para o primeiro nó
	Node* last;	  //Aponta para o último nó
	Node* cursor; //Aponta para o nó cursor
}List;
/***************************************************************************
*
*  Função: LIS create list
*  ****/
LIS_tpCondRet createList(List** l){ (*l) = (List*) calloc(1, sizeof(List)); if(!l) return LIS_CondRetFaltouMemoria; (*l)->first = NULL; (*l)->last = NULL; (*l)->cursor = NULL; return LIS_CondRetOK; }
/* Fim função: LIS criar lista */
/***************************************************************************
*
*  Função: LIS push back
*  ****/
LIS_tpCondRet push_back(List* l, void* val)
{
	Node* Nnode;
	Nnode = (Node*) calloc (1, sizeof(Node));
	if(!Nnode)
		return LIS_CondRetFaltouMemoria;
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
	return LIS_CondRetOK;
} /* Fim função: LIS criar lista */
/***************************************************************************
*
*  Função: LIS push front
*  ****/
LIS_tpCondRet push_front(List* l, void* val)
{
	Node* Nnode;
	Nnode = (Node*) calloc(1, sizeof(Node));
	if(!Nnode)
		return LIS_CondRetFaltouMemoria;
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
	return LIS_CondRetOK;
} /* Fim função: LIS criar lista */
/***************************************************************************
*
*  Função: LIS pop back
*  ****/
LIS_tpCondRet pop_back(List* l, void** val)
{
	if(l->first == NULL) { printf("\n\n <!><!><!> Lista Vazia! <!><!><!> \n\n"); return LIS_CondRetListaVazia; }

	*val = l->last->val;

	if (l->first == l->last)
	{
		l = NULL;
		return LIS_CondRetListaVazia;
	}
	if(l->cursor == l->last)
		l->cursor = l->last->prev;
	l->last = l->last->prev;
	l->last->next = NULL;
	return LIS_CondRetOK;
} /* Fim função: LIS criar lista */
/***************************************************************************
*
*  Função: LIS pop front
*  ****/
LIS_tpCondRet pop_front(List* l, void** val)
{
	if(l->first == NULL) { printf("\n\n <!><!><!> Lista Vazia! <!><!><!> \n\n"); return LIS_CondRetListaVazia; }

	*val = l->first->val;

	if (l->first == l->last)
	{
		l = NULL;
		return LIS_CondRetListaVazia;
	}
	if(l->cursor == l->first)
		l->cursor = l->first->next;
	l->first = l->first->next;
	l->first->prev = NULL;
	return LIS_CondRetOK;
} /* Fim função: LIS criar lista */
/***************************************************************************
*
*  Função: LIS list size
*  ****/
LIS_tpCondRet list_size(List* l, unsigned int size)
{
	size = 0;
	Node* Tnode = l->first;
	if(l->first == NULL)
		return 0;
	while(Tnode != l->last)
		size++;
	return LIS_CondRetOK;
} /* Fim função: LIS list size */
/***************************************************************************
*
*  Função: LIS next
*  ****/
LIS_tpCondRet next(List* l)
{
	if(l->first == NULL) { printf("\n\n <!><!><!> Lista Vazia! <!><!><!> \n\n");}
	else if(l->cursor->next == NULL)
	{
		printf("\n\n <!> Cursor posicionado no final da lista <!> \n\n");
		return LIS_CondRetCursorNoFinal;
	}
	else l->cursor = l->cursor->next;
	return LIS_CondRetOK;
} /* Fim função: LIS next */
/***************************************************************************
*
*  Função: LIS prev
*  ****/
LIS_tpCondRet prev(List* l)
{
	if(l->first == NULL) { printf("\n\n <!><!><!> Lista Vazia! <!><!><!> \n\n");}
	else if(l->cursor->prev == NULL)
	{
		printf("\n\n <!> Cursor posicionado no inicio da lista <!> \n\n");
		return LIS_CondRetCursorNoInicio;
	}
	else l->cursor = l->cursor->prev;
	return LIS_CondRetOK;
} /* Fim função: LIS prev */
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
	
	pop_back(l, &b);
	c = (int*) b;

	printNodeValue(l->cursor);
    printf("\n%d", *c);
	prev(l);
	printf("\n");
	printNodeValue(l->cursor);

	system("pause");

	return 0;
}
