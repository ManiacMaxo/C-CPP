#include <stdio.h>
#include <string.h>

int palindrome(char *str) {
    int i, j = strlen(str) - 1;
    for (i = 0; i < j; i++, j--) {
        if (str[i] != str[j])
            return 0;
    }
    return 1;
}

int main() {
    char str[100];
    printf("string: ");
    gets(str);
    printf("%d\n", palindrome(str));
}
