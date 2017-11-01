/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              testedis.c
*  Letras identificadoras:      TDIS
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Pedro Gabriel Serodio Sales - pg
*           Matheus Rodrigues de Oliveira Leal - mrol
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       4.00   mrol  31/10/2017 Adicionar funções de altera
*       3.00   mrol  08/09/2017 Uniformização da interface das funções e
*                               de todas as condições de retorno.
*       2.00   pg   06/09/2017 Eliminação de código duplicado, reestruturação
*       1.00   pg   05/09/2017 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para o teste do
*     módulo disciplina. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo disciplina:
*
*     "=gerainp"        - chama a função DIS_gera_cmd( )
*     "=gerapar" <Char> <Char> <Int> <Char> <Char>
*                   - chama a função DIS_gera_param( <Char> <Char> <Int> <Char> <Char> )
*                     Obs. notação: <Char> <Int> são os valores dos parâmetros
*                     que se encontram no comando de teste.
*
*     "=exibe"      - chama a função DIS_exibe
*
*     "=obterdis" <Struct Disciplina>
*                      - chama a função DIS_get_disciplina
*     "=obtercre" <Struct Disciplina> <INT>
*                      - chama a função DIS_get_creditos
*     "=obterem" <Struct Disciplina> <Char>
*                      - chama a função DIS_get_ementa
*     "=obternome" <Struct Disciplina> <Char>
*                      - chama a função DIS_get_nome
*     "=obtercod" <Struct Disciplina> <Char>
*                      - chama a função DIS_get_codigo
*     "=obterbib" <Struct Disciplina> <Char>
*                      - chama a função DIS_get_bibliografia
*
*     "=destroi" <Struct Disciplina>
*                      - chama a função DIS_deleta_Disciplina( )
*     "=insereturma" <Struct Disciplina> <Struct Turma>
*                      - chama a função DIS_insere_turma()
*     "=limpaturma" <Struct Disciplina>
*                      - chama a função DIS_limpa_turma()
*     "=exibeturma" <Struct Disciplina>
*                      - chama a função DIS_exibe_todas_turmas()
*     "=exibeturma" <Struct Disciplina>
*                      - chama a função DIS_exibe_todas_turmas()
*     "=alteracred" <Struct Disciplina> <Int>
*                      - chama a função DIS_altera_creditos()
*     "=alterabib" <Struct Disciplina> <Char>
*                      - chama a função DIS_altera_bibliografia()
*     "=alteractrapv" <Struct Disciplina> <Int>
*                      - chama a função DIS_altera_criterio()
*     "=alteraementa" <Struct Disciplina> <Char>
*                      - chama a função DIS_altera_ementa()
*
***************************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include    "tst_espc.h"
#include    "generico.h"
#include    "lerparm.h"
//#include    "turma.h"
#include    "disciplina.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define     GERA_INP_DIS_CMD    "=gerainp"
#define     GERA_PAR_DIS_CMD    "=gerapar"
#define     EXIBE_DIS_CMD       "=exibe"
#define     OBTER_CRE_CMD       "=obtercre"
#define     OBTER_EM_CMD        "=obterem"
#define     OBTER_NOME_CMD      "=obternome"
#define     OBTER_COD_CMD       "=obtercod"
#define     OBTER_BIB_CMD       "=obterbib"
#define     DESTROI_CMD         "=destruir"
#define     INSERE_TURMA_DIS    "=insereturma"
#define     LIMPA_TURMA_DIS     "=limpaturma"
#define     EXIBE_TURMA_DIS     "=exibeturma"
#define     ALTERA_BIB_DIS      "=alterabib"
#define     ALTERA_CRED_DIS     "=alteracred"
#define     ALTERA_CRIAPV_DIS   "=alteractrapv"
#define     ALTERA_EMENTA_DIS   "=alteraementa"

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TDIS Efetuar operações de teste específicas para disciplina
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     disciplina sendo testado.
*
*  $EP Parâmetros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/
#define MAX_TUR 5

