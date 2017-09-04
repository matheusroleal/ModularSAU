// RODAR ESSE ARQUIVO, INCREMENTANDO ELE, CADA VEZ QUE TIVER UMA NOVA FUNÇAO!!!
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "disciplina.h"

int main(void){
 char*msg;
 char*msg1;
 char*msg2;
 char*msg3;
 int cred;
  //TESTAR COM AS DUAS MANEIRAS DE OBTER OS DADOS
  // DIS_tpCondRet c1 = DIS_gera_cmd();
  DIS_tpCondRet c1 = DIS_gera_param("ALUNO","inf1301",4,"sadasdas","teste");

  DIS_tpCondRet c2 = DIS_exibe();
  
  DIS_tpCondRet c3 = DIS_get_nome(&msg);
  printf("NOME: %s\n",msg);

  free(msg);
  DIS_tpCondRet c4 = DIS_get_ementa(&msg1);
  printf("EMENTA: %s\n",msg1);
  free(msg1);
  DIS_tpCondRet c8 = DIS_get_creditos(&cred);
  printf("CREDITOS: %d\n",cred);

  DIS_tpCondRet c6 = DIS_get_codigo(&msg2);
  printf("CODIGO: %s\n",msg2);
  free(msg2);
  DIS_tpCondRet c5 = DIS_get_bibliografia(&msg3);
  printf("BIBLIOGRAFIA: %s\n",msg3);
  free(msg3);



  
  DIS_tpCondRet c7 = DIS_exibe();

  return 0;
}
