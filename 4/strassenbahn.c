/* Datei: strassenbahn.c */

#include <stdio.h>
#include <stdlib.h>

/*
 * Berechnet den Fahrpreis einer Fahrt in einem Straßenbahnnetz und gibt aus wie der Preis ermittelt wurde.
 *
 * fünf Straßenbahnlinien mit je einer Endstation
 * + eine Ringlinie, welche durch die zweiten Station einer Straßenbahnlinie führt
 *
 * Identifikation einer Haltestelle erfolgt über einen eindeutigen Code
 * <Nummer der Straßenbahnlinie><Haltestellennummer der Linie>
 */

int main(void) {
    int StartHaltestellenNummer;
    int EndhaltestellenNummer;

    printf("Geben Sie Ihre Starthaltestelle ein:\n");
    scanf("%d", &StartHaltestellenNummer);

    printf("Geben Sie Ihre Endhaltestelle ein:\n");
    scanf("%d", &EndhaltestellenNummer);

    int Starthaltestelle_letzteZiffer = StartHaltestellenNummer % 10;
    int Endhaltestelle_letzteZiffer = EndhaltestellenNummer % 10;

    int Starthaltestelle_ersteZiffer = (StartHaltestellenNummer / 10) % 10;
    int Endhaltestelle_ersteZiffer = (EndhaltestellenNummer / 10) % 10;

    int Starthaltestelle_IstStadtzone = (Starthaltestelle_letzteZiffer <= 2);
    int Endhaltestelle_IstStadtzone= (Endhaltestelle_letzteZiffer <= 2);

    int Starthaltestelle_IstEndstation = (Starthaltestelle_letzteZiffer == 5);
    int Endhaltestelle_IstEndstation= (Endhaltestelle_letzteZiffer == 5);

    /* Fahrpreispauschale */
    int Fahrpreis = 3; // Angabe in Euro

    printf("\nBerechnung Ihres Fahrtpreises faellt in folgende Kategorien:\n");
    printf("Fahrpreispauschale: + 3 Euro\n");

    /* Endstationenaufschlag */
    if (Starthaltestelle_IstEndstation) {
        printf("Endstationenaufschlag 1: + 1 Euro\n");
        Fahrpreis += 1;
    }

    if (Endhaltestelle_IstEndstation) {
        printf("Endstationenaufschlag 2: + 1 Euro\n");
        Fahrpreis += 1;
    }

    /* Zonenwechselaufschlag */

    if ((!Starthaltestelle_IstStadtzone && !Endhaltestelle_IstStadtzone)) {
        printf("Zonenwechselaufschlag 2: + 2 Euro\n");
        Fahrpreis += 2;

    } else if (!Starthaltestelle_IstStadtzone && Endhaltestelle_IstStadtzone || Starthaltestelle_IstStadtzone && !Endhaltestelle_IstStadtzone) {
        printf("Zonenwechselaufschlag 1: + 1 Euro\n");
        Fahrpreis += 1;
    }

    /* Kurzstreckenrabatt */

    if (
            (abs(Starthaltestelle_letzteZiffer - Endhaltestelle_letzteZiffer) <= 1 && Starthaltestelle_ersteZiffer == Endhaltestelle_ersteZiffer)           // Auf einer Linie nacheinander
        ||  (abs(Starthaltestelle_ersteZiffer - Endhaltestelle_ersteZiffer) <= 1 && Starthaltestelle_letzteZiffer == 2 && Endhaltestelle_letzteZiffer == 2)  // Auf der Ringlinie nebeneinander
        ||  (StartHaltestellenNummer == 00 && Endhaltestelle_letzteZiffer == 1) // Ausnahme für Zentralhaltestelle
        ||  (EndhaltestellenNummer == 00 && Starthaltestelle_letzteZiffer == 1) // Ausnahme für Zentralhaltestelle
        ||  (StartHaltestellenNummer == 12 && EndhaltestellenNummer == 52 || StartHaltestellenNummer == 52 && EndhaltestellenNummer == 12) // 12 nach 52??
    ) {
        printf("Kurzstreckenrabatt: - 1 Euro\n");
        Fahrpreis -= 1;
    }

    /* Kurzstreckenrabatt-Ausnahmen wg. Streckensperrung */

    if (StartHaltestellenNummer == 42 && EndhaltestellenNummer == 52 || StartHaltestellenNummer == 52 && EndhaltestellenNummer == 42) {
        printf("Ausnahme Kurzstrecke 1: + 1 Euro, da die direkte Strecke zwischen den gewaehlten Haltestellen nicht verfuegbar ist, muss eine Ausweichroute gewaehlt werden.\n");
        Fahrpreis += 1;
    } else if (StartHaltestellenNummer == 00 && EndhaltestellenNummer == 21 || StartHaltestellenNummer == 21 && EndhaltestellenNummer == 00) {
        printf("Ausnahme Kurzstrecke 2: + 1 Euro, da die direkte Strecke zwischen den gewaehlten Haltestellen nicht verfuegbar ist, muss eine Ausweichroute gewaehlt werden.\n");
        Fahrpreis += 1;
    }

    printf("\nDer berechnete Befoerderungsentgelt fuer die angegebenen Haltestellen betraegt\n%d Euro", Fahrpreis);
}