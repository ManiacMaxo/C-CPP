#include <stdio.h>

void concatenate(char *str1, char *str2, char *str3) {
    int i, k;
    for (i=0; i<32; i++)
        str3[i] = str1[i];
    for (k=0; k<64; k++, i++)
        str3[i] = str2[k];
    str3[64] = '\0';
}

int main() {
    char str1[32], str2[32], str3[64];
    printf("string 1: ");
    fgets(str1, 32, stdin);
    printf("string 2: ");
    fgets(str2, 32, stdin);
    concatenate(str1, str2, str3);
    printf("concatenated string: %s", str3);
}
