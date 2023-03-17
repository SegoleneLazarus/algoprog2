#include "tp4.h"
#include "mainwindow.h"

// #include "tp1.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <vector>
#include <time.h>
using std::size_t;
using std::string;

struct Heap{
	vect<int> tab;

	int leftChild(int nodeIndex){
		return nodeIndex*2+1;
	}
	int rightChild(int nodeIndex){
		return nodeIndex*2+2;
	}
	void insertHeapNode(int heapSize, int value){
		this->tab.push_back(value);

		int i = heapSize;

		while(i>0 && this->tab[i] > this->tab[(i-1)/2]){
			int swap = this->tab[(i-1)/2];
			this->tab[(i-1)/2] = this->tab[i];
			this->tab[i] = swap;
			i = (i-1)/2;
		}
	}

	void heapify(int heapSize, int nodeIndex)
	{
		int i = nodeIndex;
		int largest = nodeIndex;

		

		if(largest!=i){
			int swap = this->tab[largest];
			this->tab[largest] = this->tab[i];
			this->tab[i] = swap;

			heapify(ouin,largest);
		}

	}

}



void buildHeap(Array& numbers)
{

}

void heapSort()
{

}

int main(int argc, char *argv[])
{
	
}
