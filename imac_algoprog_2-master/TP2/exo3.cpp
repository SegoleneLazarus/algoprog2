// #include <QApplication>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <random>
// #include "tp2.h"

// MainWindow* w=nullptr;

const int tailleTb = 8;

void bubbleSort(int toSort[]){
	// bubbleSort
}


int main(int argc, char *argv[])
{
	srand((unsigned)time(NULL));
	int tab[tailleTb];
 

    for(int i=0;i<tailleTb;i++){
        tab[i]=rand()%10;
    }

    for(int i=0;i<tailleTb;i++){
        std::cout << tab[i] << "\n";
    }

    bubbleSort(tab);

    std::cout << "hahahahaha" << "\n";

    for(int i=0;i<tailleTb;i++){
        std::cout << tab[i] << "\n";
    }
}
