#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <vector>
#include <time.h>
using std::size_t;
using std::string;

const int tailleTb = 10;

struct Heap{
	std::vector<int> tab;

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

	void heapify(int nodeIndex)
	{
		int i = nodeIndex;
		int largest = nodeIndex;

		
		if(largest < this->tab[rightChild(largest)]){
			largest = rightChild(largest);
		}
		if(largest < this->tab[leftChild(largest)]){
			largest = leftChild(largest);
		}
		if(largest!=i){
			int swap = this->tab[largest];
			this->tab[largest] = this->tab[i];
			this->tab[i] = swap;

			heapify(largest);
		}

	}

	void buildHeap(std::vector<int> numbers){
		// this->tab.resize(numbers.size());
		for(int i=0;i<numbers.size();i++){
			insertHeapNode(i,numbers[i]);
		}

	}

	void heapSort(){
		for(int i=tab.size()-1;i=0;i--){
			int swap = this->tab[i];
			this->tab[i] = this->tab[0];
			this->tab[0] = swap;
			heapify(i);
		}
	}

};

int main(int argc, char *argv[])
{
	srand((unsigned)time(NULL));

	Heap* h = new Heap;
	std::vector<int> tab;
	tab.resize(tailleTb);
	
	for(int i=0;i<tailleTb;i++){
		tab[i] = rand()%20;
	}

	for(int i=0;i<tailleTb;i++){
        std::cout << tab[i] << "\n";
    }

	h->buildHeap(tab);
	
	std::cout << "hahahahaha" << "\n";

    for(int i=0;i<tailleTb;i++){
        std::cout << h->tab[i] << "\n";
    }
}
