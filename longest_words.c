#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int words(char text[]) {
    int len = strlen(text);
    int m_len = 0, c_len = 0;  // max & current
    int count = 0;             // number of longest words
    for (int i = 0; i < len; i++) {
        while ((text[i] > 'A' && text[i] < 'Z') || (text[i] > 'a' && text[i] < 'z') || text[i] == '\'' || text[i] == '-') {
            c_len++;
            i++;
        }

        if (c_len == m_len) {
            count++;
        }
        if (c_len > m_len) {
            m_len = c_len;
            count = 1;
        }
        c_len = 0;
    }
    return count;
}

int main() {
    char *input = malloc(200 * sizeof(char));
    fgets(input, 200, stdin);
    printf("Number of longest words: %d\n", words(input));
}
