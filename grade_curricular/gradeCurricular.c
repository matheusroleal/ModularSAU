/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo Corpo Docente
*
*  Arquivo gerado:              corpoDocente.C
*  Letras identificadoras:      GRC
*
*  Nome da base de software:    Fonte do m�dulo Corpo Docente
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Bruce Marcellino, BM
*			Felipe Alfena, FA
*			Nicolas Paes, NP
*			Mariana Ruddy, MR
*			Rodrigo Pumar, RP.
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor 	Data     	Observa��es
*       0.10   BM	07/10/2017	Inicio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Este m�dulo cont�m as fun��es espec�ficas para manipular os professores na lista de corpo docente.
*     Este m�dulo utiliza func�es de interface do modulo professor.
***************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gradeCurricular.h"
#include "disciplina.h"
#include "listas.h"

/***********************************************************************
*
*  $TC Tipo de dados: corpoDocente
*
*
*  $ED Descri��o do tipo
*     Estrutura principal que armazena os dados de um corpo docente ao qual este m�dulo se dedica.
*
***********************************************************************/

typedef struct parDisciplina{
	Disciplina *disciplina;
	List *preRequisitos;
} ParDisciplina;

typedef struct gradeCurricular{
	List *parDisciplinas;
} GradeCurricular;


/*****  Dados encapsulados no m�dulo  *****/

static GradeCurricular *grc;
	/* inst�ncia de corpo docente armazenada por este m�dulo */

/***** Prot�tipos das fun��es encapsuladas no m�dulo *****/
// TODO retirar isto caso nao fa�a nenhuma funcao


/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: GRC Criar Lista de Corpo Docente
*  ****/

GRC_tpCondRet GRC_cria(void){
	grc = (GradeCurricular*) malloc(sizeof(GradeCurricular));
	createList(&grc->parDisciplinas);
	return GRC_CondRetOk;
}/* Fim fun��o: GRC Criar Lista de Corpo Docente */

/***************************************************************************
*
*  Fun��o: GRC Cadastrar Professor
*  ****/

GRC_tpCondRet GRC_cadastra(char* nome, char* codigo, int creditos, char* bibliografia, char* ementa, int criterio){
	ParDisciplina *parD = NULL;
	Disciplina *disc = NULL;
	DIS_tpCondRet ret;
	if(GRC_buscaPorCodigo(codigo) == GRC_CondRetOk)
		return GRC_CondRetIdJaCriado;
	ret = DIS_gera_param(&disc, nome, codigo, creditos, bibliografia, ementa,criterio);
	if(ret == DIS_CondRetFaltouMemoria) return GRC_CondRetNaoHaMemoria;
	if(ret == DIS_CondRetParametroInvalido) return GRC_CondRetFormatoInvalido;
	parD = (ParDisciplina*) malloc(sizeof(ParDisciplina));
	parD->disciplina = disc;
	createList(&parD->preRequisitos);
	push_back(grc->parDisciplinas, parD);
	return GRC_CondRetOk;
}/* Fim fun��o: GRC Cadastrar Professor */

/***************************************************************************
*
*  Fun��o: GRC Mostra Pre-Requisitos
*  ****/

/* Funcao interna */

GRC_tpCondRet GRC_mostraPreRequisitos(ParDisciplina *parD){
	Disciplina *disc = NULL;
	char buffer[80] = "";
	char *codigo = NULL;
	int tam=0;
	first(parD->preRequisitos);
	printf("Pre-Requisitos: ");
	do{
		if(get_val_cursor(parD->preRequisitos, (void**) &disc)== LIS_CondRetListaVazia) break;
		DIS_get_codigo(disc, &codigo);
		printf(" %s", buffer);
		strcpy(buffer, codigo);
		strcat(buffer, ",");
		free(codigo);
	}while(next(parD->preRequisitos)==LIS_CondRetOK);
	if(strcmp(buffer,"")==0)
		printf("--//--");
	else{
		tam = strlen(buffer);
		/* Tam n�o � igual a zero, pois se fosse, nao estariamos neste if */
		buffer[tam-1] = '.';
		printf("%s", buffer);
	}
	printf("\n");
	return GRC_CondRetOk;
}/* Fim fun��o: GRC Mostra Pre-Requisitos */

