/* Datei: bool.c */

#include <stdio.h>

int main(void) {

    /* Aufgabe a) */

    int x = 49;
    int wert1, wert2, wert3, wert4;

    wert1 = !(x >= 0 && x < 50 || x > 50 && x <= 100);
    wert2 = x++ == 49 || x-- == 49;
    wert3 = !(x >= 0 && x < 50 || x > 50 && x <= 100);
    int k;
    scanf("%d", &k);
    wert4 = !(k > 0 && k % 10 <= 7) == (!(k > 0) || !(k % 10 <= 7));
    /* Wert 4 immer wahr, weil:
     * p = k > 0
     * q = k & 10 <= 7
     *      !(k > 0 && k % 10 <= 7) == (!(k > 0) || !(k % 10 <= 7))
     * äqv. !(p && q) == (!p || !q)
     * äqv. !(p && q) == !(p && q)*/

    printf("Zeile 2 %d\nZeile 3 %d\nZeile 4 %d\nZeile 6 %d\n", wert1, wert2, wert3, wert4);

    /* Aufgabe b) */

    // 1.
    int m, n;
    int y,z;
    int a;
    wert1 = !(m > 10) && (n != 9);
    wert2 = (x % 1 == 0) && (y % 1 == 0) && (z % 1 == 0);
    wert3 = (1 < a < 10) || (a < -7);

}