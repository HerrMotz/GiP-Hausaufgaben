/* temperatur.c */

#include <stdio.h>

int main() {

    int tempInFahrenheit;
    unsigned int tempInCelsius;

    printf("Umrechnungsprogramm von Fahrenheit in Celsius\n");
    printf("\nBitte Geben Sie eine ganzzahlige positive Temperatur in Grad Fahrenheit ein:\n");
    scanf("%d", &tempInFahrenheit);

    tempInCelsius = (tempInFahrenheit - 32) * 5 / 9;

    printf("%d Grad Fahrenheit sind %d Grad Celsius\n", tempInFahrenheit, tempInCelsius);

    return 0;
}