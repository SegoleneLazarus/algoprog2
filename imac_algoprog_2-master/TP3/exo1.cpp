// #include "tp1.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <vector>
#include <time.h>
using std::size_t;

const int tailleTb = 8;

int binarySearch(int array[], int toSearch)
{

	int start = 0;
	int end = tailleTb;
	int foundIndex = 0;

	for(start;start<end;start++){
		int mid = (start+end)/2;
		if(toSearch>array[mid]){
			start = mid +1;
		}
		else if(toSearch<array[mid]){
			end = mid;
		}
		else{
			foundIndex = mid;
		}
	}

	return foundIndex;
}

void selectionSort(int toSort[]){
    bool comtuveu = true;
    while(comtuveu){
        comtuveu = false;
        for(int i=0;i<tailleTb;i++){
            for(int k=i;k<tailleTb;k++){
                if(toSort[i] > toSort[k]){
                    int n = toSort[i];
                    toSort[i] = toSort[k];
                    toSort[k] = n;
                    k=tailleTb;
                    comtuveu = true;
                }
            }
        }
    }
	
}

int main(int argc, char *argv[])
{
	 srand((unsigned)time(NULL));

	int toSearch = rand()%20;

	std::cout << "valeur à chercher :" << toSearch << "\n";

	int tab[tailleTb];

    for(int i=0;i<tailleTb;i++){
        tab[i]=rand()%20;
    }

	std::cout << "tableau affichage" << "\n";

    for(int i=0;i<tailleTb;i++){
        std::cout << tab[i] << "\n";
    }

	selectionSort(tab);

	std::cout << "tableau rangé" << "\n";

	for(int i=0;i<tailleTb;i++){
        std::cout << tab[i] << "\n";
    }

	std::cout << "resultat de la recherche" << "\n";

	std::cout << binarySearch(tab,toSearch) << "\n";

}
