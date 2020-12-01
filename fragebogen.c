/* fragebogen.c */

#include <stdio.h>

int main() {
    char blutgruppe;
    int alter;
    float sixteenDividedBy3;
    char ersterBuchstabeVorname;
    float cosOfSqrt6PlusSqrt2AllDividedBy4;

    printf("Der einzugebende Buchstabe fuer Ihre Auswahl steht in Klammern.");
    printf("\nIst Ihre Blutgruppe (A), (B), AB (X) oder (N)ull?\n");
    scanf(" %c", &blutgruppe);
    printf("\nWie alt sind Sie?\n");
    scanf("%d", &alter);
    printf("\nWas ist das Ergebnis von 16 geteilt durch 3? (Angabe bitte als approximierte Kommazahl)\n");
    scanf(" %f", &sixteenDividedBy3);
    printf("\nWas ist der erste Buchstabe Ihres ersten Vornamen?\n");
    scanf(" %c", &ersterBuchstabeVorname);
    printf("\nWas ist das Ergebnis vom Cosinus aus Wurzel 6 und Wurzel 2 und beides geteilt durch 4? (Angabe bitte als approximierte Kommazahl)\n");
    scanf(" %f", &cosOfSqrt6PlusSqrt2AllDividedBy4);
    printf("\n");

    printf("\nEs wurde eine Frage gestellt, aber das Programm hat Sie nicht nach einer Antwort gefragt? Pruefen Sie Ihre Eingaben. Kommazahlen bitte mit Punkt statt Komma angeben.\nIhre Antworten in umgekehrter Reihenfolge:\n");
    printf("Blutgruppe: %.2f\tAlter: %c\t16/3: %.2f\tAlter: %d\tBlutgruppe: %c", cosOfSqrt6PlusSqrt2AllDividedBy4, ersterBuchstabeVorname, sixteenDividedBy3, alter, blutgruppe);
    return 0;
}