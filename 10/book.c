#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *book, *verbs, *ans;
    book = fopen("book.txt", "r");
    verbs = fopen("verbs.txt", "r");
    ans = fopen("ans.txt", "a");

    char word[30], s[30];
    while (!feof(book)) {
        fscanf(book, "%s", word);
        while (!feof(verbs)) {
            fscanf(verbs, "%s", s);
            if (strstr(word, s)) {
                fprintf(ans, word);
            }
        }
    }
    return 0;
}
