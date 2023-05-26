// #include "tp1.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <vector>
#include <time.h>

#define return_and_display(result) return _.store(result);

int allEvens(int evens[], int array[], int evenSize, int arraySize)
{
    // dans array, vérfier si un nombre est pair
    // pour cela : n%2 = 0
    // if(array[arraySize-1] % 2 == 0)
    // si c'est égal à 0, alors on remplit evens
    // insert(index,value)
    // return allEvens()


    if(arraySize==0){
        return evenSize;
    }
    else if (array[arraySize - 1] % 2 == 0) {
            evens[evenSize] = array[arraySize - 1];
            evenSize++;
            return allEvens(evens, array, evenSize + 1, arraySize - 1);
        }
        
    
    else{
        return allEvens(evens, array, evenSize, arraySize - 1);
    }
    
}

int main(int argc, char *argv[])
{
    int evens[150];
    int array[9] = { 1,2,3,4,5,6,7,8,9 };
    std::cout << "résultat : " << allEvens(evens, array, 0, 9) << std::endl;

    return 0;

}




