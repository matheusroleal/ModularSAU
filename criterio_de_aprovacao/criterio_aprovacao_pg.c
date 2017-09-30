/***************************************************************************
*
*  $MCI Módulo de definição: Módulo Criterio de Aprovação
*
*  Arquivo gerado:              Criterio_Aprovacao.C
*  Letras identificadoras:      CRI
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 4
*  Autores: 	pg - Pedro Gabriel Serodio Sales
*             SaintL - Leonardo Abreu Santos
*	      			LL - Clayton Lucas Mendes Lima
*	         
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data      Observações
*       0.01 pg    29/09/2017  Início do desenvolvimento
*       
***************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "criterio_aprovacao.h"
/***** Protótipos das funções encapuladas no módulo *****/
/*
*				A Completar
*
*****  Código das funções exportadas pelo módulo  *****/
/***************************************************************************
*
*  Inicio Função: Verifica_Criterio01
*		Deverá receber as notas G1, G2 do aluno, a média para a aprovação (sem prova final),
*		um ponteiro para gurdar a média final do aluno e outro para guardar se foi aprovado ou não.
*
*  ****/
CRI_tpCondRet CRI_Verifica_Criterio01(float G1, float G2, float *media_aluno, float media_aprovado, int *resultado ){
	if(G2<3){
		*media_aluno= (G1+(G2*3))/4;
	}
	else{  
		*media_aluno= ((G1*2)+(G2*3))/5;
	}
	if((*media_aluno)>=media_aprovado){
		*resultado=1;
		return CRI_CondRetOK;
	}
	else {
		*resultado=0;
		return CRI_CondRetOK;
	}
} /* Fim função: Verifica_Criterio01 
*
*		Retorna se o aluno foi aprovado ou não, e
*		qual foi a média final dele para o critério 1.
*/
/***************************************************************************
*
*  Inicio Função: Aplica Critério
*		Deverá receber o número do criterio a ser aplicado, os graus, a media para aprovação,
*	 e depois ponteiros, um para guardar sua média final e outro para guardar se foi aprovado ou não.
*
*  ****/
CRI_tpCondRet CRI_Aplica_Criterio(float G1, float G2, float G3, float *media_aluno, float media_aprovado, int *resultado, int num_criterio){
	switch(num_criterio){
		case 1:
			CRI_Verifica_Criterio01(G1,G2,media_aluno,media_aprovado,resultado);
			break;
	}
	return CRI_CondRetOK;
}
/* Fim função: Aplica Critério
*
*		Retorna se o aluno foi aprovado ou não, e
*		qual foi a média final dele para o critério inserido.
*/
