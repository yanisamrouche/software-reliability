/* File: triangle.c
Auteurs: Yanis Amrouche
cree le 04 01 2022
modifie le:  jj mm aa    */

#include "triangle.h"
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cote_a[100];
char cote_b[100];
char cote_c[100];


Triangle readData (char * file){
    Triangle triangle;
    FILE *rfile = fopen(file, "r");
    if(rfile == NULL){
        perror("Erreur fichier...");
        exit(0);
    }

    fscanf(rfile, "a=%s\n", cote_a);
    fscanf(rfile, "b=%s\n", cote_b);
    fscanf(rfile, "c=%s\n", cote_c);
    printf(">a=%s \n b=%s \n c=%s \n ", cote_a, cote_b, cote_c);
    triangle.coteA = atof(cote_a);
    triangle.coteB = atof(cote_b);
    triangle.coteC = atof(cote_c);

    return triangle;

}

int typeTriangle(float a, float b, float c){
    if(a <= 0.0 || b <= 0.0 || c<= 0.0 || (a > b+c) || (b > a+c) || (c > a+b)){
        return -1;
    }else if (a==b && b==c)
    {
        return 3;
    }else if (a==b || a==c || b==c){
        return 2;
    }else if (a != b && b!=c && a!=c){
        return 1;
    }
    
}