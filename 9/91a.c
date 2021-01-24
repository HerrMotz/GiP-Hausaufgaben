/*
 * Datei: 91a.c
 * Daniel Motz
 *
 * */

#include <stdio.h>
#include <stdlib.h>

int f (int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return f(n-1) + f(n-2);
}

int main(void) {

    int n;
    printf("Recursive fibonacci. Please enter a number n and we will give you the nth fibonacci number:\n");
    scanf("%d", &n);

    printf("f(n): %d\n", f(n));

    return EXIT_SUCCESS;
}