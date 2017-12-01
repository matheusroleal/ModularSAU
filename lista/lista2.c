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
*		0.04   ngtgmp   01/10/2017 Reparos após testes e revisão
*
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define LISTA_OWN
#include "listas.h"
#undef LISTA_OWN

/***********************************************************************
*
*  $TC Tipo de dados: LIS Descritor de Lista
*
*
*  $ED Descrição do tipo
*     Descreve a organização dos Nós em uma Lista
*
***********************************************************************/
struct node
{
  #ifdef _DEBUG

  	List pCabeca ;
  	/* Ponteiro para cabeca
  	*
  	*$ED Descrição
  	*   Todos os nós da lista devem apontar para a respectiva cabeça.
  	*   Esse ponteiro corresponde a um identificador da lista para fins
  	*   de verificação da integridade. */

  	char Tipo ;
  	/* Tipo do elemento */

  #endif

	struct node* next;	//Aponta para o próximo nó
	struct node* prev;  //Aponta para o nó anterior
	void* val;			//Aponta para variável val
};
/***********************************************************************
*
*  $TC Tipo de dados: LIS Descritor de Lista
*
*
*  $ED Descrição do tipo
*     Descreve a organização de uma Lista pelo cabeçalho. Pode-se fazer Listas de Listas.
*
***********************************************************************/
struct list
{
	Node* first;  //Aponta para o primeiro nó
	Node* last;	  //Aponta para o último nó
	Node* cursor; //Aponta para o nó cursor

  #ifdef _DEBUG
    char Tipo ;
    /* Tipo do elemento */
  #endif
};

/*****  Dados encapsulados no módulo  *****/
#ifdef _DEBUG

static char EspacoLixo[ 256 ] =
	"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" ;
/* Espaço de dados lixo usado ao testar */

