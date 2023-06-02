// #include <QApplication>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <vector>

const int tailleTb = 8;

void merge(std::vector<int>& first, std::vector<int>& second, std::vector<int>& result);

void splitAndMerge(std::vector<int>& origin)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)

	// initialisation
	std::vector<int>& first;
	std::vector<int>& second;
	
	// split

	// recursiv splitAndMerge of lowerArray and greaterArray

	// merge
}

void merge(std::vector<int>& first, std::vector<int>& second, std::vector<int>& result)
{

}

void mergeSort(std::vector<int>& toSort)
{
    splitAndMerge(toSort);
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
