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

void binarySearchAll(int array[], int toSearch, int* indexMin, int* indexMax)
{

	int start = 0;
	int end = tailleTb;

	indexMin = indexMax = binarySearch(array,toSearch);

	//on cherche un intervalle

	while(indexMax<end && array[indexMax+1]==toSearch){
		indexMax++;
	}

	while(indexMin>=start && array[indexMin-1]==toSearch){
		indexMin++;
	}

}

int main(int argc, char *argv[])
{
	
}