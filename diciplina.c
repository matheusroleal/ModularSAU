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
*	  ngtgmp - Felipe Nogueira de Souza
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data      Observações
*       0.01   mrol   30/08/2017  Início do desenvolvimento
*       0.02 ngtgmp   01/092017   
***************************************************************************/

#include "disciplina.h"

/***************************************************************************
*
*  Função: DIS ler bibliografia
*  ****/
char *DIS_le_Bib(void){
  char *n = (char *)malloc(300*sizeof(char));
  if(*n == NULL)
  {
    printf("Espaço em memória insuficiente\n");
    free(n);
    exit(-1);
  }
  printf("Digite a bibliografia\n");
  scanf(" %300[^\n]s", n);
  return n;
} /* Fim função: DIS ler bibliografia */
/***************************************************************************
*
*  Função: DIS obter bibliografia
*  ****/
 DIS_tpCondRet DIS_get_bibliografia(Disciplina d, char* bibliografia) {
	if (d->bibliografia)
	{
		strcpy(bibliografia, d->bibliografia);
		return DIS_CondRetOK;
	}
	return DIS_CondRetErroEstrutura;
}
/* Fim função: DIS obter bibliografia */
/***************************************************************************
*
*  Função: DIS ler codigo
*  ****/
char* DIS_le_codigo(void) 				/* Codigo da disciplina no padrão inf0000 */
{
	char* cod2 = malloc(5 * sizeof(char)); 		/* cod2 = parte numerica */
	if (cod2 == NULL)
	{
		printf("Memoria insuficiente!\n\n");
		exit(-1);
	}

	char* cod1 = (char*)malloc(8 * sizeof(char)); 	/*cod1 = prefixo*/
	if (cod1 == NULL)
	{
		printf("Memoria insuficiente!\n\n");
		exit(-1);
	}

	cod1[0] = 'i';                  		/* "inf" já virá como prefixo do codigo */
	cod1[1] = 'n';
	cod1[2] = 'f';
	cod1[3] = '\0';
	printf("\n\nDigite o código numerico da disciplina:\n");
	scanf("%4s", cod2); 				/* O usuario digitará apenas a parte numerica do codigo (4 Numerais no caso)*/
	/*ngtgmp - não deixa o usuário escrever algo que não sejam numerais*/
	while(cod2[0]<48 || cod2[0]>57 ||cod2[1]<48 || cod2[1]>57 || cod2[2]<48 || cod2[2]>57 || cod2[3]<48 || cod2[3]>57)
	{
		printf("Selecione caracteres validos (0 >= x <=9):")
	}
	
	strcat(cod1, cod2);	  			/* Concatena "inf" + 4 numerais no máximo */

	free(cod2);

	return cod1;
}
}/* Fim função: DIS ler nome */

/***************************************************************************
*
*  Função: DIS obter codigo
*  ****/
DIS_tpCondRet DIS_get_codigo(Disciplina d, char* codigo)
{
	if (d->codigo)
	{
		strcpy(codigo, d->codigo);
		return DIC_CondRetOK;
	}
	return DIC_CondRetErroEstrutura;
}
/* Fim função: DIS obter nome */

/***************************************************************************
*
*  Função: DIS obter nome
*  ****/
DIS_tpCondRet DIS_get_nome(Disciplina d, char* nome)
{
  if(d->nome){
   strcpy(nome,d->nome);
   return DIS_CondRetOK;
  }
  return DIS_CondRetErroEstrutura;
}/* Fim função: DIS obter nome */

/*************************************************************************
*  ngtgmp
*
*  Função: DIS gera uma disciplina por input do teclado
*  ****/
DIS_tpCondRet geraDIS1(Disciplina* d)
{
  d = (Disciplina*) malloc (sizeof(Disciplina));
	if(*d == NULL)
		return DIS_CondRetFaltouMemoria;
  d->nome = DIS_le_nome();
  d->codigo = DIS_le_codigo();
  d->creditos = le_creditos();
  d->bibliografia = le_bibliografia();
  return DIS_CondRetOK;
}

/*************************************************************************
*  ngtgmp
*
*  Função: DIS gera uma disciplina recebendo parâmetros externos
*  ****/
DIS_tpCondRet geraDIS2(Disciplina* d, char* nome, char* codigo, int creditos, char* bibliografia)
{
  d = (Disciplina*) malloc (sizeof(Disciplina));
	if(*d == NULL)
		return DIS_CondRetFaltouMemoria;
  strcpy(d->nome, codigo);
  strcpy(d->codigo, codigo);
  d->creditos = creditos;
  d->bibliografia = le_bibliografia();
  return DIS_CondRetOK;
}


