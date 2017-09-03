/***************************************************************************
*
*  $MCI Módulo de definição: Módulo Disciplina
*
*  Arquivo gerado:              disciplina.C
*  Letras identificadoras:      DIS
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 4
*  Autores: mrol - Matheus Rodrigues de Oliveira Leal
*                - Leonardo Abreu Santos
*	          ngtgmp - Felipe Nogueira de Souza
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data      Observações
*       0.01   mrol   30/08/2017  Início do desenvolvimento
*       0.02 ngtgmp   01/092017
*       0.03 mrol     03/092017   Funções básicas implementadas e funcionando
***************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "disciplina.h"
#define MAX_NOME 25
#define MAX_CODIGO 8
#define MAX_BIBLIOGRAFIA 300
#define MAX_EMENTA 300
/***********************************************************************
*
*  $TC Tipo de dados: DIS Descritor de Disciplina
*
*
*  $ED Descrição do tipo
*     Descreve a organização de uma Disciplina
*
***********************************************************************/
struct disciplina{
  char *nome;
  char *codigo;
  int creditos;
  char *bibliografia;
  char *ementa;
};

/*****  Dados encapsulados no módulo  *****/

Disciplina *d = NULL;

/*****  Código das funções exportadas pelo módulo  *****/
/***************************************************************************
*
*  Função: Cria disciplina
*  ****/
DIS_tpCondRet DIS_cria_Disciplina(void)
{
  d = (Disciplina *) malloc(sizeof(Disciplina));
  if(d == NULL)
		return DIS_CondRetFaltouMemoria;
  return DIS_CondRetOK;
}/* Fim função: DIS cria */
/***************************************************************************
*
*  Função: DIS exibe
*  ****/
DIS_tpCondRet DIS_exibe(void){
  if (d != NULL){
    printf("NOME: %s - CODIGO: %s - CREDITOS: %d - BIBLIOGRAFIA: %s - EMENTA: %s\n",d->nome, d->codigo, d->creditos, d->bibliografia,d->ementa);
    return DIS_CondRetOK;
  }
  return DIS_CondRetErroEstrutura;
} /* Fim função: DIS exibe */
/***************************************************************************
* ngtgmp
*
*  Função: DIS ler ementa
*  ****/
char *DIS_le_ementa(void){
  char *ementa = (char *)malloc(MAX_EMENTA*sizeof(char));
  if(ementa == NULL)  { exit(1);  }
  printf("Digite a ementa\n");
  scanf(" %MAX_EMENTAs", ementa);
  return ementa;
} /* Fim função: DIS ler bibliografia */
/***************************************************************************
*
*  Função: DIS ler creditos
*  ****/
int DIS_le_creditos(void){
  int cred;
  printf("Digite a quantidade de creditos:\n");
  scanf("%d", &cred);
  return cred;
} /* Fim função: DIS ler creditos */
/***************************************************************************
*
*  Função: DIS ler nome
*  ****/
char* DIS_le_nome(void){
  char *n = (char *)malloc(300*sizeof(char));
  if(n == NULL)
  {
    printf("Espaço em memória insuficiente\n");
    exit(-1);
  }
  printf("Digite o nome\n");
  scanf(" %300[^\n]s", n);
  return n;
} /* Fim função: DIS ler creditos */
/***************************************************************************
*
*  Função: DIS ler bibliografia
*  ****/
char *DIS_le_Bib(void){
  char *n = (char *)malloc(MAX_BIBLIOGRAFIA*sizeof(char));
  if(n == NULL)
  {
    printf("Espaço em memória insuficiente\n");
    exit(1);
  }
  printf("Digite a bibliografia\n");
  scanf(" %MAX_BIBLIOGRAFIA[^\n]s", n);
  return n;
} /* Fim função: DIS ler bibliografia */
/***************************************************************************
*
*  Função: DIS ler codigo
*  ****/
char* DIS_le_codigo(void) 				/* Codigo da disciplina no padrão inf0000 */
{
  char* cod1 = (char*)malloc(MAX_CODIGO * sizeof(char)); 	/*cod1 = prefixo*/
  char* cod2 [5];
  if (cod1 == NULL)
  {
    printf("Memoria insuficiente!\n\n");
    return DIS_CondRetErroEstrutura;
  }
  strcat(cod1, "inf");
	
  printf("\n\nDigite o código numerico da disciplina:\n");
  scanf("%4s", cod2); 				/* O usuario digitará apenas a parte numerica do codigo (4 Numerais no caso)*/
  /*ngtgmp - não deixa o usuário escrever algo que não sejam numerais*/
  while(cod2[0]<48 || cod2[0]>57 ||cod2[1]<48 || cod2[1]>57 || cod2[2]<48 || cod2[2]>57 || cod2[3]<48 || cod2[3]>57)
  {
    printf("Selecione caracteres validos (0 >= x <=9):");
  }

  strcat(cod1, cod2);	  			/* Concatena "inf" + 4 numerais no máximo */

  free(cod2);

  return cod1;
}/* Fim função: DIS ler codigo  */
/***************************************************************************
*
*  Função: DIS obter bibliografia
*  ****/
 DIS_tpCondRet DIS_get_bibliografia(char* bibliografia) {
	if (d->bibliografia)
	{
		bibliografia = (char*) malloc(MAX_BIBLIOGRAFIA*sizeof(char));
		if(bibliografia == NULL)
		{
			printf("Memoria insuficiente");
			exit(1);
		}
		strcpy(bibliografia, d->bibliografia);
		return DIS_CondRetOK;
	}
	return DIS_CondRetErroEstrutura;
}/* Fim função: DIS obter bibliografia */
/***************************************************************************
*
*  Função: DIS obter codigo
*  ****/
DIS_tpCondRet DIS_get_codigo(char* codigo)
{
	if (d->codigo)
	{
		codigo = (char*) malloc (MAX_CODIGO*sizeof(char));
			if(codigo == NULL)
			{
				printf("Memoria insuficiente");
				exit(1);
			}
		strcpy(codigo, d->codigo);
		return DIS_CondRetOK;
	}
	return DIS_CondRetErroEstrutura;
}/* Fim função: DIS obter codigo */
/***************************************************************************
*
*  Função: DIS obter nome
*  ****/
DIS_tpCondRet DIS_get_nome(char* nome)
{
  if(d->nome){
   nome = (char*) malloc (MAX_NOME*sizeof(char));
   if(nome == NULL)
   {
     printf("Memoria insuficiente");
     exit(1);
   }
   strcpy(nome,d->nome);
   return DIS_CondRetOK;
  }
  return DIS_CondRetErroEstrutura;
}/* Fim função: DIS obter nome */
/***************************************************************************
*
*  Função: DIS obter ementa
*  ****/
DIS_tpCondRet DIS_get_ementa(char* ementa)
{
  if(d->ementa)
  {
	ementa = (char*) malloc (MAX_EMENTA*sizeof(char));
	if(ementa == NULL)
	{
		printf("Memoria insuficiente");
		exit(1);
	}
	strcpy(ementa, d->ementa);
	return DIS_CondRetOK;
  }
  return DIS_CondRetErroEstrutura;
}/* Fim função: DIS obter ementa */
/*************************************************************************
*  ngtgmp
*
*  Função: DIS gera uma disciplina por input do teclado
*  ****/
DIS_tpCondRet DIS_gera_cmd(void)
{
  int i = DIS_cria_Disciplina();
  if(i == DIS_CondRetFaltouMemoria)
	return DIS_CondRetFaltouMemoria;

  d->creditos = DIS_le_creditos();
  d->bibliografia = DIS_le_Bib();
  d->nome = DIS_le_nome();
  d->codigo = DIS_le_codigo();
  d->ementa = DIS_le_ementa();

  return DIS_CondRetOK;
}/* Fim função: DIS gera uma disciplina por input do teclado */
/*************************************************************************
*  ngtgmp
*
*  Função: DIS gera uma disciplina recebendo parâmetros externos
*  ****/
DIS_tpCondRet DIS_gera_param(char* nome, char* codigo, int creditos, char* bibliografia, char* ementa)
{
  int i = DIS_cria_Disciplina();
  if(i == DIS_CondRetFaltouMemoria)
		return DIS_CondRetFaltouMemoria;

  d->nome = (char*)malloc(sizeof(nome));
  if(d->nome == NULL)
	  return DIS_CondRetFaltouMemoria;
  strcpy(d->nome, nome);
  d->codigo = (char*)malloc(sizeof(codigo));
  if(d->codigo == NULL)
	  return DIS_CondRetFaltouMemoria;
  strcpy(d->codigo, codigo);
  d->creditos = creditos;
  d->bibliografia = (char*)malloc(sizeof(bibliografia));
  if(d->bibliografia == NULL)
	  return DIS_CondRetFaltouMemoria;
  strcpy(d->bibliografia, bibliografia);
  d->ementa = (char*)malloc(sizeof(ementa));
  if(d->ementa == NULL)
	  return DIS_CondRetFaltouMemoria;
  strcpy(d->ementa, ementa);
	
  return DIS_CondRetOK;
}/* Fim função: DIS gera uma disciplina recebendo parâmetros externos */
