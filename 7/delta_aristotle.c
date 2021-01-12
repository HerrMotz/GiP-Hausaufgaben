/* Datei: delta_aristotle.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func1(double x, double y) {
    double ret = (x+y) / (x-y);

    if (isinf(ret) || x-y == 0)
        return NAN;
    else
        return ret;
}

double func2(double x, double y) {
    return sqrt(round(pow(x, 2)) + round(pow(y, 2)));
}


int main(void) {
    double x, y;
    double result;

    x = 2;
    y = 2;

    result = func1(x, y);

    printf("result of f1: %lf\n", result);

    result = func2(x, y);

    printf("result of f2: %lf\n", result);

    return EXIT_SUCCESS;
}