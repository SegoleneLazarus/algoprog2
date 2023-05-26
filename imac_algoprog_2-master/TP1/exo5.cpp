#include "tp1.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <vector>
#include <time.h>

int isMandelbrot(Point z, int n, Point point){
    
    if(n>0) {
        int module = sqrt(z.x * z.x + z.y * z.y);

        if(module>2) {
            return n;
        } else {
            Point new_z;

            new_z.x = (z.x * z.x - z.y * z.y) + point.x;
            new_z.y = (2 * z.x * z.y) + point.y;

            return isMandelbrot(new_z, n-1, point);
        }
    }

    return 0;
}

int main(int argc, char *argv[])
{
    std::cout << isMandelbrot() << "\n";
    //fréro je n'ai QT je sais pas comment on fait bizou
}



