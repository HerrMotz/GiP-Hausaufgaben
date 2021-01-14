/* Datei: binary_decimal.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

    while (number > 0) {
        binaryNumber += i * (number % 10);
        i *= 2;
        number = number / 10;
    }

    return binaryNumber;
}

int main(void) {

    /* user function call */
    int input;

    printf("Enter decimal number to be converted to binary representation:\n");
    scanf("%d", &input);

    int binaryNumber = decimalToBinary(input);
    int decimalNumber = binaryToDecimal(binaryNumber);

    printf("binary representation: %d\n", binaryNumber);
    printf("decimal representation: %d\n", decimalNumber);


    /* Test Case */
    printf("\nStart Test\n");

    int test_number_decimal = 86;
    int test_number_binary = 1010110;

    printf("bin: %d =?= dec: %d\n", test_number_binary, test_number_decimal);

    binaryNumber = decimalToBinary(test_number_decimal);
    decimalNumber = binaryToDecimal(test_number_binary);

    if (decimalNumber != test_number_decimal)
        printf("[self assert] decimalToBinary failed: Could not verify correctness of decimal to binary conversion!\n");
    else
        printf("[self assert] decimalToBinary: Test successful!\n");

    if (binaryNumber != test_number_binary)
        printf("[self assert] binaryToDecimal failed: Could not verify correctness of binary to decimal conversion!\n");
    else
        printf("[self assert] binaryToDecimal: Test successful!\n");

    return EXIT_SUCCESS;
}
