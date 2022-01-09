/* File: monAppli.c
Auteurs: JMT
cree le 29 12 2021
modifie le:  jj mm aa    */

#include "monAppli.h"


typedef struct date{
  int a; 
  int m; } Date;

int ajouter(int x, int y){
  return x + y;
}

/*
pas de main si on veut utiliser CUnit!
*/
/*
int main (){
  Date d1, d2;
  d1.a =1000;
  d1.m =99;
  d2 = d1;
  d2.m =0;
  printf("a : %d, m : %d\n", d1.a, d2.a);
  return 0;
}
*/