Turma *turma[MAX_TUR] = { NULL, NULL, NULL, NULL, NULL } ;
Disciplina *dis=NULL;

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      DIS_tpCondRet CondRetObtido  ;
      DIS_tpCondRet CondRetEsperada  ;
                                      /* inicializa para qualquer coisa */



      //char ValorEsperado;
      char ValorDado1Nome[25];
      char ValorDado2Codigo[8];
      int ValorDado3Creditos;
      char ValorDado4Bib[300];
      char ValorDado5Ementa[300];
	  int ValorCriterioAPV;

      int  NumLidos = -1 ;
      char *ValorObtido1;
	  char *ValorEsperado1;
      int ValorEsperado33;
	  int ValorObtido33;
	  int index = 0 ;

      TUR_CriaTurma(turma+index,"33WB",9,13,"Quarta",50);

      /* Testar DIS Gerar discipina por parametros externos */

         if ( strcmp( ComandoTeste , GERA_PAR_DIS_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ssissii" , &ValorDado1Nome, &ValorDado2Codigo, &ValorDado3Creditos , &ValorDado4Bib, &ValorDado5Ementa ,&ValorCriterioAPV, &CondRetEsperada ) ;
            if ( NumLidos != 7 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DIS_gera_param( &dis, ValorDado1Nome, ValorDado2Codigo, ValorDado3Creditos, ValorDado4Bib, ValorDado5Ementa, ValorCriterioAPV) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao gerar disciplina recebendo parametros externos.\n" );

         } /* fim ativa: Testar DIS Gerar disciplina por parametros externos */

      /* Testar DIS exibe as informacoes da disciplina */

         else if ( strcmp( ComandoTeste , EXIBE_DIS_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" , &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DIS_exibe ( dis ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao exibir as informacoes de disciplina." );

         } /* fim ativa: Testar DIS exibe os valores da disciplina */


      /* Testar DIS obter creditos */

         else if ( strcmp( ComandoTeste , OBTER_CRE_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" , &ValorEsperado33 ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DIS_get_creditos( dis, &ValorObtido33 ) ;

			return TST_CompararInt ( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter creditos.\n" );

         } /* fim ativa: Testar DIS obter creditos */

      /* Testar DIS obter ementa */

         else if ( strcmp( ComandoTeste , OBTER_EM_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "si" ,  &ValorEsperado1 ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DIS_get_ementa(dis, &ValorObtido1);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter ementa." );

         } /* fim ativa: Testar DIS obter ementa */

      /* Testar DIS obter nome */

         else if ( strcmp( ComandoTeste , OBTER_NOME_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "si", &ValorEsperado1 ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DIS_get_nome( dis, &ValorObtido1  ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter nome.\n" );

         } /* fim ativa: Testar DIS obter nome */
	/* Testar DIS obter codigo */

         else if ( strcmp( ComandoTeste , OBTER_COD_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "si", &ValorEsperado1 ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DIS_get_codigo( dis , &ValorObtido1 ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter codigo.\n" );

         } /* fim ativa: Testar DIS obter codigo */
	/* Testar DIS obter bibliografia */

         else if ( strcmp( ComandoTeste , OBTER_BIB_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "si" , &ValorEsperado1 ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DIS_get_bibliografia( dis , &ValorObtido1 ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter bibliografia.\n" );

         } /* fim ativa: Testar DIS obter bibliografia */
      /* Testar DIS Destruir disciplina */

         else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
         {
            NumLidos = LER_LerParametros( "i",
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DIS_deleta_Disciplina(&dis) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao obter bibliografia.\n" );
         } /* fim ativa: DIS Destruir disciplina */

   /* Testar DIS Insere turma a lista de turmas */

      else if ( strcmp( ComandoTeste , INSERE_TURMA_DIS ) == 0 )
      {
         NumLidos = LER_LerParametros( "i",
                            &CondRetEsperada ) ;
         if ( NumLidos != 1 )
         {
            return TST_CondRetParm ;
         } /* if */

         CondRetObtido = DIS_insere_turma(&dis, turma+index) ;

         return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                 "Retorno errado ao obter bibliografia.\n" );
      } /* fim ativa: DIS Destruir disciplina */


/* Testar DIS limpa a lista de turmas */

   else if ( strcmp( ComandoTeste , LIMPA_TURMA_DIS ) == 0 )
   {
      NumLidos = LER_LerParametros( "i",
                         &CondRetEsperada ) ;
      if ( NumLidos != 1 )
      {
         return TST_CondRetParm ;
      } /* if */

      CondRetObtido = DIS_limpa_turma(&dis) ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                              "Retorno errado ao obter bibliografia.\n" );
   } /* fim ativa: DIS Destruir disciplina */


/* Testar DIS exibe turma a lista de turmas */

   else if ( strcmp( ComandoTeste , EXIBE_TURMA_DIS ) == 0 )
   {
      NumLidos = LER_LerParametros( "i",
                         &CondRetEsperada ) ;
      if ( NumLidos != 1 )
      {
         return TST_CondRetParm ;
      } /* if */

      CondRetObtido = DIS_exibe_todas_turmas(&dis) ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                              "Retorno errado ao obter bibliografia.\n" );
   } /* fim ativa: DIS Destruir disciplina */

   
   /* Testar DIS alterar credito de disciplina */

   else if ( strcmp( ComandoTeste , ALTERA_CRED_DIS ) == 0 )
   {
      NumLidos = LER_LerParametros( "ii",&ValorDado3Creditos, &CondRetEsperada ) ;
      if ( NumLidos != 2 )
      {
         return TST_CondRetParm ;
      } /* if */

      CondRetObtido = DIS_altera_creditos(dis,ValorDado3Creditos) ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                              "Retorno errado ao alterar creditos.\n" );
   } /* fim ativa: DIS alterar credito de disciplina */
	   

   /* Testar DIS alterar bibliografia de disciplina */

   else if ( strcmp( ComandoTeste , ALTERA_BIB_DIS ) == 0 )
   {
      NumLidos = LER_LerParametros( "si",&ValorDado4Bib, &CondRetEsperada ) ;
      if ( NumLidos != 2 )
      {
         return TST_CondRetParm ;
      } /* if */

      CondRetObtido = DIS_altera_bibliografia(dis,ValorDado4Bib) ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                              "Retorno errado ao alterar creditos.\n" );
   } /* fim ativa: DIS alterar bibliografia de disciplina */

   /* Testar DIS alterar criterio de aprovação de disciplina */

   else if ( strcmp( ComandoTeste , ALTERA_CRIAPV_DIS ) == 0 )
   {
      NumLidos = LER_LerParametros( "ii",&ValorCriterioAPV, &CondRetEsperada ) ;
      if ( NumLidos != 2 )
      {
         return TST_CondRetParm ;
      } /* if */

      CondRetObtido = DIS_altera_criterio(dis,ValorCriterioAPV) ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                              "Retorno errado ao alterar criterio de aprovação.\n" );
   } /* fim ativa: DIS alterar criterio de aprovação de disciplina */

   /* Testar DIS alterar ementa de disciplina */
   else if ( strcmp( ComandoTeste , ALTERA_EMENTA_DIS ) == 0 )
   {
      NumLidos = LER_LerParametros( "si",&ValorDado5Ementa, &CondRetEsperada ) ;
      if ( NumLidos != 2 )
      {
         return TST_CondRetParm ;
      } /* if */

      CondRetObtido = DIS_altera_ementa(dis,ValorDado5Ementa) ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                              "Retorno errado ao alterar ementa.\n" );
   } /* fim ativa: DIS alterar ementa de disciplina */
   
return TST_CondRetNaoConhec ;

} /* Fim função:TDIS Efetuar operações de teste específicas para disciplina */

/********** Fim do módulo de implementação: Módulo de teste específico **********/
