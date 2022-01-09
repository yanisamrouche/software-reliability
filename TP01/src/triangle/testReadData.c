#include "triangle.h"
#include <stdio.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

/*Test suites and clean up functions*/
int init_suite(void) { return 0;}
int clean_suite(void){return 0;}

/* les tests*/
void testReadDataTrueTriangle(void) {
  Triangle triangle;
  triangle.coteA = 2.5;
  triangle.coteB = 1.5;
  triangle.coteC = 2.5;

  Triangle triangle2 = readData("triangle.txt");

  CU_ASSERT_EQUAL(triangle2.coteA, triangle.coteA);
  CU_ASSERT_EQUAL(triangle2.coteB, triangle.coteB);
  CU_ASSERT_EQUAL(triangle2.coteC, triangle.coteC);

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
  pSuite = CU_add_suite("ReadDataTestSuite", init_suite, clean_suite);
  if (pSuite == NULL){
    CU_cleanup_registry();
    return CU_get_error();
  }

  /*ajouter les  tests à la suite */
  printf("add first test\n");
  if (
      (CU_add_test(pSuite,"testReadDataTrueTriangle", testReadDataTrueTriangle) == NULL) 
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