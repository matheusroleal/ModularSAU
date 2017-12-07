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
*  Função: LIS  &Verificar a estrutura de uma lista
*  ****/

   LIS_tpCondRet VerificarNo( void* pNoParm )
   {

      Node* No_Lixo = NULL ;   // No usado para verificacao de Lixo dentro dos Nos
      Node* Prev = NULL ;      // No usado para verificacao de encadeamento do No anterior
      Node* Next = NULL ;      // No usado para verificacao de encadeamento do No posterior
      int Incrementador = 0 ;
      List* pNo = NULL ;

      pNo = ( List * )( pNoParm ) ;

      if( pNo->first != pNo->cursor ) // 
      {

      		Prev = pNo->cursor->prev;

      }

      if( pNo->last != pNo->cursor )
      {

      		Next = pNo->cursor->next;

      }

      while(pNo->cursor != NULL)
      {
      
      /* Verificar se é nó estrutural */

         if ( pNoParm == NULL )
         {
			CNT_CONTAR ("LIS_VerificaListaNula");
			printf("Lista recebida aponta para NULL!\n\n");
            		Incrementador++;

         }

	  /* Verificar se o cabeça aponta para o mesmo tipo do corrente */

		 if (CED_ObterTipoEspaco(pNo) != CED_ObterTipoEspaco(pNo->cursor) )
		 {
			CNT_CONTAR ("LIS_VerificaTipoCabeca");
			printf("No corrente aponta para um tipo diferente do no cabeca!\n\n");
			Incrementador++;

		 }

	  /* Verificar se é nó corrente */

		 if (pNo->cursor == NULL)
		 {
			CNT_CONTAR ("LIS_VerificaCorrenteNulo");
			printf("No corrente aponta para NULL!\n\n");
			Incrementador++;

		 }

	  /* Verificar se é nó anterior se o nó não for o primeiro */

		if ( pNo->cursor != pNo->first && pNo->cursor->prev == NULL )
		{
			CNT_CONTAR ("LIS_VerificaPrevNulo");
			printf("Ponteiro para no anterior aponta para NULL!\n\n");
			Incrementador++;

		}

	  /* Verificar se é nó próximo se o nó não for o último */

		if ( pNo->cursor != pNo->last && pNo->cursor->next == NULL )
		{
			CNT_CONTAR ("LIS_VerificaNextNulo");
			printf("Ponteiro para o proximo no aponta para NULL!\n\n");
			Incrementador++;

		}

	  /* Verificar se é o primeiro nó */

		if ( pNo->first == NULL )
		{
			CNT_CONTAR ("LIS_VerificaFirstNulo");
			printf("Primeiro no aponta para NULL!\n\n");
			Incrementador++;

		}

	  /* Verificar se é o último nó */

		if ( pNo->last == NULL )
		{
			CNT_CONTAR ("LIS_VerificaLastNulo");
			printf("Ultimo no aponta para NULL!\n\n");
			Incrementador++;

		}
		
		No_Lixo = ( Node * ) EspacoLixo ;		

	  /* Verificar se o nó corrente é lixo */

		 if (pNo->cursor == No_Lixo)
		 {
			CNT_CONTAR ("LIS_VerificaCorrenteLixo");
			printf("No corrente aponta para Lixo!\n\n");
			Incrementador++;

		 }

	  /* Verificar se é nó anterior se o nó não for o primeiro */

		if ( pNo->cursor != pNo->first && pNo->cursor->prev == No_Lixo )
		{
			CNT_CONTAR ("LIS_VerificaPrevLixo");
			printf("Ponteiro para no anterior aponta para Lixo!\n\n");
			Incrementador++;

		}

	  /* Verificar se é nó próximo se o nó não for o último */

		if ( pNo->cursor != pNo->last && pNo->cursor->next == No_Lixo )
		{
			CNT_CONTAR ("LIS_VerificaNextLixo");
			printf("Ponteiro para o proximo no aponta para Lixo!\n\n");
			Incrementador++;

		}

	  /* Verificar se é o primeiro nó */

		if ( pNo->first == No_Lixo )
		{
			CNT_CONTAR ("LIS_VerificaFirstLixo");
			printf("Primeiro no aponta para Lixo!\n\n");
			Incrementador++;

		}

	  /* Verificar se é o último nó */

		if ( pNo->last == No_Lixo )
		{
			CNT_CONTAR ("LIS_VerificaLastLixo");
			printf("Ultimo no aponta para Lixo!\n\n");
			Incrementador++;

		}
		
	      /* Casos de Encadeamento */
	      
	  /* Verificar se o nó anterior ao próximo é o nó corrente */

		if (  pNo->cursor != pNo->last && Next != NULL && Next->prev != pNo->cursor )
		{
			CNT_CONTAR ("LIS_VerificaProximoDesencadeado");
			printf("O no anterior do proximo nao e o no corrente!\n\n");
			Incrementador++;

		}
		
	   /* Verifica se o próximo no ao anterior  o nó corrente */ 

		if (  pNo->cursor != pNo->first && Prev != NULL && Prev->next != pNo->cursor )
		{
			CNT_CONTAR ("LIS_VerificaAnteriorDesencadeado");
			printf("O proximo no do anterior nao e o no corrente!\n\n");
			Incrementador++;

		}
	
	      /* Verifica se o no que nao tem anterior é o primeiro nó */
	      
		if ( pNo->cursor->prev == NULL )
		{
			if ( pNo->first != pNo->cursor )
			{

				CNT_CONTAR("LIS_VerificaFirstDesencadeado");
				printf("O no que nao tem anterior nao e o primeiro no!\n\n");
			        Incrementador++;
	
			}
		

		}

	      /* Verifica se o nó que não tem posterior é o último nó */
	      
		if ( pNo->cursor->next == NULL )
		{
			if ( pNo->last != pNo->cursor )
			{

				CNT_CONTAR("LIS_VerificaLastDesencadeado");
				printf("O no que nao tem posterior nao e o ultimo no!\n\n");
			        Incrementador++;
	
			}
		

		}

		pNo->cursor=pNo->cursor->next;
	}

	if (Incrementador == 0 )
	{
		
		return LIS_CondRetOK ;	

	}
	
	return LIS_CondErroEstrutura ;
  
 }

