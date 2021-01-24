/*
 * Datei: 91c.c
 * Daniel Motz
 *
 * */

#include <stdio.h>
#include <stdlib.h>

int check(long long unsigned int number) {
    if (number < 10) {
        return 1;
    } else if (number % 10 > number / 10 % 10) {
        return 0;
    }
    return check(number/10);
}

int main(void) {

    long long unsigned int n = 98666631111;

    printf("check asc order from right to left: %d\n", check(n));

    return EXIT_SUCCESS;
}