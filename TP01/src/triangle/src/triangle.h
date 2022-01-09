/* File: triangle.h
Auteurs: Yanis Amrouche et Farouk Agueni
cree le 04 01 2022
modifie le:  09 01 2022  */
#ifndef TRIANGLE
#define TRIANGLE

#include <stdlib.h>
#include <stdio.h>

typedef struct  {
  float coteA;
  float coteB;
  float coteC;
} Triangle;

Triangle readData (char * file);

int typeTriangle(float a, float b, float c);
#endif
