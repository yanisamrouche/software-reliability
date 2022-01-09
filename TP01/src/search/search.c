/* File: search.c
Auteurs: Yanis Amrouche
cree le 04 01 2022
modifie le:  jj mm aa    */

#include "search.h"
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/random.h>

int* generateSorted(int n){
    int* tab = malloc(sizeof(int) * n);
   
    for(int i=0; i<n; i++){
        int r = random() % n;
        tab[i] = r;
    }
    
    int tmp;
    // tri à bulle
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(tab[j] > tab[j+1]){
                tmp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = tmp;

            }

        }
        
    }
    printf(" [ ");
    for(int i=0; i<n; i++){
        printf("%d ", tab[i]);
    }
    printf(" ] \n");

    return tab;
}

int searchInteger(int* t, int n, int e){
    int debut = 0;
    int fin = n-1;
    while (debut <= fin)
    {
        int milieu = debut + (fin - debut) / 2 ;
        if(t[milieu] == e){
           return milieu;
        }
        if(t[milieu] > e){
            fin = milieu - 1;
        }
        else{
            debut = milieu + 1; 
        }
    }
    return -1;
    


}
