/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTE.C
*  Letras identificadoras:      TDIS
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Pedro Gabriel Serodio Sales
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       3.00   avs   28/02/2003 Uniformização da interface das funções e
*                               de todas as condições de retorno.
*       2.00   avs   03/08/2002 Eliminação de código duplicado, reestruturação
*       1.00   avs   15/08/2001 Início do desenvolvimento
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
*     "=destroi"    - chama a função ARV_DestruirArvore( )
*
***************************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include    "tst_espc.h"

#include    "generico.h"
#include    "lerparm.h"

#include    "disciplina.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define     GERA_INP_DIS_CMD    "=gerainp"
#define     GERA_PAR_DIS_CMD    "=gerapar"
#define     EXIBE_DIS_CMD       "=exibe"
#define     OBTER_DIS_CMD       "=obterdis"
#define     OBTER_CRE_CMD       "=obtercre"
#define     OBTER_EM_CMD        "=obterem"
#define     OBTER_NOME_CMD      "=obternome"
#define     OBTER_COD_CMD       "=obtercod"
#define     OBTER_BIB_CMD       "=obterbib"
#define     DESTROI_CMD         "=destruir"

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
#define MAX 8

Disciplina *dis[MAX]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      DIS_tpCondRet CondRetObtido   = DIS_CondRetOK ;
      DIS_tpCondRet CondRetEsperada = DIS_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */

      

      char ValorEsperado;
      char ValorDado1[20];
      char ValorDado2[20];
      int ValorDado3;
      char ValorDado4[20];
      char ValorDado5[20];
      int index =0;
      int  NumLidos = -1 ;

      TST_tpCondRet Ret ;

      /* Testar DIS Gerar disciplina por input do teclado */

         if ( strcmp( ComandoTeste , GERA_INP_DIS_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DIS_gera_cmd( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao gerar disciplina por input do teclado.\n" );

         } /* fim ativa: Testar DIS Gerar disciplina por input do teclado */

      /* Testar DIS Gerar discipina por parametros externos */

         else if ( strcmp( ComandoTeste , GERA_PAR_DIS_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ississi" ,
                               ValorDado1, ValorDado2, &ValorDado3 , ValorDado4, ValorDado5 , &CondRetEsperada ) ;
            if ( NumLidos != 5 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DIS_gera_param( ValorDado1, ValorDado2, ValorDado3, ValorDado4, ValorDado5 ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao gerar disciplina recebendo parametros externos.\n" );

         } /* fim ativa: Testar DIS Gerar disciplina por parametros externos */

      /* Testar DIS exibe as informacoes da disciplina */

         else if ( strcmp( ComandoTeste , EXIBE_DIS_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                                &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DIS_exibe ( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao exibir as informacoes de disciplina." );

         } /* fim ativa: Testar DIS exibe os valores da disciplina */

      /* Testar DIS obter disciplina */

         else if ( strcmp( ComandoTeste , OBTER_DIS_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" , &index,
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DIS_get_diciplina( dis[index] ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao obter struct disciplina.\n" );

         } /* fim ativa: Testar DIS obter disciplina */

      /* Testar DIS obter creditos */

         else if ( strcmp( ComandoTeste , OBTER_CRE_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "isi" ,&index, ValorDado1 ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DIS_get_codigo( dis[index] , ValorDado1 ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao obter creditos.\n" );

         } /* fim ativa: Testar DIS obter creditos */

      /* Testar DIS obter ementa */

         else if ( strcmp( ComandoTeste , OBTER_EM_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "isi" , &index, ValorDado1 ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DIS_get_ementa(dis[index] , ValorDado1 ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir para direita." );

         } /* fim ativa: Testar DIS obter ementa */

      /* Testar DIS obter nome */

         else if ( strcmp( ComandoTeste , OBTER_NOME_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "isi" ,&index, ValorDado1 ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DIS_get_nome( dis[index], ValorDado1  ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao obter nome.\n" );

         } /* fim ativa: Testar DIS obter nome */
	/* Testar DIS obter codigo */

         else if ( strcmp( ComandoTeste , OBTER_COD_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "isi" ,&index, ValorDado1 ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DIS_get_codigo( dis[index] , ValorDado1 ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao obter codigo.\n" );

         } /* fim ativa: Testar DIS obter codigo */
	/* Testar DIS obter bibliografia */

         else if ( strcmp( ComandoTeste , OBTER_BIB_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "isi" ,&index, ValorDado1 ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = DIS_get_bibliografia( dis[index] , ValorDado2 ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao obter bibliografia.\n" );

         } /* fim ativa: Testar DIS obter bibliografia */
      /* Testar DIS Destruir disciplina */

         else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
         {
	    NumLidos = LER_LerParametros( "i" ,
                               &index ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } 
            DIS_deleta_Disciplina(dis[index]) ;

            return TST_CondRetOK ;

         } /* fim ativa: DIS Destruir disciplina */

      return TST_CondRetNaoConhec ;

   } /* Fim função: TDIS Efetuar operações de teste específicas para disciplina */

/********** Fim do módulo de implementação: Módulo de teste específico **********/
