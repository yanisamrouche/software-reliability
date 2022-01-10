/* File: triangle.c
Auteurs: Yanis Amrouche et Farouk Agueni
cree le 04 01 2022
modifie le:  09 01 2022  */

#include "triangle.h"
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cote_a[100];
char cote_b[100];
char cote_c[100];

/** la méthode readData renvoie une structure de type triangle
 * dont les cotés correspondent aux trois lignes du fichier
*/
Triangle readData (char * file){
    Triangle triangle;

    for(size_t i=strlen(file)-1; i>=0; i--){
        if(file[i-1] != 't' || file[i-2] != 'x' || file[i-3] != 't'){
            triangle.coteA=-1;
            triangle.coteB=-1;
            triangle.coteC=-1;
            return triangle;
        }
    }

    FILE *rfile = fopen(file, "r");

    if(rfile == NULL){
        triangle.coteA=-1;
        triangle.coteB=-1;
        triangle.coteC=-1;
        return triangle;
        perror("Erreur fichier...");
        exit(0);
    }
    int c = fgetc(rfile);
    if(c==EOF){
        triangle.coteA=-1;
        triangle.coteB=-1;
        triangle.coteC=-1;
        return triangle;
    }
    fscanf(rfile, "a=%s\n", cote_a);
    fscanf(rfile, "b=%s\n", cote_b);
    fscanf(rfile, "c=%s\n", cote_c);
    printf(">a=%s \n b=%s \n c=%s \n ", cote_a, cote_b, cote_c);
    triangle.coteA = atof(cote_a); // la méthode atof : transforme un char en float
    triangle.coteB = atof(cote_b);
    triangle.coteC = atof(cote_c);

    return triangle;

}



/**la méthode typeTriangle renvoie le type du triangle dont les cotés
 * sont les réels a,b,c
 * retourne 1 s'ils ne définissent pas un triangle
 * retourne 3 si le triangle est équilatéral
 * retourne 2 s'il est isocèle
 * retourne 1 s'il est scalène
 */
int typeTriangle(float a, float b, float c){
    if(a <= 0.0 || b <= 0.0 || c<= 0.0 || (a > b+c) || (b > a+c) || (c > a+b)){
        return -1;
    }else if (a==b && b==c)
    {
        return 3;
    }else if (a==b || a==c || b==c){
        return 2;
    }else{
        return 1;
    }
    return -1;
}