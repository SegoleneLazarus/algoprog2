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
	bool comtuveu = true;
	int i=0;
	while(comtuveu){
		comtuveu = false;
		for(int k=0;k<tailleTb;k++){
			i=k;
			while(toSort[i]>toSort[i+1]){
				int n = toSort[i];
				toSort[i] = toSort[i+1];
				toSort[i+1] = n;
				i++;
				comtuveu = true;
			}
		}
	}	
	
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
