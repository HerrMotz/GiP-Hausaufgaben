/* Datei: delta_aristotle.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func1(double x, double y) {
    if (y == x)
        return NAN;
    return (x+y) / (x-y);
}

double func2(double x, double y) {
    return sqrt(x*x + y*y);
}


int main(void) {
    double x, y;
    double result;

    x = 42;
    y = 7;

    result = func1(x, y);

    printf("result of f1: %lf\n", result);

    result = func2(x, y);

    printf("result of f2: %lf\n", result);

    return EXIT_SUCCESS;
}