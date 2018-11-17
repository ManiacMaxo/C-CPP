#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

int countOccurences (const char *str, const char *find) {
    int count=0;
    while((str=strstr(str, find))) {
        count++;
        str += strlen(find);
    }
    return count;
}

int findReplace(char *result, const char *str, const char *find, char *replace) {
    int num = 0;
    char *pfind = str;
    char *pstart = str;

    while ((pfind=strstr(pfind, find))) {
        strncpy(result, pstart, (pfind-pstart)); // copy the find before found position to result
        result += (pfind-pstart); // move result
        strncpy(result, replace, strlen(replace)); // add the replaced value
        result += strlen(replace); // move result
        pfind += strlen(find); // move the pointer in the original str
        pstart = pfind; // set the position to start looking for next find
        num++;
    }
    int remaining = strlen(str) - (pstart-str);
    if (remaining>0) {
        strncpy(result, pstart, remaining); // copy or append the remaining find after last substitution (or if no substitutions)
        result += remaining;
    }
    *(result) = NULL; //null terminate the result
    return num;
}

int main() {
    char str[max], find[max], replace[max];
    int num=0;
    
    printf("Enter a string\n");
    gets(str);
    printf("Find: ");
    gets(find);
    printf("Replace: ");
    gets(replace);
    
    int spaceAllocated = strlen(str) + countOccurences(str,find) * (strlen(replace)-strlen(find)) + 1;
    char result[spaceAllocated];
    
    num = findReplace(result, str, find, replace);
    
    printf("Replacements: %d Result:\n%s\n", num, result);
    
    return 0;
}


