/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Lista
*
*  Arquivo gerado:              listas.h
*  Letras identificadoras:      LIS
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 4
*  Autores: ngtgmp - Felipe Nogueira de Souza
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       0.01   ngtgmp   10/09/2017 Início do desenvolvimento
*		0.02   ngtgmp   21/09/2017 Implementação de mais funções
*		0.03   ngtgmp   27/09/2017 Preparo para os testes automatizados e revisão do código
*
*  $ED Descrição do módulo
*     Este módulo implementa o módulo lista duplamente encadeada para ser utilizada pelos demais módulos do projeto "Sistema Acadêmico da turma 3wb".
*	  Uma lista(list) contém um cabeçalho, com um nó apontanto para o primeiro item da lista, um apontando para o último e outro apontando para o nó cursor.
*	  Nós(node(s)) são estrutura contendo o próximo nó e o anterior (duplamente encadeada) e contém um ponteiro para um valor (void*)
***************************************************************************/

typedef struct node Node;

typedef struct list List;

/***********************************************************************
*
*  $TC Tipo de dados: LIS Condições de retorno
*
*
***********************************************************************/
   typedef enum {
     LIS_CondRetOK = 0 ,
     /* Executou correto */
     LIS_CondRetListaVazia = 1,
     /* Estrutura list está deletada */
     LIS_CondRetFaltouMemoria = 2 ,
     /* Faltou memória ao alocar dados */
     LIS_CondRetCursorNoFinal = 3,
	 /* Impossível obter próximo */
	 LIS_CondRetCursorNoInicio = 4
	 /* Impossível obter anterior*/

   }LIS_tpCondRet;
/***********************************************************************
*
*  $FC Função: LIS create List
*
*  $ED Descrição da função
*    Cria uma lista vazia
*
***********************************************************************/
LIS_tpCondRet createList(List** l);
/***********************************************************************
*
*  $FC Função: LIS push back
*
*  $ED Descrição da função
*    Insere um elemento no final da List
*
***********************************************************************/
LIS_tpCondRet push_back(List* l, void* val);
/***********************************************************************
*
*  $FC Função: LIS push front
*
*  $ED Descrição da função
*    Insere um elemento no começo da List
*
***********************************************************************/
LIS_tpCondRet push_front(List* l, void* val);
/***********************************************************************
*
*  $FC Função: LIS pop back
*
*  $ED Descrição da função
*    Atualiza o parâmetro val, referenciado, para o último elemento da lista, que é removido da mesma.
*
***********************************************************************/
LIS_tpCondRet pop_back(List* l, void** val);
/***********************************************************************
*
*  $FC Função: LIS pop front
*
*  $ED Descrição da função
*    Atualiza o parâmetro val, referenciado, para o primeiro elemento da lista, que é removido da mesma.
*
***********************************************************************/
LIS_tpCondRet pop_front(List* l, void** val);
/***********************************************************************
*
*  $FC Função: LIS pop cursor
*
*  $ED Descrição da função
*    Remove o nó cursor da lista e retorna a referência para seu valor.
*
***********************************************************************/
/*LIS_tpCondRet pop_cursor(List* l, void** val); A fazer - Remove o nó cursor da lista e retorna referência para seu valor. */

/*void prt_cursor(List* l); Depende da estrutura, então não dá pra fazer aqui. */

/*void exclui_cursor(List* l); A fazer - Destrui nó cursor e reposiciona o cursor segundo convenção. */
/***********************************************************************
*
*  $FC Função: LIS list size
*
*  $ED Descrição da função
*    Retorna a quantidade de elementos da lista
*
***********************************************************************/
LIS_tpCondRet list_size(List* l, unsigned int size); //retorna a quantidade de elementos na List
/***********************************************************************
*
*  $FC Função: LIS next
*
*  $ED Descrição da função
*    Atualiza o cursor para o próximo nó
*
***********************************************************************/
LIS_tpCondRet next(List* l);//atualiza o cursor para o próximo nó
/***********************************************************************
*
*  $FC Função: LIS prev
*
*  $ED Descrição da função
*    Atualiza o cursor para o nó anterior
*
***********************************************************************/
LIS_tpCondRet prev(List* l);//atualiza o cursor para o nó anterior
/***********************************************************************
*
*  $FC Função: LIS del
*
*  $ED Descrição da função
*    Deleta uma lista já criada
*
***********************************************************************/
/*void del(List l); A fazer - Deleta toda a lista. */
