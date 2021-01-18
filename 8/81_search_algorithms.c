/*
 * Datei: 81_search_algorithms.c
 * Daniel Motz
 *
 * */

#include <stdio.h>
#include <stdlib.h>


const int PRIME_LIMIT = 100;


/* Aufgabe a)
 * */
int binarySearch(int n, int *a, int l) {
    int middle, left, right;

    left = 0;
    right = l - 1;

    while (left <= right) {

        middle = (left + right) / 2;

        if (a[middle] > n) {
            right = middle - 1;
        } else if (a[middle] < n) {
            left = middle + 1;
        } else {
            return middle;
        }
    }

    return -1;
}


int linearSearch(int n, int *a, int l) {
    for (int i = 0; i < l; ++i) {
        if (a[i] == n)
            return i;
    }
    return -1;
}
/*
 * end Aufgabe a) */


/* Aufgabe c)
 * */
int binarySearchWithPointers(int n, int *a, int l) {
    int *left, *right, *m;

    left = a;
    right = a+l-1;

    while (left <= right) {
        m = left + (right - left) / 2;

        if (n < *m) {
            right = m - 1;
        } else if (n > *m) {
            left = m + 1;
        } else {
            return m - a;
        }
    }

    return -1;
}
/*
 * end Aufgabe c) */


int main(void) {

    /* Sieve of Eratosthenes */
    int n = PRIME_LIMIT;
    int primes[PRIME_LIMIT];

    int * end = &primes[0]+PRIME_LIMIT;
    for (int * i = primes; i != end; ++i) *i = 1;

    for (int p = 2; p * p <= n; p++)
    {
        if (primes[p] == 1)
        {
            for (int i = p * p; i <= n; i += p){
                primes[i] = 0;
            }
        }
    }

    /* sad and ugly mapping */
    int primeIsValue[PRIME_LIMIT];
    int counter = 0;

    for (int i = 0; i <= PRIME_LIMIT; i++) {
        if (primes[i] == 1 && i >= 2) {
            primeIsValue[counter++] = i;
        }
    }


    /* self assert test */
    if (binarySearchWithPointers(31, primeIsValue, counter) == 10)
        printf("[self assert] decimalToBinary: Test successful!\n");
    else
        printf("[self assert] binarySearchWithPointers in primes failed.\n");


    /* Aufgabe b) */
    int search, result;

    printf("Please enter a number and we will tell you which position it is:\n");
    scanf("%d", &search);
    result = binarySearchWithPointers(search, primeIsValue, counter);

    if (result == -1) {
        printf("We're sorry! The number you entered is not a prime :(\n%d", result);
    } else {
        printf("position: %d\n", result);
    }

    return EXIT_SUCCESS;
}