#endif

#ifdef _DEBUG
/***************************************************************************
*
*  Função: LIS  &Deturpar lista
*  ****/

void LIS_Deturpar( void * pListParm, LIS_tpModosDeturpacao ModoDeturpar )
{
	   List * pList = NULL ;


      if ( pListParm == NULL )
      {
         return LIS_CondRetListaVazia ;
      } /* if */

      pList = ( List * )( pListParm ) ;

	  switch ( ModoDeturpar )
	  {
		 /* Deturpa Tipo do No */

		 case DeturpaTipoNo :
		 {

		    pList->cursor->Tipo = 'f' ;

		    break ;

		 } /* fim ativa: Deturpa Tipo do No */
		
		  /* Anula ponteiro corrente */

		 case DeturpaCursorNulo :
		 {
		 	if ( pList->cursor == NULL )
			{

				return LIS_CondRetCursorNulo ;

			}

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
		 	if ( pList->cursor == NULL )
			{

				return LIS_CondRetCursorNulo ;

			}

		    	pList->cursor->next = NULL ;

		    break ;

		 } /* fim ativa: Anula próximo ponteiro */

		/* Anula ponteiro anterior */

		 case DeturpaPrevNulo :
		 {
		 	if ( pList->cursor == NULL )
			{

				return LIS_CondRetCursorNulo ;

			}
		 	pList->cursor->prev = NULL ;

		        break ;

		 } /* fim ativa: Anula ponteiro anterior */
		
		/* Anula valor corrente */

		 case DeturpaValorNulo :
		 {
		 	
		 	pList->cursor->val = NULL ;

		        break ;

		 } /* fim ativa: Anula valor corrente */
		  
		/* Coloca lixo no ponteiro corrente */

		 case DeturpaCursorLixo :
		 {

		    pList->cursor = ( Node * ) EspacoLixo ;

		    break ;

		 } /* fim ativa: Coloca lixo no ponteiro corrente */

	      /* Coloca lixo no ponteiro final */

		 case DeturpaLastLixo :
		 {

		    pList->last = ( Node * ) EspacoLixo ;

		    break ;

		 } /* fim ativa: Coloca lixo no ponteiro final */

		/* Coloca lixo no ponteiro inicial */

		 case DeturpaFirstLixo :
		 {

		    pList->first = ( Node * ) EspacoLixo ;

		    break ;

		 } /* fim ativa: Coloca lixo no ponteiro inicial */

		/* Coloca lixo no  próximo ponteiro */

		 case DeturpaNextLixo :
		 {
		 	if ( pList->cursor == NULL )
			{

				return LIS_CondRetCursorNulo ;

			}
		        pList->cursor->next = ( Node * ) EspacoLixo ;

		        break ;

		 } /* fim ativa: Coloca lixo no próximo ponteiro */

		/* Coloca lixo no ponteiro anterior */

		 case DeturpaPrevLixo :
		 {
		 	if ( pList->cursor == NULL )
			{

				return LIS_CondRetCursorNulo ;

			}
		        pList->cursor->prev = ( Node * ) EspacoLixo ;

		        break ;

		 } /* fim ativa: Coloca lixo no ponteiro anterior */

		/* Desencadeia o nó anterior ao nó corrente */

		 case DeturpaDesencadeiaNoPrev :
		{
			if ( pList->cursor != pList->first )
			{

				pList->cursor->prev->next = NULL;

				break ;

			}

	         } /* fim ativa: Desencadeia o próximo nó do nó corrente */

		/* Desencadeia o próximo nó do nó corrente */

		 case DeturpaDesencadeiaNoNext :
		{
			if ( pList->cursor != pList->last )
			{

				pList->cursor->next->prev = NULL;

				break ;

			}

	        } /* fim ativa: Desencadeia o próximo nó do nó corrente */

		/* Desencadeia o primeiro nó */

		 case DeturpaDesencadeiaFirst :
		{
			if ( pList->cursor == pList->first )
			{

				pList->cursor->prev = ( Node * ) EspacoLixo;

				break ;

			}

	        } /* fim ativa: Desencadeia o primeiro nó */

		/* Desencadeia o ultimo nó */

		 case DeturpaDesencadeiaLast :
		{
			if ( pList->cursor == pList->last )
			{

				pList->cursor->next = ( Node * ) EspacoLixo;

				break ;

			}

	        } /* fim ativa: Desencadeia o ultimo nó */
	
		 /* Atribui valor fora do domínio do espaço */

		 case DeturpaValorLixo :
		 {  
			 
		        pList->cursor->val = ( void * ) EspacoLixo ;

		        break ;
			
		 }
			 
		 /* fim ativa: Atribui valor fora do domínio do espaço */

	}
	return LIS_CondRetOK ;	
}
#endif
