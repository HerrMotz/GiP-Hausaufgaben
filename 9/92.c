/*
 * Datei: 92.c
 * Daniel Motz
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int verbose = 0;

char *encipher(char string[], int key) {
    char *encipher;
    encipher = malloc(strlen(string));

    for (int i = 0; string[i] != 0; ++i) {
        if (string[i] != 32) {
            /* this, sadly, is implementation defined */
            encipher[i] = (string[i] + key - 65 + 26) % 26 + 65;
        } else {
            encipher[i] = 32;
        }
        if (verbose) {
            printf("%c %d %c %d\n", string[i], string[i], encipher[i], encipher[i]);
        }
    }
    return encipher;
}

char *decipher(char string[], int key) {
    char *decipher;
    decipher = malloc(strlen(string));

    for (int i = 0; string[i] != 0; ++i) {
        if (string[i] != 32) {
            /* this, sadly, is implementation defined */
            decipher[i] = (string[i] - key - 65 + 26) % 26 + 65;
        } else {
            decipher[i] = 32;
        }
        if (verbose) {
            printf("%c %d %c %d\n", string[i], string[i], decipher[i], decipher[i]);
        }
    }
    return decipher;
}

int main(void) {
    /* ASSUMES ASCII UPPERCASE CHARACTERS WITH 25 ENCRYPTION ALPHABETS AND 1 SOURCE ALPHABET */

    /* Test case */
    if (strcmp(decipher("CXZ", 3), "ZUW") == 0)
        printf("[self assert] Decipher: Test successful!\n");
    else
        printf("[self assert] Decipher: Test failed\n");

    if (strcmp(encipher("ZUW", 3), "CXZ") == 0)
        printf("[self assert] Decipher: Test successful!\n");
    else
        printf("[self assert] Decipher: Test failed\n");

    /* Task */
    char code[] = "YLHOH NDPHQ DOOPDHKOLFK CX GHU XHEHUCHXJXQJ HLQHQ JURVVHQ IHKOHU "
                  "JHPDFKW CX KDEHQ DOV VLH YRQ GHQ EDHXPHQ KHUXQWHUJHNRPPHQ ZDUHQ XQG "
                  "HLQLJH VDJWHQ VFKRQ GLH EDHXPH VHLHQ HLQ KROCZHJ JHZHVHQ GLH RCHDQH "
                  "KDHWWH PDQ QLHPDOV YHUODVVHQ GXHUIHQ";

    char *message = decipher(code, 3);
    printf("\nDeciphered:\n%s\n", message);

    message = encipher(message, 3);
    printf("\nEnciphered:\n%s\n", message);

    /* and because the task specifically asks for it, we can also encrypt using ROT26 */
    message = encipher("SECRET MESSAGE", 26);
    printf("\nROT26:\n%s\n", message);

    return EXIT_SUCCESS;
}