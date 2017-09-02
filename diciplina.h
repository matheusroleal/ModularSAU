/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Diciplina
*
*  Arquivo gerado:              diciplina.h
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
*  $ED Descrição do módulo
*     Este módulo implementa um conjunto simples de funções para criar e
*      explorar as diciplinas do sistema acadêmico.
*     Uma disciplina deverá ter um código que a identifica.
*     A cada momento o módulo admite no máximo uma única diciplina.
*     Ao iniciar a execução do programa não existe diciplinas.
*     Uma disciplina deverá ter um critério de avaliação, que será um código que se *refere a uma forma de calcular a média final para poder determinar se um aluno *está aprovado ou não.
***************************************************************************/
typedef struct diciplina Diciplina;

/***********************************************************************
*
*  $TC Tipo de dados: DIC Condicoes de retorno
*
*
***********************************************************************/

   typedef enum {

         DIC_CondRetOK = 0 ,
               /* Executou correto */

         DIC_CondRetErroEstrutura = 1 ,
              /* Estrutura da diciplina está errada */

         DIC_CondRetFaltouMemoria = 8
               /* Faltou memória ao alocar dados */

   }DIC_tpCondRet;

/***********************************************************************
*
*  $FC Função: DIC obter nome
*
*  $ED Descrição da função
*    Recebe uma diciplina e retorna o seu nome.
*
***********************************************************************/
char* DIC_le_codigo(void);
DIC_tpCondRet DIC_get_nome(Diciplina* d, char* nome);
DIC_tpCondRet DIC_get_codigo(Diciplina *d, char *codigo);
