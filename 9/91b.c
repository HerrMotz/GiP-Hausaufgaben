/*
 * Datei: 91b.c
 * Daniel Motz
 *
 * */

#include <stdio.h>
#include <stdlib.h>

int countDigitOccurences(int number, int digit) {
    if (number % 10 == digit) {
        return 1 + countDigitOccurences(number/10, digit);
    } else if (number != 0) {
        return countDigitOccurences(number/10, digit);
    } else {
        return 0;
    }
}

int main(void) {

    int n, m;
    printf("Digit counter. Please enter a number and the digit, of which we will give you the amount of occurences in the number:\n");
    scanf("%d %d", &n, &m);

    printf("occurences: %d\n", countDigitOccurences(n, m));

    return EXIT_SUCCESS;
}