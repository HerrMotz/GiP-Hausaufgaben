/* quader.c */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int xA, xB, yA, yB, zA, zB;

    // Quader -> acht Punkte
    // Grundfläche -> vier Punkte

    printf("Quaderberechnungen\nBitte geben Sie die zwei gegenueberliegenden Punkte des Quaders ABCDEFGH an, also die Punkte A und G die den Quader aufspannen:\n");
    printf("Punkt A:\n");
    printf("x:");
    scanf("%d", &xA);
    printf("y:");
    scanf("%d", &yA);
    printf("z:");
    scanf("%d", &zA);
    printf("\nPunkt G:\n");
    printf("x:");
    scanf("%d", &xB);
    printf("y:");
    scanf("%d", &yB);
    printf("z:");
    scanf("%d", &zB);

    unsigned int xAusdehnung, yAusdehnung, zAusdehnung;

    xAusdehnung = abs(xB-xA);
    yAusdehnung = abs(yB-yA);
    zAusdehnung = abs(zB-zA);

    unsigned int grundflaeche;
    unsigned int volumen;
    unsigned int kantenlaenge;
    unsigned int oberflaeche;

    // Grundfläche = Kante 1 * Kante 2
    grundflaeche = xAusdehnung * yAusdehnung;
    printf("Grundflaeche: %d FE\n", grundflaeche);

    // Volumen = Grundfläche * Höhe
    volumen = grundflaeche * zAusdehnung;
    printf("Volumen: %d VE\n", volumen);

    // Kantenlänge = (X-Ausdehnung + Y-Ausdehnung + Z-Ausdehnung)*4
    kantenlaenge = (xAusdehnung + yAusdehnung + zAusdehnung)*4;
    printf("Kantenlaenge: %d LE\n", kantenlaenge);

    // Oberfläche = 2X-Ausdehnung * 2Y-Ausdehnung + 2X-Ausdehnung*2Y-Ausdehnung + 2Z-Ausdehnung * 2Y-Ausdehnung
    oberflaeche = (2*(xAusdehnung * yAusdehnung) + 2*(xAusdehnung * yAusdehnung) + 2*(zAusdehnung * yAusdehnung));
    printf("Oberflaeche: %d FE\n", oberflaeche);

    return 0;
}