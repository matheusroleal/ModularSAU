/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Criterio de Aprovacao
*
*  Arquivo gerado:              criterio_aprovacao.h
*  Letras identificadoras:      CRI
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 4
*  Autores: pg -Pedro Gabriel Serodio Sales	
*        		SaintL - Leonardo Abreu Santos
*	      		LL - Clayton Lucas Mendes Lima
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       0.01   pg   29/09/2017 Início do desenvolvimento [08:33 PM]
*
*  $ED Descrição do módulo
*     Este módulo implementa um conjunto simples de funções para 
*     explorar os critérios de aprovação do sistema acadêmico
*     Um critério deverá ter um código que o identifica.
*     Cada critério retornará a média final do aluno e se ele foi aprovado ou não
*     
*     
***************************************************************************/
typedef struct criterio Criterio;
/***********************************************************************
*
*  $TC Tipo de dados: CRI Condições de retorno
*
*
***********************************************************************/

   typedef enum {
     CRI_CondRetOK = 0 ,
     /* Executou correto */
     CRI_CondRetFaltouMemoria = 1 ,
     /* Faltou memória ao alocar dados */
   }CRI_tpCondRet;
/***********************************************************************
*
*  $FC Função: CRI Verifica_Criterio01
*
*  $ED Descrição da função
*    Recebe os Graus de um aluno, a media de aprovacao, 
*     retorna se o aluno foi aprovado ou não e a sua média final.
*
***********************************************************************/
CRI_tpCondRet CRI_Verifica_Criterio01(float G1, float G2, float *media_aluno, float media_aprovado, int *resultado);
/***********************************************************************
*
*  $FC Função: CRI Aplica_Credito
*
*  $ED Descrição da função
*    Recebe os Graus de um aluno, a media de aprovacao, e o número do criterio de avaliação e
*     retorna se o aluno foi aprovado ou não e a sua média final para aquele determinado critério.
*
***********************************************************************/
CRI_tpCondRet CRI_Aplica_Criterio(float G1, float G2, float G3, float *media_aluno, float media_aprovado, int *resultado, int num_criterio);
/***********************************************************************/
