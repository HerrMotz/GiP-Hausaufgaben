#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *encipher(char string[], int key)
{
    unsigned int l = strlen(string);
    char *krypt = calloc(l, sizeof(char));
    for (int i = 0; i < l; ++i) {
        krypt[i] = (char)((string[i] - 65 + key) % 26 + 65);
    }
    return krypt;
}

int main(void)
{
    char zeichen[] = "SPRACHEZ";
    int key = 3;
    char* string;
    string = encipher(zeichen,key);
    printf("%s", string);
}
