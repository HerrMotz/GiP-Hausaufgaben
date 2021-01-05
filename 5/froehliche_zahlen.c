/* Datei: froehliche_zahlen.c */

#include <stdio.h>
#include <math.h>
#include <time.h>

/* Checks if a value is member of an array */
int in_array(int value, int array[], int limit) {
    /* Parameter limit is necessary, because sizeof a pointer would not work on e.g. IA-32 */
    for (int i = 0; i < limit; ++i) {
        if (array[i] == value) {
            return 1;
        }
    }

    return 0;
}

int reverse_array(int array[], int places) {
    int start = 0;
    int end = places - 1;
    int temp;
    while (start < end)
    {
        temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}

/* Concatenates a char pointer to an integer number */
int concatenate(int array[], int places) {
    int result = 0;

    for (int i = 0; i < places; i++)
    {
        int digits = floor(log10(array[i])) + 1;
        result *= pow(10, digits);
        result += array[i];
    }

    return result;
}

unsigned int factorial (unsigned int f) {
    if (f == 0) {
        return 1;
    }
    return (f * factorial(f-1));
}

/* Creates combinations of a given number, which are smaller than the number */
int make_combinations (int number[], int *combinations, int places) {

    reverse_array(number, places);
    int originalNumber = concatenate(number, places);

    int temp, n = 0;
    int concat;
    for (int j = 1; j <= places; j++) {
        for (int i = 0; i < places - 1; i++) {
            temp = number[i];
            number[i] = number[i + 1];
            number[i + 1] = temp;

            concat = concatenate(number, places);
            if (concat < originalNumber)
                combinations[n++] = concatenate(number, places);
        }
    }

    return n;
}

/* Checks if combinations of a number are in an array */
int combinations_in_array(int *number, int array[], int limit, int places) {
    int combinations[places];
    int n = make_combinations(number, combinations, places);

    for (int i = 0; i < n; ++i) {
        if (in_array(combinations[i], array, limit)) {
            return 1;
        }
    }

    return 0;
}

/* Bestimmt die fröhlichen Zahlen von 1 bis Variable ZahlenBis */
int main(void) {

    clock_t begin = clock();

    int ZahlenBis = 1000;
    int glueckliche_Zahlen[ZahlenBis];
    int gZ_Zaehler = 0;
    int Zahl;

    for (int i = 1; i <= ZahlenBis; ++i) {
        Zahl = i;

        while (Zahl != 20) {
            int AnzahlStellen = (int) floor(log10(Zahl)) + 1;
            int Stellen[AnzahlStellen];
            int Summe = 0;

            for (int j = 0; j < AnzahlStellen; ++j) {
                Stellen[j] = Zahl / round(pow(10, j));
                Stellen[j] = Stellen[j] % 10;
                Summe += round(pow(Stellen[j], 2));
            }

            if (Summe == 1 ||
                in_array(Summe, glueckliche_Zahlen, gZ_Zaehler) == 1 ||
                combinations_in_array(Stellen, glueckliche_Zahlen, gZ_Zaehler, AnzahlStellen) == 1
            ) {
                glueckliche_Zahlen[gZ_Zaehler++] = i;
                break;
            }

            Zahl = Summe;
        }
    }

    for (int i = 0; i < gZ_Zaehler; i++) {
        printf("%d\n", glueckliche_Zahlen[i]);
    }

    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f", time_spent);
    return 0;
}