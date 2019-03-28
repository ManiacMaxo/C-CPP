#include <stdio.h>
#include <string.h>

int longest_num(char *str) {
    int longest = 0, count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            if (!(count == 0 && str[i] == '0')) {
                count++;
            }
        } else {
            longest = count > longest ? count : longest;
            count = 0;
        }
    }
    return longest;
}

int main() {
    char str[250];
    fgets(str, 250, stdin);
    printf("%d\n", longest_num(str));
}
