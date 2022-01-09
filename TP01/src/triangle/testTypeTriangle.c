#include "triangle.h"
#include <stdio.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

/*Test suites and clean up functions*/
int init_suite(void) { return 0;}
int clean_suite(void){return 0;}

/* les tests*/
void testTypeValueA(void){
  char a = 'a';
  float b = 5.4;
  float c = 2.5;
  int value = -1;
  CU_ASSERT_EQUAL(typeTriangle(a, b, c), value);

}
void testTypeValueB(void){
  char a = 1.5;
  float b = 'b';
  float c = 2.5;
  int value = -1;
  CU_ASSERT_EQUAL(typeTriangle(a, b, c), value);

}
void testTypeValueC(void){
  char a = 2.2;
  float b = 5.4;
  char c = 'c';
  int value = -1;
  CU_ASSERT_EQUAL(typeTriangle(a, b, c), value);

}

void testNegativeValueA(void) {
  float a = -2.0;
  float b = 3.5;
  float c = 3.5;
  int value = -1;

  CU_ASSERT_EQUAL(typeTriangle(a, b, c), value);
}
void testNegativeValueB(void) {
  float a = 3.0;
  float b = -5.0;
  float c = 3.0;
  int value = -1;

  CU_ASSERT_EQUAL(typeTriangle(a, b, c), value);
}
void testNegativeValueC(void) {
  float a = 2.0;
  float b = 6.0;
  float c = -6.0;
  int value = -1;

  CU_ASSERT_EQUAL(typeTriangle(a, b, c), value);
}
void testNullValueA(void) {
  float a = 0.0;
  float b = 6.0;
  float c = 6.0;
  int value = -1;

  CU_ASSERT_EQUAL(typeTriangle(a, b, c), value);
}
void testNullValueB(void) {
  float a = 2.0;
  float b = 0.0;
  float c = 2.0;
  int value = -1;

  CU_ASSERT_EQUAL(typeTriangle(a, b, c), value);
}
void testNullValueC(void) {
  float a = 3.0;
  float b = 3.0;
  float c = 0.0;
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

void testTypeTriangleIsoceleAB(void) {
  float a = 5.0;
  float b = 5.0;
  float c = 3.5;
  int value = 2;

  CU_ASSERT_EQUAL(typeTriangle(a, b, c), value);
}
void testTypeTriangleIsoceleAC(void) {
  float a = 5.0;
  float b = 3.5;
  float c = 5.0;
  int value = 2;

  CU_ASSERT_EQUAL(typeTriangle(a, b, c), value);
}
void testTypeTriangleIsoceleBC(void) {
  float a = 3.5;
  float b = 5.0;
  float c = 5.0;
  int value = 2;

  CU_ASSERT_EQUAL(typeTriangle(a, b, c), value);
}

void testTypeTriangleScalene(void) {
  float a = 1.0;
  float b = 1.1;
  float c = 0.5;
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
  if ((CU_add_test(pSuite,"testTypeValueA", testTypeValueA) == NULL) 
      ||(CU_add_test(pSuite,"testTypeValueB", testTypeValueB) == NULL) 
      ||(CU_add_test(pSuite,"testTypeValueC", testTypeValueC) == NULL) 
      ||(CU_add_test(pSuite,"testNegativeValueA", testNegativeValueA) == NULL) 
      ||(CU_add_test(pSuite,"testNegativeValueB", testNegativeValueB) == NULL)  
      ||(CU_add_test(pSuite,"testNegativeValueC", testNegativeValueC) == NULL)
      ||(CU_add_test(pSuite,"testNullValueA", testNullValueA) == NULL)
      ||(CU_add_test(pSuite,"testNullValueB", testNullValueB) == NULL)
      ||(CU_add_test(pSuite,"testNullValueC", testNullValueC) == NULL)                              
      ||(CU_add_test(pSuite,"testTypeTriangleEquilateral", testTypeTriangleEquilateral) == NULL) 
      ||(CU_add_test(pSuite,"testTypeTriangleIsoceleAB", testTypeTriangleIsoceleAB) == NULL) 
      ||(CU_add_test(pSuite,"testTypeTriangleIsoceleAC", testTypeTriangleIsoceleAC) == NULL) 
      ||(CU_add_test(pSuite,"testTypeTriangleIsoceleBC", testTypeTriangleIsoceleBC) == NULL) 
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