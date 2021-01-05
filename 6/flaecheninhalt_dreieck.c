/* Datei: flaecheninhalt_dreieck.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Flächeninhalt eines Dreieck
 * Vom Bildschirm sollen die Koordinaten von drei Punkten R^2 */


int main(void) {

    double  x_1, y_1,
            x_2, y_2,
            x_3, y_3;

    printf("Bitte geben Sie die Punktkoordinaten ein.\n");
    printf("\nPunkt 1:\n x y:\n");
    scanf("%lf %lf", &x_1, &y_1);
    printf("\n\nPunkt 2:\n x y:\n");
    scanf("%lf %lf", &x_2, &y_2);
    printf("\n\nPunkt 3:\n x y:\n");
    scanf("%lf %lf", &x_3, &y_3);

    double a = sqrt(pow(x_2 - x_1, 2) + pow(y_2 - y_1, 2));
    double b = sqrt(pow(x_3 - x_2, 2) + pow(y_3 - y_2, 2));
    double c = sqrt(pow(x_1 - x_3, 2) + pow(y_1 - y_3, 2));

    /* Eine der Seiten ist null
     * schließt den Fall ein, dass zwei punkte identisch sind */
    if (c == 0 || a == 0 || b == 0) {
        printf("Die Eingabewerte ergeben kein gültiges Dreieck. Eine der Seiten ist null.");
        return EXIT_FAILURE;
    }

    /* Dreiecksungleichung
     * schließt auch den Fall ein, dass alle Punkte auf einer Geraden liegen */
    if (a + b <= c || a + c <= b || b + c <= a) {
        printf("Die Eingabewerte ergeben kein gültiges Dreieck. Die Dreiecksungleichung ist verletzt.");
        return EXIT_FAILURE;
    }

    /* Flächeninhalt
     * Satz des Heron */
    double s = (a + b + c) * 0.5f;
    double A = 0.25f * sqrt(s * (s - a) * (s - b)* (s - c));

    printf("Flächeninhalt: %lf", A);

    return EXIT_SUCCESS;
}
