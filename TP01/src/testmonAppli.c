/* Programme de tests pour les fonctions de monAppli.c */
/*Utilisation : compiler monAppli.c pour obtenir monAppli.o 
                    gcc -Wall -c monAppli.c
                compiler testmonAppli.c en incluant la librairie pour avoir l'executable
                    gcc -Wall -I$HOME/local/CUnit/include -o testmonAppli testmonAppli.c monAppli.o -L$HOME/local/CUnit/lib -lcunit
                       avec HOME la variable d'environnement dont la valeur $HOME vaut le nom de votre home directory et 
                            $HOME/local/CUnit est le répertoire contenant CUnit
*/



#include "monAppli.h"
#include <stdio.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

/*Test suites and clean up functions*/
int init_suite(void) { return 0;}
int clean_suite(void){return 0;}

/* les tests*/
void testAjouterZero(void) {
  int x = 1;
  int y = 0;
  CU_ASSERT_EQUAL(ajouter(x, y), x);
}

void testResultatZero(void) {
  int x = 1;
  int y = -1;
  CU_ASSERT_EQUAL(ajouter(x, y), 0);
}

/* Mise en place des tests via main */
int main(void){
  CU_pSuite pSuite = NULL;

  /*initialise le catalogue de tests*/
  printf("initialize test registry\n");
  if (CUE_SUCCESS != CU_initialize_registry()) {
    return CU_get_error();
  }

  printf("add suite to testregistry\n");
  /*ajoute une suite de tests au catalogue */
  /*la suite de test n'a qu'un seul test ici!!!*/
  pSuite = CU_add_suite("monAppliTestSuite", init_suite, clean_suite);
  if (pSuite == NULL){
    CU_cleanup_registry();
    return CU_get_error();
  }

  /*ajouter les  tests à la suite */
  printf("add first test\n");
  if ((CU_add_test(pSuite,"testAjouterZero", testAjouterZero) == NULL) 
      ||(CU_add_test(pSuite,"testResultatZero", testAjouterZero) == NULL) 
      /* si plus de tests: || (CU_add_test(...)) || ...|| (CU_add_test(...))*/
      ){
    CU_cleanup_registry();
    return CU_get_error();
  }

  /*Run all tests using the basic interface */
  printf("start execution\n");
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("termine\n\n");
  CU_basic_show_failures(CU_get_failure_list());

  /*Clean up registry and return*/
  CU_cleanup_registry();
  return CU_get_error();
}
