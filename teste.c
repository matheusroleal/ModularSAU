// RODAR ESSE ARQUIVO, INCREMENTANDO ELE, CADA VEZ QUE TIVER UMA NOVA FUNÇAO!!!
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "disciplina.h"
#define MAXBUF  (100)

int main(void){

  //TESTAR COM AS DUAS MANEIRAS DE OBTER OS DADOS
  // DIS_tpCondRet c1 = DIS_gera_cmd();
  DIS_tpCondRet c1 = DIS_gera_param("ALUNO","inf1301",4,"sadasdas","teste");

  DIS_tpCondRet c2 = DIS_exibe();

  char * msg = (char*) malloc( (MAXBUF + 1) * sizeof(char) );
  DIS_tpCondRet c3 = DIS_get_nome(msg);
  printf("NOME: %s\n",msg);

  DIS_tpCondRet c4 = DIS_get_ementa(msg);
  printf("EMENTA: %s\n",msg);

  DIS_tpCondRet c6 = DIS_get_codigo(msg);
  printf("CODIGO: %s\n",msg);

  DIS_tpCondRet c5 = DIS_get_bibliografia(msg);
  printf("BIBLIOGRAFIA: %s\n",msg);
  free(msg);

  DIS_tpCondRet c7 = DIS_exibe();

  return 0;
}
