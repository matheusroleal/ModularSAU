/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              testeGradeC.C
*  Letras identificadoras:      TGRADC
*
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Matheus Rodrigues de Oliveira Leal - mrol
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   mrol   23/10/2017 Início do desenvolvimento
*       2.00   mrol   24/10/2017 Adicionadas mais funções para teste
*       3.00   mrol   2/11/2017 Funções para teste com busca de codigo refeitas
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para o teste do
*     módulo grade currícular. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo grade currícular:
*
*     "=geradis" <Char> <Char> <Int> <Char> <Char>
*                   - chama a função GRC_cadastra( <Char> <Char> <Int> <Char> <Char> )
*                     Obs. notação: <Char> <Int> são os valores dos parâmetros
*                     que se encontram no comando de teste.
*     "=obtercre" <INT>
*                      - chama a função GRC_consultaCreditos
*     "=obterem" <Char>
*                      - chama a função GRC_consultaEmenta
*     "=obternome"<Char>
*                      - chama a função GRC_consultaNome
*     "=obtercod" <Char>
*                      - chama a função GRC_consultaCodigo
*     "=obterbib" <Char>
*                      - chama a função GRC_consultaBibiliografia
*     "=inserepr" <Char>
*                      - chama a função GRC_inserePreRequisito
*     "=buscacod" <Char>
*                      - chama a função GRC_buscaPorCodigo
*     "=removepr"
*                      - chama a função GRC_removePreRequisitos
*     "=criagrc"
*                      - chama a função GRC_cria
*     "=mostradisgrc"
*                      - chama a função GRC_mostraAtual
*     "=mostragrc"
*                      - chama a função GRC_mostraTodas
*     "=liberagrc"
*                      - chama a função GRC_libera
*     "=limpagrc"
*                      - chama a função GRC_limpa
*     "=removedisgrc"
*                      - chama a função GRC_retira
*     "=getdisc" <Disciplina>
*                      - chama a função GRC_devolveDisc
*
***************************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "tst_espc.h"
#include "generico.h"
#include "lerparm.h"
#include "gradeCurricular.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define     GERA_PAR_DIS_CMD     "=geradis"
#define     CONSULTA_CRE         "=obtercre"
#define     CONSULTA_EM          "=obterem"
#define     CONSULTA_NOME        "=obternome"
#define     CONSULTA_COD         "=obtercod"
#define     CONSULTA_BIB         "=obterbib"
#define     INSERE_PRE_REQUISITO "=inserepr"
#define	    REMOVE_PRE_REQUISITO "=removepr"
#define	    BUSCA_CODIGO		     "=buscacod"
#define	    CRIA_GRC	 		       "=criagrc"
#define	    MOSTRA_DIS_GRC		   "=mostradisgrc"
#define	    MOSTRA_GRC	 		     "=mostragrc"
#define	    LIMPA_GRC	           "=limpagrc"
#define	    LIBERA_GRC	         "=liberagrc"
#define	    REMOVE_DIS_GRC	     "=removedisgrc"
#define		OBTEM_DISC			"=getdisc"	

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TDIS Efetuar operações de teste específicas para grade currícular
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     grade currícular sendo testado.
*
*  $EP Parâmetros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/
 void *dis;

TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
{

  GRC_tpCondRet CondRetObtido  ;
  GRC_tpCondRet CondRetEsperada  ;
  /* inicializa para qualquer coisa */

  //char ValorEsperado;
  char ValorDado1Nome[25];
  char ValorDado2Codigo[8];
  int  ValorDado3Creditos;
  char ValorDado4Bib[300];
  char ValorDado5Ementa[300];
  int  ValorDado6Criterio;

  int  NumLidos = -1 ;
  char ValorDado7Codigo[8];
  char ValorDado8Codigo[8];
  char *ValorEsperado1;
  int ValorEsperado33;


  TST_tpCondRet Ret ;

  /* Testar GRC cadastra discipina por parametros externos */

  if ( strcmp( ComandoTeste , GERA_PAR_DIS_CMD ) == 0 )
  {

    NumLidos = LER_LerParametros( "ssissii" , &ValorDado1Nome, &ValorDado2Codigo, &ValorDado3Creditos , &ValorDado4Bib, &ValorDado5Ementa, &ValorDado6Criterio , &CondRetEsperada ) ;
    if ( NumLidos != 7 )
    {
      return TST_CondRetParm ;
    } /* if */

    CondRetObtido = GRC_cadastra( ValorDado1Nome, ValorDado2Codigo, ValorDado3Creditos, ValorDado4Bib, ValorDado5Ementa, ValorDado6Criterio ) ;

    return TST_CompararInt( CondRetEsperada , CondRetObtido ,
      "Retorno errado ao gerar disciplina recebendo parametros externos.\n" );

    } /* fim ativa: Testar GRC cadastra disciplina por parametros externos */

    /* Testar GRC consulta de creditos */

    else if ( strcmp( ComandoTeste , CONSULTA_CRE ) == 0 )
    {

      NumLidos = LER_LerParametros( "ii" , &ValorEsperado33 ,
      &CondRetEsperada ) ;
      if ( NumLidos != 2 )
      {
        return TST_CondRetParm ;
      } /* if */

      CondRetObtido = GRC_consultaCreditos(&ValorEsperado33) ;

      return TST_CompararInt ( CondRetEsperada , CondRetObtido ,
        "Retorno errado ao tentar obter creditos.\n" );

    } /* fim ativa: Testar GRC consulta de creditos */

      /* Testar GRC consulta de bibliografia */
    else if ( strcmp( ComandoTeste , CONSULTA_BIB ) == 0 )
    {

      NumLidos = LER_LerParametros( "si" , &ValorEsperado1 ,
      &CondRetEsperada ) ;
      if ( NumLidos != 2 )
      {
        return TST_CondRetParm ;
      } /* if */

      CondRetObtido = GRC_consultaBibliografia(ValorEsperado1) ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
        "Retorno errado ao tentar obter bibliografia.\n" );

    } /* fim ativa: Testar GRC consulta de bibliografia */


      /* Testar GRC consulta de ementa */

    else if ( strcmp( ComandoTeste , CONSULTA_EM ) == 0 )
    {

      NumLidos = LER_LerParametros( "si" ,  &ValorEsperado1 ,
      &CondRetEsperada ) ;
      if ( NumLidos != 2 )
      {
        return TST_CondRetParm ;
      } /* if */

      CondRetObtido = GRC_consultaEmenta(ValorEsperado1);

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
        "Retorno errado ao tentar obter ementa." );

    } /* fim ativa: Testar GRC consulta de ementa */

      /* Testar GRC consulta de nome */

    else if ( strcmp( ComandoTeste , CONSULTA_NOME ) == 0 )
    {

      NumLidos = LER_LerParametros( "si", &ValorEsperado1 ,
      &CondRetEsperada ) ;
      if ( NumLidos != 2 )
      {
        return TST_CondRetParm ;
      } /* if */

      CondRetObtido = GRC_consultaNome(ValorEsperado1) ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
        "Retorno errado ao tentar obter nome.\n" );

    } /* fim ativa: Testar GRC consulta de nome */

      /* Testar GRC consulta de codigo */

    else if ( strcmp( ComandoTeste , CONSULTA_COD ) == 0 )
    {

      NumLidos = LER_LerParametros( "si", &ValorEsperado1 ,
      &CondRetEsperada ) ;
      if ( NumLidos != 2 )
      {
        return TST_CondRetParm ;
      } /* if */

      CondRetObtido = GRC_consultaCodigo(ValorEsperado1) ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
        "Retorno errado ao tentar obter codigo.\n" );

    } /* fim ativa: Testar GRC consulta de codigo */

      /* Testar GRC busca por codigo */
    else if ( strcmp( ComandoTeste , BUSCA_CODIGO ) == 0 )
    {

      NumLidos = LER_LerParametros( "si", &ValorDado7Codigo ,
      &CondRetEsperada ) ;
      if ( NumLidos != 2 )
      {
        return TST_CondRetParm ;
      } /* if */

      CondRetObtido = GRC_buscaPorCodigo(ValorDado7Codigo) ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
        "Retorno errado ao tentar obter codigo.\n" );

    } /* fim ativa: Testar GRC busca por codigo */

                /* Testar GRC insere todos pre requesito*/
    else if ( strcmp( ComandoTeste , INSERE_PRE_REQUISITO ) == 0 )
    {

      NumLidos = LER_LerParametros( "si", &ValorDado8Codigo ,
      &CondRetEsperada ) ;
      if ( NumLidos != 2 )
      {
        return TST_CondRetParm ;
      } /* if */

      CondRetObtido = GRC_inserePreRequisito(ValorDado8Codigo) ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
        "Retorno errado ao tentar obter codigo.\n" );

    } /* fim ativa: Testar GRC insere por codigo pre requesito */

        /* Testar GRC remove todos pre requesito*/
    else if ( strcmp( ComandoTeste , REMOVE_PRE_REQUISITO ) == 0 )
    {

      NumLidos = LER_LerParametros( "i",&CondRetEsperada ) ;
      if ( NumLidos != 1 )
      {
        return TST_CondRetParm ;
      } /* if */

      CondRetObtido = GRC_removePreRequisitos() ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
        "Retorno errado ao tentar obter codigo.\n" );

    } /* fim ativa: Testar GRC remove por codigo pre requesito */

        /* Testar GRC cria grade curricular */

    else if ( strcmp( ComandoTeste , CRIA_GRC ) == 0 )
    {

      NumLidos = LER_LerParametros( "i",&CondRetEsperada ) ;
      if ( NumLidos != 1 )
      {
        return TST_CondRetParm ;
      } /* if */

      CondRetObtido = GRC_cria() ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
        "Retorno errado ao tentar obter codigo.\n" );

    } /* fim ativa: Testar GRC cria grade curricular */

      /* Testar GRC mostra disciplina atual de grade curricular */
    else if ( strcmp( ComandoTeste , MOSTRA_DIS_GRC ) == 0 )
    {

      NumLidos = LER_LerParametros( "i",&CondRetEsperada ) ;
      if ( NumLidos != 1 )
      {
        return TST_CondRetParm ;
      } /* if */

      CondRetObtido = GRC_mostraAtual() ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
        "Retorno errado ao tentar obter codigo.\n" );

    } /* fim ativa: Testar GRC mostra disciplina atual de grade curricular */

        /* Testar GRC mostra todas as disciplinas de grade curricular */
    else if ( strcmp( ComandoTeste , MOSTRA_GRC ) == 0 )
    {

      NumLidos = LER_LerParametros( "i",&CondRetEsperada ) ;
      if ( NumLidos != 1 )
      {
        return TST_CondRetParm ;
      } /* if */

      CondRetObtido = GRC_mostraTodas() ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
        "Retorno errado ao tentar obter codigo.\n" );

    } /* fim ativa: Testar GRC mostra todas as disciplinas de grade curricular */

        /* Testar GRC retira disciplina atual de grade curricular */
    else if ( strcmp( ComandoTeste , REMOVE_DIS_GRC ) == 0 )
    {

      NumLidos = LER_LerParametros( "i",&CondRetEsperada ) ;
      if ( NumLidos != 1 )
      {
        return TST_CondRetParm ;
      } /* if */

      CondRetObtido = GRC_retira() ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
        "Retorno errado ao tentar obter codigo.\n" );

    } /* fim ativa: Testar GRC retira disciplina atual de grade curricular */

    /* Testar GRC limpa disciplina atual de grade curricular */
    else if ( strcmp( ComandoTeste , LIMPA_GRC ) == 0 )
    {

      NumLidos = LER_LerParametros( "i",&CondRetEsperada ) ;
      if ( NumLidos != 1 )
      {
        return TST_CondRetParm ;
      } /* if */

      CondRetObtido = GRC_limpa() ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
        "Retorno errado ao tentar obter codigo.\n" );

    } /* fim ativa: Testar GRC limpa disciplina atual de grade curricular */

    /* Testar GRC libera disciplina atual de grade curricular */
    else if ( strcmp( ComandoTeste , LIBERA_GRC ) == 0 )
    {

      NumLidos = LER_LerParametros( "i",&CondRetEsperada ) ;
      if ( NumLidos != 1 )
      {
        return TST_CondRetParm ;
      } /* if */

      CondRetObtido = GRC_libera() ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
        "Retorno errado ao tentar obter codigo.\n" );

    } /* fim ativa: Testar GRC libera disciplina atual de grade curricular */
	
	/* Testar GRC Devolve a Disciplina do cursor atual */
	else if ( strcmp( ComandoTeste , OBTEM_DISC ) == 0 )
    {

      NumLidos = LER_LerParametros( "i",&CondRetEsperada ) ;
      if ( NumLidos != 1 )
      {
        return TST_CondRetParm ;
      } /* if */

      CondRetObtido = GRC_devolveDisc(&dis) ;

      return TST_CompararInt( CondRetEsperada , CondRetObtido ,
        "Retorno errado ao tentar obter codigo.\n" );

    } /* fim ativa: Testar GRC Devolve a Disciplina do cursor atual */

  return TST_CondRetNaoConhec ;
}/* Fim função:TGRADC Efetuar operações de teste específicas para grade curricular */

/********** Fim do módulo de implementação: Módulo de teste específico **********/
