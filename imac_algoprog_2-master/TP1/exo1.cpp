// #include "tp1.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <vector>
#include <time.h>

#define return_and_display(result) return _.store(result);

long power(long value, long n)
{
    
    if(n==0){
        return 1;
    }
    else{
        return value * power(value,n-1);
    }
    
}

int main(int argc, char *argv[])
{

    std::cout << power(2,8) << "\n";

}