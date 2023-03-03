// #include <QApplication>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <vector>
// #include "tp2.h"
// MainWindow* w=nullptr;

const int tailleTb = 8;
// int taillePt = tailleTb;
// int tailleGt = tailleTb;


void recursivQuickSort(std::vector<int>& toSort, int size){
	if(size!=1 && size!=0){
		int pivot = toSort[0];
		std::cout << "affiche pivot : " << pivot << "\n";

		std::vector<int> lowers;
		std::vector<int> greaters;
		
		for(int k=1;k<size;k++){
			if(toSort[k]<pivot){
				lowers.push_back(toSort[k]);
			}
			else{
				greaters.push_back(toSort[k]);
			}
		}

		recursivQuickSort(lowers, lowers.size());
		recursivQuickSort(greaters, greaters.size());

		for(int i=0;i<lowers.size();i++){
			toSort[i] = lowers[i];
		}

		toSort[lowers.size()] = pivot;

		int temp = lowers.size()+1;

		for(temp;temp<size;temp++){
			toSort[temp] = greaters[temp-(lowers.size()+1)];
		}
	}
	else{
		return;
	}
	

	
}

int main(int argc, char *argv[])
{
	srand((unsigned)time(NULL));
	std::vector<int> tab;
 

    for(int i=0;i<tailleTb;i++){
        tab.push_back(rand()%10);
    }

    for(int i=0;i<tailleTb;i++){
        std::cout << tab[i] << "\n";
    }

    recursivQuickSort(tab,tab.size());

    std::cout << "hahahahaha" << "\n";

    for(int i=0;i<tailleTb;i++){
        std::cout << tab[i] << "\n";
    }
}
