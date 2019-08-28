#include <stdio.h>

int findBiggestnumberScore(unsigned int number) {
    int max = number % 10;
    while (number) {
        if (number % 10 > max)
            max = number % 10;
        number /= 10;
    }
    return max;
}

int main(int argc, char **argv) {
    printf("%d\n", findBiggestnumberScore(atoi(argv[1])));
}
