/*
 * Datei: 92.c
 * Daniel Motz
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int verbose = 0;
const int ASCII_A = 0x41;
const int ASCII_Z = ASCII_A + 0x1a;

char *encipher(char string[], int key) {
    char *encipher;
    encipher = calloc(strlen(string), sizeof(char));

    for (int i = 0; string[i] != 0; ++i) {
        if (ASCII_A <= string[i] && string[i] <= ASCII_Z) {
            encipher[i] = (char)((string[i] + key - 'A' + 0x1a) % 0x1a + 'A');
        } else {
            encipher[i] = string[i];
        }
        if (verbose) {
            printf("%c %d %c %d\n", string[i], string[i], encipher[i], encipher[i]);
        }
    }
    return encipher;
}

char *decipher(char string[], int key) {
    return encipher(string, -key);
}

int main(void) {
    /* ASSUMES ASCII UPPERCASE CHARACTERS WITH 25 ENCRYPTION ALPHABETS AND 1 SOURCE ALPHABET */

    /* Test case */
    if (strcmp(decipher("CXZ", 3), "ZUW") == 0)
        printf("[self assert] Decipher: Test successful!\n");
    else
        printf("[self assert] Decipher: Test failed\n");

    if (strcmp(encipher("ZUW", 3), "CXZ") == 0)
        printf("[self assert] Encipher: Test successful!\n");
    else
        printf("[self assert] Encipher: Test failed\n");

    /* Task */
    char code[] = "YLHOH NDPHQ DOOPDHKOLFK CX GHU XHEHUCHXJXQJ HLQHQ JURVVHQ IHKOHU "
                  "JHPDFKW CX KDEHQ DOV VLH YRQ GHQ EDHXPHQ KHUXQWHUJHNRPPHQ ZDUHQ XQG "
                  "HLQLJH VDJWHQ VFKRQ GLH EDHXPH VHLHQ HLQ KROCZHJ JHZHVHQ GLH RCHDQH "
                  "KDHWWH PDQ QLHPDOV YHUODVVHQ GXHUIHQ";

    char *message = decipher(code, 3);
    printf("\nDeciphered:\n%s\n", message);

    message = encipher(message, 3);
    printf("\nEnciphered:\n%s\n", message);

    /* and because the task specifically asks for it, we can also encipher using ROT26 */
    message = encipher("SECRET MESSAGE", 26);
    printf("\nROT26:\n%s\n", message);

    return EXIT_SUCCESS;
}