// #include "tp1.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <vector>
#include <time.h>

#define return_and_display(result) return _.store(result);


int search(int value, int array[], int size)
{
// un tableau 
//est-ce que tel nombre est dans le tableau
//si oui, à quelle position

    //compteur arrêt argument répéter

    if(size==0){
        return -1;
    }
    if(array[size-1]==value){
        return size-1;
    }

    return search(value, array, size - 1)  ;
}

int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));
    const int size = 5;
    int valTest = rand()%size;
    int tab[size];

    std::cout << "valeur de test : " << valTest << "\n";

    for(int i=0;i<size;i++){
        tab[i]=rand()%10;
    }

    for(int i=0;i<size;i++){
        std::cout << tab[i] << "\n";
    }

    std::cout << "séparation" << "\n";

    std::cout << search(valTest,tab,size) << "\n";
}




