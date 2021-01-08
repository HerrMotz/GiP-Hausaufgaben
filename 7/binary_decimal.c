/* Datei: binary_decimal.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int reverse_array(int array[], int places) {
    int start = 0;
    int end = places - 1;
    int temp;
    while (start < end)
    {
        temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}

int binaryToDecimal(int number) {
    int i;
    int decimalNumber = 0;

    for (i = 0; number > 0; i++) {
        decimalNumber += number % 10 * (int)round(pow(2, i));
        number = number / 10;
    }

    return decimalNumber;
}

int decimalToBinary(int number) {
    int i;
    int binaryNumber = 0;
    int places[31];

    for (i = 0; number >= 1; i++) {
        if (number % 2 == 1) {
            places[i] = 1;
        } else {
            places[i] = 0;
        }
        number = number / 2;
    }

    for (i -= 1; i >= 0; i--) {
        binaryNumber *= 10;
        if (places[i] == 1) {
            binaryNumber += 1;
        }
    }
    return binaryNumber;
}

int main(void) {
    int input;

    printf("Enter decimal number to be converted to binary representation:\n");
    scanf("%d", &input);

    int binaryNumber = decimalToBinary(input);
    int decimalNumber = binaryToDecimal(binaryNumber);

    printf("binary representation: %d\n", binaryNumber);
    printf("decimal representation: %d\n", decimalNumber);

    if (decimalNumber == input) {
        printf("[self assert binaryToDecimal == decimalToBinary] Test successful!");
    }

    return EXIT_SUCCESS;
}