#endif
/***************************************************************************
*
*  Função: LIS create list
*  ****/
LIS_tpCondRet createList(List** l){
	(*l) = (List*) calloc(1, sizeof(List));
	if(!l)
		return LIS_CondRetFaltouMemoria;

	(*l)->first = NULL;
	(*l)->last = NULL;
	(*l)->cursor = NULL;

  #ifdef _DEBUG
  	(*l)->Tipo = LIS_TipoEspacoCabeca;
  	CED_DefinirTipoEspaco(pLista , LIS_TipoEspacoCabeca) ;
  #endif

	return LIS_CondRetOK;
}
/* Fim função: LIS create lista */
/***************************************************************************
*
*  Função: LIS del
*  ****/
LIS_tpCondRet del(List* l)
{
	Node* tnode = l->first;
	l->cursor = l->first;
	while(tnode != NULL)
	{
		l->cursor = l->cursor->next;
		free(tnode);
		tnode = l->cursor;
	}
	free(l);
	return LIS_CondRetOK;
}/* Fim função: LIS del */
/***************************************************************************
*
*  Função: LIS clear
*  ****/
LIS_tpCondRet clear(List* l)
{
	Node* tnode = l->first;
	l->cursor = l->first;
	while(tnode != NULL)
	{
		l->cursor = l->cursor->next;
		free(tnode);
		tnode = l->cursor;
	}
	l->first = NULL;
	l->last = NULL;
	l->cursor = NULL;
	return LIS_CondRetOK;
}/* Fim função: LIS del */
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

  #ifdef _DEBUG
	   Nnode->pCabeca = (*l);
     Nnode->Tipo = LIS_TipoEspacoNo;
	   CED_DefinirTipoEspaco(pElem , LIS_TipoEspacoNo) ;
  #endif

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
} /* Fim função: LIS push back */
/***************************************************************************
*
*  Função: LIS push front
*  ****/
LIS_tpCondRet push_front(List* l, void* val)
{
	Node* Nnode;

  #ifdef _DEBUG
      void * PonteiroVoid = NULL ;
      int TipoEspaco = -1 ;
      int Retorno = -1 ;
  #endif

	Nnode = (Node*) calloc(1, sizeof(Node));
	if(!Nnode)
		return LIS_CondRetFaltouMemoria;
	Nnode->val = val;
	Nnode->prev = NULL;

  #ifdef _DEBUG
	   Nnode->pCabeca = (*l);
     Nnode->Tipo = LIS_TipoEspacoNo;
	   CED_DefinirTipoEspaco(pElem , LIS_TipoEspacoNo) ;
  #endif

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

  #ifdef _DEBUG
      PonteiroVoid = (void *)(*l) ;
      TipoEspaco = CED_ObterTipoEspaco(PonteiroVoid) ;

      PonteiroVoid = (void *)Nnode ;
      CED_DefinirTipoEspaco(PonteiroVoid, TipoEspaco) ;

      PonteiroVoid = (void *)val ;
      Retorno = CED_DefinirTipoEspaco(PonteiroVoid, TipoEspaco) ;
  #endif

	return LIS_CondRetOK;
} /* Fim função: LIS push front */
/***************************************************************************
*
*  Função: LIS pop back
*  ****/
LIS_tpCondRet pop_back(List* l, void** val)
{
	Node* tnode;
	if(l->first == NULL) {
		/* Lista Vazia! */
		return LIS_CondRetListaVazia;
	}

	*val = l->last->val;

	if (l->first == l->last)
	{
		l->first = NULL;
		l->last = NULL;
		l->cursor = NULL;
		return LIS_CondRetOK;
	}
	if(l->cursor == l->last)
		l->cursor = l->last->prev;
	tnode = l->last;
	l->last = l->last->prev;
	l->last->next = NULL;
	tnode->prev = NULL;
	return LIS_CondRetOK;
} /* Fim função: LIS pop back */
/***************************************************************************
*
*  Função: LIS pop front
*  ****/
LIS_tpCondRet pop_front(List* l, void** val)
{
	Node* tnode;
	if(l->first == NULL) {
		/* Lista Vazia! */
		return LIS_CondRetListaVazia;
	}

	*val = l->first->val;

	if (l->first == l->last)
	{
		l->first = NULL;
		l->last = NULL;
		l->cursor = NULL;
		return LIS_CondRetOK;
	}
	if(l->cursor == l->first)
		l->cursor = l->first->next;
	tnode = l->first;
	l->first = l->first->next;
	l->first->prev = NULL;
	tnode->next = NULL;
	return LIS_CondRetOK;
} /* Fim função: LIS pop front */
/***************************************************************************
*
*  Função: LIS pop cursor
*  ****/
LIS_tpCondRet pop_cursor(List* l, void** val)
{
	Node* tnode;
	if(l->cursor == l->first)
		return pop_front(l, val);
	else if(l->cursor == l->last)
		return pop_back(l, val);
	else
	{
		if(l->first == NULL) {
			/* Lista Vazia! */
			return LIS_CondRetListaVazia;
		}

		*val = l->cursor->val;

		if (l->first == l->last)
		{
		l->first = NULL;
		l->last = NULL;
		l->cursor = NULL;
		return LIS_CondRetOK;
		}
		tnode = l->cursor;
		l->cursor->prev->next = l->cursor->next;
		l->cursor->next->prev = l->cursor->prev;
		l->cursor = l->cursor->next;
		tnode->next = NULL;
		tnode->prev = NULL;
		return LIS_CondRetOK;
		}
} /* Fim função: LIS pop cursor */
/***************************************************************************
*
*  Função: LIS get val cursor
*  ****/
LIS_tpCondRet get_val_cursor(List* l, void** val)
{
	if(l->first == NULL) {
		/* Lista Vazia! */
		return LIS_CondRetListaVazia;
	}
	*val = l->cursor->val;
	return LIS_CondRetOK;
}/* Fim função: LIS get val cursor */
/***************************************************************************
*
*  Função: LIS list size
*  ****/
LIS_tpCondRet list_size(List* l, unsigned int* size)
{
	Node* Tnode = l->first;
	if(l->first == NULL)
		return LIS_CondRetListaVazia;
	*size = 0;
	while(Tnode != NULL)
	{
		Tnode = Tnode->next;
		*size = *size +1;
	}
	return LIS_CondRetOK;
} /* Fim função: LIS list size */

