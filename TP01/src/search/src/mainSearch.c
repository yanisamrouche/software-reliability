/* File: mainTriangle.c
Auteurs: Yanis Amrouche
cree le 05 01 2022
 */

#include "search.h"
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (){
    int n = 10;
    int element = 5;
    printf("la taille du tableau : %d", n);
    
    int* tab = generateSorted(n);
    int index = searchInteger(tab, n, element);
    printf("l'indice de l'element %d est : %d \n",element, index);
    
    return 0;
}