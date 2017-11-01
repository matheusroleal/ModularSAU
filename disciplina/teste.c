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
  Disciplina *dis=NULL;
  DIS_tpCondRet c4;
  DIS_tpCondRet c8;
  DIS_tpCondRet c6;
  DIS_tpCondRet c5;
  DIS_tpCondRet c10;
  DIS_tpCondRet c7;
  
  DIS_tpCondRet c1 = DIS_gera_param(&dis, "blabla","1234", 4, "blabla", "blabla");

  DIS_tpCondRet c2 = DIS_exibe(dis);

  DIS_tpCondRet c3 = DIS_get_nome(dis,&msg);
  
  c4 = DIS_get_ementa(dis,&msg1);
  
  printf("NOME: %s\n",msg);
  free(msg);
  printf("EMENTA: %s\n",msg1);
  free(msg1);
  printf("CREDITOS: %d\n",cred);

  c6 = DIS_get_codigo(dis,&msg2);
  printf("CODIGO: %s\n",msg2);
  free(msg2);
  c5 = DIS_get_bibliografia(dis,&msg3);
  printf("BIBLIOGRAFIA: %s\n",msg3);
  free(msg3);
  c10 = DIS_deleta_Disciplina(&dis);
  c7 = DIS_exibe(dis);

  return 0;
}
