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
  DIS_tpCondRet c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;
  Disciplina *dis=NULL;
  //TESTAR COM AS DUAS MANEIRAS DE OBTER OS DADOS
  // DIS_tpCondRet c1 = DIS_gera_cmd();
  c1 = DIS_gera_param("ALUNO","inf1301",4,"sadasdas","teste");

  c2 = DIS_exibe();

  c9 = DIS_get_diciplina(&dis);

  c3 = DIS_get_nome(dis,&msg);
  printf("NOME: %s\n",msg);
  free(msg);
  c4 = DIS_get_ementa(dis,&msg1);
  printf("EMENTA: %s\n",msg1);
  free(msg1);
  c8 = DIS_get_creditos(dis,&cred);
  printf("CREDITOS: %d\n",cred);

  c6 = DIS_get_codigo(dis,&msg2);
  printf("CODIGO: %s\n",msg2);
  free(msg2);
  c5 = DIS_get_bibliografia(dis,&msg3);
  printf("BIBLIOGRAFIA: %s\n",msg3);
  free(msg3);
  c10 = DIS_deleta_Disciplina(&dis);
  c7 = DIS_exibe();

  return 0;
}
