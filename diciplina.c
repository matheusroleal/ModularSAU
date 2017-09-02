/***************************************************************************
*
*  $MCI Módulo de definição: Módulo Diciplina
*
*  Arquivo gerado:              diciplina.C
*  Letras identificadoras:      DIC
*
*  Nome da base de software:    
*  Arquivo da base de software: 
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 4
*  Autores: mrol - Matheus Rodrigues de Oliveira Leal
*                - Leonardo Abreu Santos
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data      Observações
*       0.01   mrol   30/08/2017  Início do desenvolvimento
*      
***************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "diciplina.h"

/***********************************************************************
*
*  $TC Tipo de dados: DIC Descritor de diciplina
*
*
*  $ED Descrição do tipo
*     Descreve a organização de uma diciplina
*
***********************************************************************/

struct diciplina{
  char *nome;
  char codigo[7];
  int creditos;
  char *bibliografia;
};

/***************************************************************************
*
*  Função: DIC ler codigo
*  ****/
char* DIC_le_codigo(void) 				/* Codigo da disciplina no padrão inf0000 */
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

	scanf("%4s", cod2); 				/* O usuario digitará apenas a parte numerica do codigo (4 Numerais no caso)*/

	strcat(cod1, cod2);	  			/* Concatena "inf" + 4 numerais no máximo */

	free(cod2);

	return cod1;
}
}/* Fim função: DIC ler nome */

/***************************************************************************
*
*  Função: DIC obter codigo
*  ****/
DIC_tpCondRet DIC_get_codigo(Diciplina *d, char *codigo) {
	if (d->codigo)
	{
		strcpy(codigo, d->codigo);
		return DIC_CondRetOK;
	}
	return DIC_CondRetErroEstrutura;
}
/* Fim função: DIC obter nome */

/***************************************************************************
*
*  Função: DIC obter nome
*  ****/
DIC_tpCondRet DIC_get_nome(Diciplina *d, char *nome){
  if(d->nome){
   strcpy(nome,d->nome);
   return DIC_CondRetOK;
  }
  return DIC_CondRetErroEstrutura;
}/* Fim função: DIC obter nome */



