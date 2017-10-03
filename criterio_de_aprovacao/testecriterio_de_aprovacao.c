/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              testecriterio_de_aprovacao.C
*  Letras identificadoras:      TCRA
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Matheus Rodrigues de Oliveira Leal- mrol
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       0.01   mrol   30/09/2017 Início do desenvolvimento
*       0.02   mrol   01/10/2017 Uniformização da interface das funções e
*                                de todas as condições de retorno.
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para o teste do
*     módulo criterios de aprrovação. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo criterios de aprrovação:
*
*
*
***************************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include    "tst_espc.h"
#include    "generico.h"
#include    "lerparm.h"
#include    "criterio_de_aprovacao.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CALCULA_CRITERIO1    "=calcri1"
#define     CALCULA_CRITERIO2    "=calcri2"
#define     CALCULA_CRITERIO3    "=calcri3"
#define     CALCULA_CRITERIO4    "=calcri4"
#define     CALCULA_CRITERIO5    "=calcri5"

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TDIS Efetuar operações de teste específicas para criterios de aprrovação
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     criterios de aprrovação sendo testado.
*
*  $EP Parâmetros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/


   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      CRI_tpCondRet CondRetObtido  ;
      CRI_tpCondRet CondRetEsperada  ;
    /* inicializa para qualquer coisa */

      double g1;
      double g2;
      double g3;
      double g4;
      double media_aprovado;
      float media_aluno;
      float media;
      int resultado;


      int  NumLidos = -1 ;


      TST_tpCondRet Ret ;

      /* Testar CRI_Criterio01 */

         if ( strcmp( ComandoTeste , CALCULA_CRITERIO1 ) == 0 )
         {

            NumLidos = LER_LerParametros( "fffi" , &g1, &g2, &g3 , &CondRetEsperada) ;
            if ( NumLidos != 4 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = CRI_Criterio01( g1, g2, g3, &media, &resultado) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao gerar disciplina recebendo parametros externos.\n" );

         } /* fim ativa: Testar CRI Verifica_Criterio01 */

         /* Testar CRI_Criterio02 */

         else if ( strcmp( ComandoTeste , CALCULA_CRITERIO2 ) == 0 )
         {

            NumLidos = LER_LerParametros( "ffffi" , &g1, &g2, &g3, &g4, &CondRetEsperada) ;
            if ( NumLidos != 5 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = CRI_Criterio02( g1, g2, g3, g4, &media, &resultado);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao exibir as informacoes de disciplina." );

         } /* fim ativa: Testar CRI_Criterio02 */


         /* Testar  CRI_Criterio03 */

         else if ( strcmp( ComandoTeste , CALCULA_CRITERIO3 ) == 0 )
         {

           NumLidos = LER_LerParametros( "ffffi" , &g1, &g2, &g3, &g4, &CondRetEsperada) ;
            if ( NumLidos != 5 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = CRI_Criterio03( g1, g2, g3, g4, &media, &resultado);

			      return TST_CompararInt ( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter creditos.\n" );

         } /* fim ativa: CRI_Criterio03 */

         /* Testar CRI Verifica_Criterio04 */

         else if ( strcmp( ComandoTeste , CALCULA_CRITERIO4 ) == 0 )
         {

            NumLidos = LER_LerParametros( "fffi" , &g1, &g2, &g3 , &CondRetEsperada) ;
            if ( NumLidos != 4 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = CRI_Criterio04( g1, g2, g3, &media, &resultado);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter ementa." );

         } /* fim ativa: Testar CRI_Criterio04 */

      /* Testar CRI CRI_Criterio05 */

         else if ( strcmp( ComandoTeste , CALCULA_CRITERIO5 ) == 0 )
         {

            NumLidos = LER_LerParametros("ffi" , &g1, &g2, &CondRetEsperada) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = CRI_Criterio05(g1, g2, &media_aluno,  &resultado) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter nome.\n" );

         } /* fim ativa: Testar CRI CRI_Criterio05 */
}
/********** Fim do módulo de implementação: Módulo de teste específico **********/
