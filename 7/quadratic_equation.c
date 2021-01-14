/* Datei: quadratic_equation.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int solve(double a, double b, double c, double *x1, double *x2) {
    if (a != 1.0f) {
        b = b / a;
        c = c / a;
    }

    double b_halved = b / 2;
    double right_part = sqrt(pow(b_halved, 2) - c);

    if (isnan(right_part)) {
        return 0;
    }

    *x1 = b_halved * -1 + right_part;
    *x2 = b_halved * -1 - right_part;

    if (*x1 == *x2) {
        return 1;
    } else {
        return 2;
    }
}

int main(void) {
    double a, b, c;
    printf("Lösen einer quadratischen Gleichung der Form ax^2 + bx + c = 0:\n");
    printf("Geben Sie a, b, c ein.\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    double x1, x2;
    int anzahl = solve(a, b, c, &x1, &x2);

    if (!anzahl)
        printf("Keine Lösung!");
    else if (anzahl == 1)
        printf("Eine Lösung x: %lf", x1);
    else
        printf("Zwei Lösungen:\nx1: %lf\nx2 %lf", x1, x2);

    return EXIT_SUCCESS;
}
