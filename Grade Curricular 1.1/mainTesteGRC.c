#include <stdio.h>
#include <stdlib.h>
#include "gradeCurricular.h"



int main(void){
	char nome[80];
	int G1, G2, G3, G4;
	int situacao;
	float media;
	GRC_tpCondRet ret;
	G1 = 3;
	G2 = 0;
	G3 = 5;
	G4 = 7;
	printf("teste1");
	ret = GRC_cria();
	printf("teste2");
	ret = GRC_cadastra( "Modular" , "INF1301", 4, "Programacao Modular, Ardt Von Stadt", "NaoVouEscrever muito pois o LimiteE curto", 2);
	ret = GRC_cadastra( "Prog2" , "INF1007", 4, "C para idiotas", "Listas, ordenacao e TAD", 1);
	printf("adicionar preReq\n");
	printf("preReq %d\n", GRC_inserePreRequisito("INF1007"));
	printf("preReq %d\n", GRC_inserePreRequisito("INF1007"));
	printf("preReq %d\n", GRC_inserePreRequisito("INF1007"));
	ret = GRC_mostraTodas();
	GRC_buscaPorCodigo("INF1301");
	GRC_attSituacaoDisCorrente(G1,G2,G3,G4, &media, &situacao);
		printf("\n A media eh: %.2f. Situacao:", media);
	if(situacao == 1)
		printf("aprovado\n");
	else
		printf("reprovado\n");
	printf("retF %d\n", ret);
	printf("retNome %d\n", GRC_consultaNome(nome));
	printf("%s\n", nome);
	GRC_limpa();
	GRC_libera();
	printf("FIM\n");
	system("pause");
	return 0;
}
