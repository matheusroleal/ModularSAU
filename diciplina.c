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
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       0.01   mrol   30/08/2017 Início do desenvolvimento
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
*  Função: DIC obter nome
*  ****/
DIC_tpCondRet DIC_get_nome(Diciplina *d, char *nome){
  if(d->nome){
   strcpy(nome,d->nome);
   return DIC_CondRetOK;
  }
  return DIC_CondRetErroEstrutura;
}/* Fim função: DIC obter nome */



