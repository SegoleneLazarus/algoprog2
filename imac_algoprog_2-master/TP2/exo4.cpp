// #include <QApplication>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
// #include "tp2.h"
// MainWindow* w=nullptr;

const int tailleTb = 8;
int taillePt = tailleTb;
int tailleGt = tailleTb;


void recursivQuickSort(int toSort[], int size){
	int pivot = toSort[0];
	
	for(int k=1;k<tailleTb;k++){
		if(toSort[k]<pivot){
			int lowers[taillePt] = toSort[k];
			taillePt++;
		}
		else{
			int greaters[taillePt] = toSort[k];
			tailleGt++;
		}
	}

	recursivQuickSort(lowers, lowers.size());
	recursivQuickSort(greaters, greaters.size());

	for(int i=0;i<taillePt;i++){
		toSort[i] = lowers[i];
	}

	toSort[taillePt] = pivot;

	int temp = taillePt+1;

	for(temp;temp<tailleTb;temp++){
		toSort[i] = greaters[i];
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
