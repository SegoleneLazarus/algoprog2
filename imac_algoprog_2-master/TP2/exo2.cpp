// #include <QApplication>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <random>
// #include "tp2.h"

// MainWindow* w=nullptr;
void insertionSort(int toSort[]){
	// Array& sorted=w->newArray(toSort.size());

	// // insertion sort from toSort to sorted
	
	// toSort=sorted; // update the original array
}

void insertionSort(int toSort[]){
	
}

// int main(int argc, char *argv[])
// {
// 	QApplication a(argc, argv);
//     uint elementCount=15; // number of elements to sort
//     MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
//     w = new TestMainWindow(insertionSort); // window which display the behavior of the sort algorithm
// 	w->show();

// 	return a.exec();
// }

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