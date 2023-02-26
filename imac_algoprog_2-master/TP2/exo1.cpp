// #include <QApplication>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <random>
// #include "tp2.h"

const int tailleTb = 8;



// MainWindow* w = nullptr;

// void selectionSort(int toSort[]){
// 	for(int i=0;i<tailleTb;i++){
//         for(int k=i;k<tailleTb;k++){
//             if(toSort[i] > toSort[k]){
//                 int n = toSort[i];
//                 toSort[i] = toSort[k];
//                 toSort[k] = n;
//                 k=tailleTb;
//             }
//         }
//     }
// }

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
	// QApplication a(argc, argv);
    // uint elementCount=15; // number of elements to sort
    // MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    // w = new TestMainWindow(selectionSort); // window which display the behavior of the sort algorithm
    // w->show();

	// return a.exec();

    int tab[tailleTb];
 

    for(int i=0;i<tailleTb;i++){
        tab[i]=rand()%10;
    }

    for(int i=0;i<tailleTb;i++){
        std::cout << tab[i] << "\n";
    }

    selectionSort(tab);

    std::cout << "hahahahaha" << "\n";

    for(int i=0;i<tailleTb;i++){
        std::cout << tab[i] << "\n";
    }

    
}