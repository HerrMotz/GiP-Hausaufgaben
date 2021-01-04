/* Datei: trainingsdaten.c */

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

/* Trainingsdaten
 * Ohne Arrays werden das arithmetische Mittel, Anzahl der Sprünge, zwei größten Weiten und die kleinste Weite und
 * die Differenz von größter und kleinster bestimmt.
 * Es werden solange Werte des Typs Gleitkommazahl eingegeben, bis die Eingabe 0 oder Eingabe einer negativer Zahl erfolgt.
 * Aus diesen Werten sollen die oben genannten Kenngrößen berechnet werden. */


int main(void) {
    float eingabe = 1.0f;
    float summeAllerWeiten = 0.0f;
    float groessteWeite = 0.0f;
    float zweitGroessteWeite = 0.0f;
    float kleinsteWeite = FLT_MAX;
    float tmp;
    int zaehler = 0;

    printf("\nBitte geben Sie die Messwerte für die Sprünge ein.\n");
    while (eingabe > 0.0f) {
        printf("\nSprung Nr. %d: \n", 1+zaehler);
        scanf("%f", &eingabe);

        if (eingabe <= 0.0f){
            printf("break");
            break;
        }

        printf("continue");

        summeAllerWeiten += eingabe;

        if (groessteWeite < eingabe) {
            tmp = groessteWeite;
            groessteWeite = eingabe;

            if (tmp > zweitGroessteWeite)
                zweitGroessteWeite = tmp;

        } else if (zweitGroessteWeite < eingabe) {
            zweitGroessteWeite = eingabe;
        }

        if (kleinsteWeite > eingabe) {
            kleinsteWeite = eingabe;
        }

        zaehler++;
    }

    float mittlereWeite = summeAllerWeiten * (1.0f/(float)zaehler);
    float differenzGroessteKleinsteWeite = groessteWeite - kleinsteWeite;

    printf("\nAnzahl der Sprünge: %d\n", zaehler);
    printf("Größte Weite: %.2f\n", groessteWeite);
    printf("Zweitgrößte Weite: %.2f\n", zweitGroessteWeite);
    printf("kleinste Weite: %.2f\n", kleinsteWeite);
    printf("mittlere Weite: %.2f\n", mittlereWeite);
    printf("Differenz von größter und kleinster Weite: %.2f\n", differenzGroessteKleinsteWeite);

    return EXIT_SUCCESS;
}