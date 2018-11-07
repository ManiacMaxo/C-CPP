#include <stdio.h>
#include <string.h>
#define max 100

int myFind(char *str, char *find) {
    int i, j=0;
    for(i=0; i<strlen(str); i++) {
        if(str[i]==find[j]) {
            while(str[i]==find[j]) {
                j++;
                if(j==strlen(find))
                    return 1;
            }
        }
    }
    return 0;
}

int main() {
    char str[max], find[max];
    printf("Enter a string\n");
    gets(str);
    printf("Enter what to find: ");
    gets(find);
    if(myFind(str, find)==1)
        printf("It is found in the string");
    else printf("It is not found in the string");
}
