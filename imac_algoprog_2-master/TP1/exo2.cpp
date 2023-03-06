// #include "tp1.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <vector>
#include <time.h>


int fibonacci(int n)
{
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    else{
        return (fibonacci(n-1)) + (fibonacci(n-2));
    }

    
}

int main(int argc, char *argv[])
{
    std::cout << fibonacci(6) << "\n";
}
