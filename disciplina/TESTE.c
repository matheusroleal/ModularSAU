#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "disciplina.h"
#include "listas.h"
#include "criterio_de_aprovacao.h"

int main(void)
{
	Disciplina* disc;
	int situacao;
	float media;
	float G1 = 10;
	float G2 = 5;
	float G3 = 2;
	float G4 = 7;
	DIS_gera_param(&disc, "modular", "1213", 2, "muita coisa", "coisas problematicas", 2);
	printf("chega aqui");
	DIS_situacaoAluno(disc, G1, G2, G3, G4, &media, &situacao);
	printf("\n A media eh: %f. Situacao:", media);
	if(situacao == 1)
		printf("aprovado");
	else
		printf("reprovado");
	DIS_exibe(disc);
	return 0;
}
