/* Datei_ berechnung_pi.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    printf("Geben Sie an, mit welcher Genauigkeit Pi berechnet werden soll (Angabe als Kommazahl):\n");
    float precisionInput;
    scanf("%f", &precisionInput);
    precisionInput = fabsf(precisionInput);

    float Summe = 0.0f;

    int i = 0;
    while (precisionInput < 1.0f) {

        int Vorzeichen = -1;
        if (i % 2 == 0)
            Vorzeichen = 1;
        Summe += Vorzeichen * (1.0f/(2.0f * i + 1.0f));

        i++;
        precisionInput *= 10;
    }

    float pi = 4 * Summe;

    printf("berechnetes Pi: %f\n", pi);
    printf("math.h Pi: %f\n", M_PI);
    printf("Abweichung: %f\n", fabsf(pi - M_PI));

    return EXIT_SUCCESS;
}