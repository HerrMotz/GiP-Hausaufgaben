/* Datei: primfaktor.c */

#include <stdio.h>

int main(void) {
    int number = 0;
    while (number < 2) {
        printf("Bitte geben Sie eine Zahl groesser gleich 2 ein:\n");
        scanf("%i", &number);
    }

    int prime = 2;
    while (prime <= number) {
        while (number % prime != 0) {
            prime++;
        }
        while (number % prime == 0) {
            number /= prime;
            printf("%i\n", prime);
        }
    }
    return 0;
}
