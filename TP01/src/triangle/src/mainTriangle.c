/* File: mainTriangle.c
Auteurs: Yanis Amrouche
cree le 04 01 2022
*/

#include "triangle.h"
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (){
    Triangle triangle;
    triangle = readData ("triangle.txt");
    printf("%d \n",typeTriangle(triangle.coteA, triangle.coteB, triangle.coteC));
    return 0;
}