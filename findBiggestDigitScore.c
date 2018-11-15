#include <stdio.h>

int findBiggestDigitScore(char *str) {
    int i, max = str[0];
    for(i=0; i<strlen(str); i++) {
            if(str[i] > max)
                max = str[i];
    }
    return max;
}

int main(int argc, char **argv) {

}