// #include "tp1.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <vector>
#include <time.h>
using std::size_t;

const int tailleTb = 20;

int binarySearch(int array[], int toSearch)
{

	int start = 0;
	int end = tailleTb-1;
	int foundIndex = 0;

	while(start<end){
		int mid = (start+end)/2;
		std::cout << "start:" << start << "end:" << end << "mid:" << mid << std::endl;
		if(toSearch>array[mid]){
			start = mid +1;
		}
		else if(toSearch<array[mid]){
			end = mid-1;
		}
		else{
			foundIndex = mid;
			break;
		}
	}

	return foundIndex;
}

void binarySearchAll(int array[], int toSearch, int* indexMin, int* indexMax)
{

	int start = 0;
	int end = tailleTb-1;

	*indexMin = *indexMax = binarySearch(array,toSearch);

	

	//on cherche un intervalle

	while(*indexMax<end && array[*indexMax+1]==toSearch){
		*indexMax++;
	}

	while(*indexMin>=start && array[*indexMin-1]==toSearch){
		*indexMin--;
	}

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

	int tab[tailleTb];

    for(int i=0;i<tailleTb;i++){
        tab[i]=rand()%20;
    }

	int* indexMin = new int;
	int* indexMax = new int;

	selectionSort(tab);

	int toSearch = tab[rand()%tailleTb];

	std::cout << "valeur à chercher :" << toSearch << "\n";
	// std::sort(tab, tab + tailleTb);

	std::cout << "tableau rangé" << "\n";

	for(int i=0;i<tailleTb;i++){
        std::cout << tab[i] << ", ";
    }
	std::cout << "\n";

	binarySearchAll(tab,toSearch,indexMin,indexMax);

	std::cout << "resultat de la recherche" << "\n";
	std::cout << *indexMin << ", " << *indexMax << "\n";

	delete indexMax;
	delete indexMin;
}