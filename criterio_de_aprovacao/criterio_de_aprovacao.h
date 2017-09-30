/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Critério de Avaliação
*
*  Arquivo gerado:              criterio_de_aprovacao.h
*  Letras identificadoras:      CRI
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 4
*  Autores: SaintL - Leonardo Abreu Santos
*               LL _ Clayton Lucas    
*
*
*  $HA Histórico de evolução:
*     Versão   Autor    Data        Observações
*       0.01		    28/09/2017  Início do desenvolvimento
*       0.02    LL          28/09/2017  Critérios 3 e 4
*  $ED Descrição do módulo:
*	  Este módulo implementa um conjunto de funções aritméticas
*	  para calcular a média de um aluno e dizer se o mesmo foi
*	  aprovado ou não.
*     
***************************************************************************/
/***********************************************************************
*
*  $TC Tipo de dados: CRI Condições de retorno
*
*
***********************************************************************/
typedef enum 
{
	CRI_CondRetOK = 0 ,
		/* Executou correto */
	CRI_CondRetErroEstrutura = 1
		/* Estrutura do Critério está errada */

}CRI_tpCondRet;
/***********************************************************************
*
*  $FC Função: CRI criterio 1
*
*  $ED Descrição da função
*	 Aplica o critério de avaliação 1
*	 sobre as notas de um aluno.
*	 Baseado no Criterio 7 da PUC-RIO
*    
*  $Acertiva de Entrada: Recebe 3 Notas (G1, G2, G3)
*
*  $Acertiva de Saída: Retorna situação e média do Aluno
*
***********************************************************************/
CRI_tpCondRet CRI_criterio1(float G1, float G2, float G3, float* media, int* situacao);
/***********************************************************************
*
*  $FC Função: CRI criterio 2
*
*  $ED Descrição da função
*	 Aplica o critério de avaliação 2
*	 sobre as notas de um aluno.
*	 Baseado no Criterio 5 da PUC-RIO
*    
*  $Acertiva de Entrada: Recebe 4 Notas (G1, G2, G3 e G4)
*
*  $Acertiva de Saída: Retorna situação e média do Aluno
*
***********************************************************************/
CRI_tpCondRet CRI_criterio2(float G1, float G2, float G3, float G4, float* media, int* situacao);
