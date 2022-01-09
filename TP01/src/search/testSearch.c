#include "search.h"
#include <stdio.h>
#include <stdbool.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

/*Test suites and clean up functions*/
int init_suite(void) { return 0;}
int clean_suite(void){return 0;}

/* les tests*/
void testLengthTab(void){
  int length = 10;
  int* tab = generateSorted(length);
  int* memeoireAlluee = malloc(length*sizeof(int));
  CU_ASSERT_EQUAL(sizeof(tab), sizeof(memeoireAlluee));  
}
void testSearchInteger(void) {
  int* tab = generateSorted(10);
  int result = 2;
  CU_ASSERT_EQUAL(searchInteger(tab, 4, 3), result);
}
void testIfSorted(void){
  int length = 10;
  int* tab = generateSorted(length);
  bool isSorted = true;
  for(int i=0; i<length-1; i++){
    for(int j=0; j<length-1-i; j++){
        if(tab[j] > tab[j+1]){
          isSorted = false;
        }      
    }
  }
  CU_ASSERT_TRUE(isSorted);
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
  pSuite = CU_add_suite("searchTestSuite", init_suite, clean_suite);
  if (pSuite == NULL){
    CU_cleanup_registry();
    return CU_get_error();
  }

  /*ajouter les  tests à la suite */
  printf("add first test\n");
  if ((CU_add_test(pSuite,"testSearchInteger", testSearchInteger) == NULL) 
      || (CU_add_test(pSuite,"testLengthTab", testLengthTab) == NULL) 
      || (CU_add_test(pSuite,"testIfSorted", testIfSorted) == NULL) 

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
