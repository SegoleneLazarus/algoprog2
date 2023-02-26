// #include <QApplication>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <random>
// #include "tp2.h"

const int tailleTb = 8;

// MainWindow* w=nullptr;
void insertionSort(int toSort[]){
	int atrier;
    bool flagplace;
	int Sorted[tailleTb];
    for (int i=0;i<tailleTb;i++)
    {
        flagplace=false;
        atrier=toSort[i];
        for (int k=0;k<i;k++)
        {
            if (atrier<Sorted[k])
            {
                for (int f=tailleTb-2;f>=k;f--)
                {
                    Sorted[f+1]=Sorted[f];
                }
                Sorted[k]=atrier;
                flagplace=true;
                break;
            }

        }
        if(flagplace==false)
            {
                Sorted[i]=atrier;
            }
    }
    for(int i=0;i<tailleTb;i++){
        toSort[i]=Sorted[i];
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

    insertionSort(tab);

    std::cout << "hahahahaha" << "\n";

    for(int i=0;i<tailleTb;i++){
        std::cout << tab[i] << "\n";
    }
}