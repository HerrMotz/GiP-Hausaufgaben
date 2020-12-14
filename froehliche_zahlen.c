/* Datei: froehliche_zahlen.c */

#include <stdio.h>
#include <math.h>
#include <limits.h>

int main(void) {
    int Zahl;

    Zahl = 500;

    int AnzahlStellen = (int) floor(log10(Zahl)) + 1;

    printf("Anzahl Stellen: %d\n", AnzahlStellen);

    int Stellen[(int) (floor(log10(INT_MAX)) + 1)];

    for (int i = 500; i > 0; --i) {
        Zahl = i;
        int Bedingung = 1;
        while (Zahl != 20) {
            int Summe = 0;
            for (int j = 0; j < AnzahlStellen; ++j) {
                Stellen[j] = Zahl / round(pow(10, j));
                Stellen[j] = Stellen[j] % 10;
                Summe += round(pow(Stellen[j], 2));
            }
            Zahl = Summe;

            if (Summe == 1) {
                printf("%d\n", i);
                break;
            }
        }
    }



}