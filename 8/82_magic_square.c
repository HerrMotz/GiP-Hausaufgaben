/*
 * Datei: 82_magic_square.c
 * Daniel Motz
 *
 * */

#include <stdio.h>
#include <stdlib.h>


int ** magicSquare (int n) {
    int ** quadrat = calloc(n, sizeof(int*));
    for (int i = 0; i < n; ++i) {
        quadrat[i] = (int*)calloc(n, sizeof(int*));
    }

    int max = n*n;
    int column = n/2;
    int row = (n/2+1) % n;
    int i = 1;

    while (i <= max) {
        if (quadrat[row][column] == 0) {
            quadrat[row][column] = i++;
            row = (row + 1) % n;
            column = (column + 1) % n;
        } else {
            while (quadrat[row][column] != 0) {
                row = (row + 1) % n;
                column = (column - 1 + n) % n;
            }
        }
    }

    return quadrat;
}


int main (void) {
    int n;

    /* self assert test */
    if (magicSquare(3)[1][1] == 5 && magicSquare(5)[1][1] == 12 && magicSquare(31)[14][15] == 961)
        printf("[self assert] Magic Square: Test successful!\n");
    else
        printf("[self assert] Magic Square: Test failed.\n");

    printf("\nMagisches Quadrat. Bitte geben Sie eine ungerade Zahl ein:\n");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("(⊙.☉)7\n");
        return EXIT_FAILURE;
    }

    int ** quadrat = magicSquare(n);

    int max_digits = 0;
    int cpy = n*n;
    while (cpy != 0) {
        cpy /= 10;
        max_digits++;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%*d ", max_digits, quadrat[i][j]);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}