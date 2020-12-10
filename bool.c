/* Datei: bool.c */

#include <stdio.h>
#include <string.h>

int main(void) {

    /* Aufgabe a) */

    int x = 49;
    int wert1, wert2, wert3, wert4;

    wert1 = !(x >= 0 && x < 50 || x > 50 && x <= 100);
    wert2 = x++ == 49 || x-- == 49;

    int r = 49;
    printf("r: %d\n", r);
    r++;
    printf("r: %d\n", r);
    r--;
    printf("r: %d\n", r);
    wert3 = !(x >= 0 && x < 50 || x > 50 && x <= 100);
    int k = 3;
    //scanf("%d", &k);
    wert4 = !(k > 0 && k % 10 <= 7) == (!(k > 0) || !(k % 10 <= 7));
    /* Wert 4 immer wahr, weil:
     * p = k > 0
     * q = k & 10 <= 7
     *      !(k > 0 && k % 10 <= 7) == (!(k > 0) || !(k % 10 <= 7))
     * äqv. !(p && q) == (!p || !q)
     * äqv. !(p && q) == !(p && q)*/

    printf("Zeile 2 %d\nZeile 3 %d\nZeile 4 %d\nZeile 6 %d\n", wert1, wert2, wert3, wert4);

    /* Aufgabe b) */

    int Aussage1, Aussage2, Aussage3, Aussage4;
    char inDerAufgabenstellungGemeint[] = "offenes Intervall";

    int m = 10;
    int n = 8;

    // 1) m ist nicht groesser als 10 und die Variable n ist ungleich 9
    Aussage1 = !(m > 10) && (n != 9);

    printf("Aussage1: %d\n", Aussage1);

    // 2) Die Variablen x,y,z sind natuerliche Zahlen und durch 5 teilbar
    int y, z;
    x = y = z = 6;
    Aussage2 = (x > 0 && x % 5 == 0) && (y > 0 && y % 5 == 0) && (z > 0 && z % 5 == 0);

    printf("Aussage2: %d\n", Aussage2);

    // 3) Die Variable a liegt im Intervall 1 und 10 oder ist kleiner als -7
    int a = -1;
    if (strcmp(inDerAufgabenstellungGemeint,"offenes Intervall") == 0) {
        // offenes Intervall
        printf("offenes\n");
        Aussage3 = (1 < a && a < 10) || (a < -7);

    } else {
        printf("geschlossenes\n");
        // geschlossenes Intervall
        Aussage3 = (1 <= a && a <= 10) || (a < -7);
    }

    printf("Aussage3: %d\n", Aussage3);

    // 4) immer Wahr
    Aussage4 = 1;

    printf("Aussage4: %d\n", Aussage4);

    unsigned int t = -5.5;
    printf("%f", t);

}