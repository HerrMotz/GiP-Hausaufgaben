/* Datei_ berechnung_pi.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    printf("Geben Sie an, mit welcher Genauigkeit Pi berechnet werden soll (Angabe als Kommazahl):\n");
    float precisionInput;
    scanf("%f", &precisionInput);
    precisionInput = fabsf(precisionInput);

    float pi = 0.0f;
    float Vorzeichen;
    int i = 0;

    while (precisionInput < 1.0f) {

        if (i++ % 2 == 0)
            Vorzeichen = 1.0f;
        else
            Vorzeichen = -1.0f;

        pi += Vorzeichen * (1.0f/(2.0f * (i-1) + 1.0f));
        precisionInput *= 10;
    }

    pi *= 4;

    printf("berechnetes Pi: %f\n", pi);
    printf("math.h Pi: %f\n", M_PI);
    printf("Abweichung: %f\n", fabsf(pi - M_PI));

    return EXIT_SUCCESS;
}