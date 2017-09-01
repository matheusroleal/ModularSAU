#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* DIC_le_codigo(void) /* Codigo da disciplina no padrão inf0000 */
{
	char* cod2 = malloc(5 * sizeof(char)); /* cod2 = parte numerica */
	if (cod2 == NULL)
	{
		printf("Memoria insuficiente!\n\n");
		exit(-1);
	}

	char* cod1 = (char*)malloc(8 * sizeof(char)); /*cod1 = prefixo*/
	if (cod1 == NULL)
	{
		printf("Memoria insuficiente!\n\n");
		exit(-1);
	}

	cod1[0] = 'i';                  /* "inf" já virá como prefixo do codigo */
	cod1[1] = 'n';
	cod1[2] = 'f';
	cod1[3] = '\0';

	scanf("%4s", cod2); /* O usuario digitará apenas a parte numerica do codigo (4 Numerais no caso)*/

	strcat(cod1, cod2);	  /* Concatena "inf" + 4 numerais no máximo */

	free(cod2);

	return cod1;
}
DIC_tpCondRet DIC_get_codigo(Diciplina *d, char *codigo) {
	if (d->codigo)
	{
		strcpy(codigo, d->codigo);
		return DIC_CondRetOK;
	}
	return DIC_CondRetErroEstrutura;
}
/* 

	TESTE DA FUNÇÃO DIC_le_codigo

int main()
{
	char* codigo = DIC_le_codigo();

	printf("%s\n\n", codigo);

	return 0;
}

*/