#include "triangle.h"
#include <stdio.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

/*Test suites and clean up functions*/
int init_suite(void) { return 0;}
int clean_suite(void){return 0;}

/* les tests*/
void testNonTypeTriangle(void) {
  float a = 2.0;
  float b = -5.0;
  float c = 0;
  int value = -1;

  CU_ASSERT_EQUAL(typeTriangle(a, b, c), value);
}

void testTypeTriangleEquilateral(void) {
  float a = 5.0;
  float b = 5.0;
  float c = 5.0;
  int value = 3;

  CU_ASSERT_EQUAL(typeTriangle(a, b, c), value);
}

void testTypeTriangleIsocele(void) {
  float a = 5.0;
  float b = 3.5;
  float c = 5.0;
  int value = 2;

  CU_ASSERT_EQUAL(typeTriangle(a, b, c), value);
}

void testTypeTriangleScalene(void) {
  float a = 5.0;
  float b = 3.5;
  float c = 1.0;
  int value = 1;

  CU_ASSERT_EQUAL(typeTriangle(a, b, c), value);
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
  pSuite = CU_add_suite("TypeTriangleTestSuite", init_suite, clean_suite);
  if (pSuite == NULL){
    CU_cleanup_registry();
    return CU_get_error();
  }

  /*ajouter les  tests à la suite */
  printf("add first test\n");
  if ((CU_add_test(pSuite,"testNonTypeTriangle", testNonTypeTriangle) == NULL) 
      || (CU_add_test(pSuite,"testTypeTriangleEquilateral", testTypeTriangleEquilateral) == NULL) 
      || (CU_add_test(pSuite,"testTypeTriangleIsocele", testTypeTriangleIsocele) == NULL) 
      ||(CU_add_test(pSuite,"testTypeTriangleScalene", testTypeTriangleScalene) == NULL) 
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