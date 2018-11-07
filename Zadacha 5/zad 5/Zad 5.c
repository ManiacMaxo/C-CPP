#include <stdio.h>
#include <string.h>

int StringCompare(char *str1, char *str2) {
    int i = 0;
    while ((str1[i] - str2[i] == 0) && (str1[i] != '\0')) i++;
    return (str1[i] - str2[i] > 0) - (str1[i] - str2[i] < 0);
}

int main() {
    printf("%d\n", StringCompare("asd", "asc"));
    printf("%d\n", StringCompare("qwe", "qwt"));
    printf("%d\n", StringCompare("asd", "asd"));
}
