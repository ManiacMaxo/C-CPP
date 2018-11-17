#include <stdio.h>
#include <string.h>
#define MAX 100

char str2[MAX];
int search(char *str, char *find) {
    int i, j=0, n=0;
    for(i=0; i<strlen(str); i++) {
        if(str[i] == find[j]) {
            while(str[i] == find[j] && n<strlen(find)) {
                i++; j++; n++;
            }
        }
    }
    j=0;
    while(i<strlen(str)) {
        str2[j] = str[i];
    }
    return n;
}

void replace(char *str, char *replace) {
    int i;
    
}

int main() {
    char str[MAX], find[MAX], replace[MAX];
}
