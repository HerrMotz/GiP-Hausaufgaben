/* Datei_ berechnung_pi.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main(void) {
    printf("Geben Sie an, bis zu welchem Delta zwischen n-1 und n Pi berechnet werden soll:\n");
    float precisionInput;
    scanf("%f", &precisionInput);
    precisionInput = fabsf(precisionInput);

    double pi = 0;
    double old_pi = DBL_MAX;
    float Vorzeichen;
    int n = 0;

    while (fabs(old_pi - pi) > precisionInput) {
        if (n % 2 == 0)
            Vorzeichen = 1.0f;
        else
            Vorzeichen = -1.0f;
        old_pi = pi;
        pi += 4.0 * Vorzeichen * (1.0 / (2.0 * n + 1.0));
        n++;
    }

    printf("berechnetes Pi: %.*f\n", DECIMAL_DIG, pi);
    printf("Durchlaeufe: %d\n", n);
    printf("\nmath.h Pi: %.*f\n", DECIMAL_DIG, M_PI);
    printf("Abweichung: %f\n", fabs(pi - M_PI));

    return EXIT_SUCCESS;
}