/***************************************************************************
*
*  Função: LIS first
*  ****/
LIS_tpCondRet first(List* l){
	if(l->first == NULL) {
		/* Lista Vazia! */
		return LIS_CondRetListaVazia;
	}
	l->cursor = l->first;
	return LIS_CondRetOK;
}


/***************************************************************************
*
*  Função: LIS next
*  ****/
LIS_tpCondRet next(List* l)
{
	if(l->first == NULL) {
		/* Lista Vazia! */
		return LIS_CondRetListaVazia;
	}
	else if(l->cursor->next == NULL)
	{
		/* Cursor ja posicionado no final da lista */
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
	if(l->first == NULL) {
		/* Lista Vazia! */
		return LIS_CondRetListaVazia;
	}
	else if(l->cursor->prev == NULL)
	{
		/* Cursor ja posicionado no inicio da lista */
		return LIS_CondRetCursorNoInicio;
	}
	else l->cursor = l->cursor->prev;
	return LIS_CondRetOK;
} /* Fim função: LIS prev */

#ifdef _DEBUG
/***************************************************************************
*
*  Função: ARV  &Verificar um nó de estrutura
*  ****/

   LIS_tpCondRet VerificarNo( void* pNoParm )
   {

      List* pNo = NULL;

      /* Verificar se é nó estrutural */

         if ( pNoParm == NULL )
         {
          //  TST_NotificarFalha( "Tentou verificar nó inexistente." ) ; Não sabemos o uso disto e se é necessário.
            return LIS_CondRetErroEstrutura ;

         }

	  /* Verificar se é nó corrente */

		 if (pNoParm->cursor == NULL)
		 {

			return LIS_CondRetErroEstrutura ;
		 }

	  /* Verificar se é nó anterior se o nó não for o primeiro */

		if ( pNoParm->cursor != pNoParm->first && pNoParm->cursor->prev == NULL )
		{
			return LIS_CondRetErroEstrutura ;
		}

	  /* Verificar se é nó próximo se o nó não for o último */

		if ( pNoParm->cursor != pNoParm->last && pNoParm->cursor->next == NULL )
		{
			return LIS_CondRetErroEstrutura ;
		}

	  /* Verificar se é o primeiro nó */

		if ( pNoParm->first == NULL )
		{
			return LIS_CondRetErroEstrutura ;
		}

	  /* Verificar se é o último nó */

		if ( pNoParm->last == NULL )
		{
			return LIS_CondRetErroEstrutura ;
		}

		// Teriamos ainda que verificar se os nós apontam para lixo?

#endif

#ifdef _DEBUG
/***************************************************************************
*
*  Função: ARV  &Deturpar lista
*  ****/

void LIS_Deturpar( void * pListParm ,
                      LIS_tpModosDeturpacao ModoDeturpar )
{
	   List * pList = NULL ;

      if ( pListParm == NULL )
      {
         return ;
      } /* if */

      pList = ( List * )( pListParm ) ;

	  switch ( ModoDeturpar )
	  {

	  /* Anula ponteiro corrente */

         case DeturpaCursorNulo :
         {

            pList->cursor = NULL ;

            break ;

         } /* fim ativa: Anula ponteiro corrente */

      /* Anula ponteiro final */

         case DeturpaLastNulo :
         {

            pList->last = NULL ;

            break ;

         } /* fim ativa: Anula ponteiro final */

	/* Anula ponteiro inicial */

         case DeturpaFirstNulo :
         {

            pList->first = NULL ;

            break ;

         } /* fim ativa: Anula ponteiro inicial */

	/* Anula próximo ponteiro */

         case DeturpaNextNulo :
         {

            pList->cursor->next = NULL ;

            break ;

         } /* fim ativa: Anula próximo ponteiro */

	/* Anula ponteiro anterior */

         case DeturpaPrevNulo :
         {

            pList->cursor->prev = NULL ;

            break ;

         } /* fim ativa: Anula ponteiro anterior */
	  }
		 // Não sabemos se temos que utilizar o Modo Deturpador
}
#endif
