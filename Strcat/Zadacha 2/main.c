#include <stdio.h>
#include <string.h>

void concatenate(char *str1, char *str2, char *str3) {
    int i, k, len1=strlen(str1), len2=strlen(str2);
    for (i=0; i<len1; i++)
        str3[i] = str1[i];
    i = len1;
    for (k=0; k<len1+len2-1; k++, i++)
        str3[i] = str2[k];
    str3[len1+len2-1] = '\0';
}

int main() {
    char str1[100], str2[100], str3[200];
    printf("string 1: ");
    scanf("%s", &str1);
    printf("string 2: ");
    scanf("%s", &str2);
    concatenate(str1, str2, str3);
    printf("concatenated string: %s\n", str3);
}
