#include <stdio.h>
#include <stdlib.h>

/* Aufgabe a)
 * Fibonacci-Zahlen */
int f (int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return f(n-1) + f(n-2);
}

/* Aufgabe b)
 * Vorkommen einer Ziffer in einer Zahl */
int countDigitOccurences(long long int number, int digit) {
    if (number < 10)
        if (number == digit)
            return 1;
        else
            return 0;
    else if (number % 10 == digit)
        return 1 + countDigitOccurences(number/10, digit);
    else if (number != 0)
        return countDigitOccurences(number/10, digit);
}

/* Aufgabe c)
 * Prüfen, ob eine Zahl von links nach rechts absteigend sortiert ist */
int checkAscRTL(long long int number) {
    if (number < 10) {
        return 1;
    } else if (number % 10 > number / 10 % 10) {
        return 0;
    }
    return checkAscRTL(number/10);
}

int main(void) {

    int end = 0;
    char sub;
    long long int llui;

    /* Test case */

    printf("[self assert] Fibonacci-Sequence:\tTest ");
    if (f(0) == 1 && f(1) == 1 && f(3) == 3 && f(4) == 5 && f(7 == 21))
        printf("successful!\n");
    else
        printf("failed\n");

    printf("[self assert] Digit occurences:\t\tTest ");
    if (countDigitOccurences(0, 0) == 1 && countDigitOccurences(1234, 0) == 0 && countDigitOccurences(10, 0) == 1 && countDigitOccurences(98666631111, 6) == 4 && countDigitOccurences(1, 1) == 1)
        printf("successful!\n");
    else
        printf("failed\n");

    printf("[self assert] checkAscRTL:\t\t\tTest ");
    if (checkAscRTL(98666631111) == 1 && checkAscRTL(4562313488) == 0 && checkAscRTL(1) == 1)
        printf("successful!\n");
    else
        printf("failed\n");

    printf("\nBitte wählen Sie ein Unterprogramm:\n\na) Fibonacci-Zahlen\nb) Vorkommen einer Ziffer\nc) Absteigend sortiert links nach rechts\n\nAuswahl: ");
    scanf(" %c", &sub);
    getchar();

    /* Task */

    int n, m;

    if (sub == 'a') {
        printf("Recursive fibonacci. Please enter a number n and we will give you the nth fibonacci number:\n");
        scanf("%d", &n);
        printf("f(%d): %d\n", n, f(n));

    } else if (sub == 'b') {
        printf("Digit counter. Please enter a number and the digit, of which we will give you the amount of occurences in the number:\n");
        scanf("%llu %d", &llui, &m);
        printf("occurences: %d\n", countDigitOccurences(llui, m));

    } else if (sub == 'c') {
        scanf("%llu", &llui);
        printf("%llu sorted descending left to right?: %d\n", llui, checkAscRTL(llui));
    }

    return EXIT_SUCCESS;
}