/***************************************************************************
*
*  Fun��o: GRC Mostra Atual
*  ****/

GRC_tpCondRet GRC_mostraAtual(void){
	ParDisciplina *parD = NULL;
	if(get_val_cursor(grc->parDisciplinas, (void**) &parD)== LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	DIS_exibe(parD->disciplina);
	GRC_mostraPreRequisitos(parD);
	return GRC_CondRetOk;
}/* Fim fun��o: GRC Mostra Atual */

 /***************************************************************************
 *
 *  Fun��o: GRC Mostra Todos Professores
 *  ****/

GRC_tpCondRet GRC_mostraTodas(void){
	ParDisciplina *parD = NULL;
	first(grc->parDisciplinas);
	do{
		if(get_val_cursor(grc->parDisciplinas, (void**) &parD)== LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
		DIS_exibe(parD->disciplina);
		GRC_mostraPreRequisitos(parD);
	}while(next(grc->parDisciplinas)==LIS_CondRetOK);
	return GRC_CondRetOk;
}/* Fim fun��o: GRC Mosta Todos Professores */

 /***************************************************************************
 *
 *  Fun��o: GRC Limpa Lista
 *  ****/

GRC_tpCondRet GRC_limpa(void){
	ParDisciplina *parD = NULL;
	while(pop_back(grc->parDisciplinas, (void**) &parD)==LIS_CondRetOK){
		DIS_deleta_Disciplina(&parD->disciplina);
		del(parD->preRequisitos);
		free(parD);
	};
	return GRC_CondRetOk;
}/* Fim fun��o: GRC Limpa Lista */

 /***************************************************************************
 *
 *  Fun��o: GRC Retira da Lista
 *  ****/

GRC_tpCondRet GRC_retira(void){
	ParDisciplina *parD = NULL;
	if(pop_cursor(grc->parDisciplinas, (void**) &parD) == LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	DIS_deleta_Disciplina(&parD->disciplina);
	del(parD->preRequisitos);
	free(parD);
	return GRC_CondRetOk;
}/* Fim fun��o: GRC Retira da Lista */

 /***************************************************************************
 *
 *  Fun��o: GRC Libera
 *  ****/

GRC_tpCondRet GRC_libera(void){
	GRC_limpa();
	del(grc->parDisciplinas);
	return GRC_CondRetOk;
}/* Fim fun��o: GRC Libera */

 /***************************************************************************
 *
 *  Fun��o: GRC Busca Por RG
 *  ****/

GRC_tpCondRet GRC_buscaPorCodigo(char *chave){
	ParDisciplina *parD = NULL;
	char *codigo = NULL;
	char *inicioCod = NULL;
	int ret;

	get_val_cursor(grc->parDisciplinas, (void**) &parD);
	if(get_val_cursor(grc->parDisciplinas, (void**) &parD) == LIS_CondRetListaVazia)
		return GRC_CondRetGradeCurricularVazia;
	DIS_get_codigo(parD->disciplina, &inicioCod);

	first(grc->parDisciplinas);
	do{
		if(get_val_cursor(grc->parDisciplinas, (void**) &parD) == LIS_CondRetListaVazia){
			free(inicioCod);
			return GRC_CondRetGradeCurricularVazia;
		}

		DIS_get_codigo(parD->disciplina, &codigo);
		ret = strcmp(chave, codigo);
		free(codigo);
		if(ret==0){
			free(inicioCod);
			return GRC_CondRetOk;
		}
	}while(next(grc->parDisciplinas)==LIS_CondRetOK);
	GRC_buscaPorCodigo(inicioCod);
	free(inicioCod);
	return GRC_CondRetDisciplinaNaoEncontrada;
}/* Fim fun��o: GRC Busca Por RG */

 /***************************************************************************
 *
 *  Fun��o: GRC Busca Por RG
 *  ****/

/*
	TODO formalizar este coment�rio
	Note que o codigo passado como argumento � o codigo do pre-requisito. E N�O o c�digo da disciplina a qual vamos adicionar um preRequisito.
	A disciplina a qual vamos adicionar � a disciplina selecionada (cursor).
*/
GRC_tpCondRet GRC_inserePreRequisito(char *codigoPre){
	ParDisciplina *parD = NULL;
	ParDisciplina *parDPre = NULL;
	char *codigo = NULL;
	/* Recuperando disciplina atual da lista */
	if(get_val_cursor(grc->parDisciplinas, (void**) &parD)== LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	/* Recuperando o c�digo dela */
	DIS_get_codigo(parD->disciplina, &codigo);
	/* Procurando o pre requisito */
	if(GRC_buscaPorCodigo(codigoPre)!=GRC_CondRetOk){
		/* Se n�o encontrei retorno o cursor para onde comecei e retorno */
		GRC_buscaPorCodigo(codigo);
		free(codigo);
		return GRC_CondRetDisciplinaNaoEncontrada;
	}
	/*
		Recuperando a disciplina Pre-Requisito
		Ja sei que a lista n�o esta vazia, n�o preciso verificar de novo
	*/
	get_val_cursor(grc->parDisciplinas, (void**) &parDPre);
	/* Guardo o endereco do pre-requisito (disciplina, nao par) na lista do par (e nao disciplina) que recuperei no inicio */
	push_back(parD->preRequisitos, parDPre->disciplina);
	/* Retorno o cursor para onde comecei e retorno */
	GRC_buscaPorCodigo(codigo);
	free(codigo);
	return GRC_CondRetOk;
}/* Fim fun��o: GRC Busca Por RG */

GRC_tpCondRet GRC_removePreRequisitos(){
	ParDisciplina *parD = NULL;
	/* Recuperando disciplina da lista */
	if(get_val_cursor(grc->parDisciplinas, (void**) &parD)== LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	clear(parD->preRequisitos);
	return GRC_CondRetOk;
}/* Fim fun��o: GRC Busca Por RG */


 /***************************************************************************
 *
 *  Fun��o: GRC Consulta Nome
 *  ****/
GRC_tpCondRet GRC_consultaNome(char *nome){
	ParDisciplina *parD = NULL;
	/* Recuperando disciplina da lista */
	if(get_val_cursor(grc->parDisciplinas, (void**) &parD)== LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	DIS_get_nome(parD->disciplina, &nome);
	return GRC_CondRetOk;
}/* Fim fun��o: GRC Consulta Nome */

 /***************************************************************************
 *
 *  Fun��o: GRC Consulta Codigo
 *  ****/
GRC_tpCondRet GRC_consultaCodigo(char *codigo){
	ParDisciplina *parD = NULL;
	/* Recuperando disciplina da lista */
	if(get_val_cursor(grc->parDisciplinas, (void**) &parD)== LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	DIS_get_codigo(parD->disciplina, &codigo);
	return GRC_CondRetOk;
}/* Fim fun��o: GRC Consulta Codigo*/

 /***************************************************************************
 *
 *  Fun��o: GRC Consulta Credito
 *  ****/
GRC_tpCondRet GRC_consultaCreditos(int *creditos){
	ParDisciplina *parD = NULL;
	int credTemp;
	/* Recuperando disciplina da lista */
	if(get_val_cursor(grc->parDisciplinas, (void**) &parD)== LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	DIS_get_creditos(parD->disciplina, &credTemp);
	*creditos = credTemp;
	return GRC_CondRetOk;
}/* Fim fun��o: GRC Consulta Credito*/

 /***************************************************************************
 *
 *  Fun��o: GRC Consulta Bibliografia
 *  ****/
GRC_tpCondRet GRC_consultaBibliografia(char *bibliografia){
	ParDisciplina *parD = NULL;
	/* Recuperando disciplina da lista */
	if(get_val_cursor(grc->parDisciplinas, (void**) &parD)== LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	DIS_get_bibliografia(parD->disciplina, &bibliografia);
	return GRC_CondRetOk;
}/* Fim fun��o: GRC Consulta Bibliografia*/


 /***************************************************************************
 *
 *  Fun��o: GRC Consulta Ementa
 *  ****/
GRC_tpCondRet GRC_consultaEmenta(char *ementa){
	ParDisciplina *parD = NULL;
	/* Recuperando disciplina da lista */
	if(get_val_cursor(grc->parDisciplinas, (void**) &parD)== LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	DIS_get_ementa(parD->disciplina, &ementa);
	return GRC_CondRetOk;
}/* Fim fun��o: GRC Consulta Ementa*/
