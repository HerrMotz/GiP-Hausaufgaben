/* Datei: zinseszins.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Zineszinstabelle
 * Zinseszins soll für vom Bildschirm eingelesene Daten berechnet werden und in einer Tabelle ausgegeben werden. */


int main(void) {

    double kapital;
    double zinssatz;
    int jahre;

    printf("Zinseszinsprogramm\n Bitte geben Sie die abgefragten Werte ein.\n");

    printf("\nKapitalvermögen / Anfangsvermögen (Kommazahl):\n");
    scanf("%lf", &kapital);

    printf("\nZinssatz (in Prozent):\n");
    scanf("%lf", &zinssatz);
    zinssatz = (zinssatz/100);

    printf("\nJahre (Natürliche Zahl):\n");
    scanf("%d", &jahre);

    double kapitalN;

    while (jahre >= 0) {
        kapitalN = kapital * pow(1 + zinssatz, jahre);
        printf("Jahr %d: \t %.2f\n", jahre, kapitalN);
        jahre--;
    }

    return EXIT_SUCCESS;
}