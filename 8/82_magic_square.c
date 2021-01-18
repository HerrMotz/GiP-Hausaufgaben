/*
 * Datei: 82_magic_square.c
 * Daniel Motz
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ** magicSquare (int n) {
    int ** quadrat = calloc(n, sizeof(int*));
    for (int i = 0; i < n; ++i) {
        quadrat[i] = (int*)calloc(n, sizeof(int*));
    }

    int max = n*n;
    int column = n/2;
    int row = n/2+1;
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
    int n = 5;

    if (n % 2 == 0) {
        printf("Bist du dumm?\n");
    }

    int ** quadrat = magicSquare(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", quadrat[i][j]);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}