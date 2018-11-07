#include <stdio.h>

int IsDigit(char digit) {
    return (digit >= '0' && digit <= '9');
}

int ToDigit(char digit) {
    if (IsDigit(digit))
        return digit - '0';
    return -1;
}

int contains(unsigned long number, char digit) {
    int d = ToDigit(digit);
    if (d == -1)
        return 0;
    do {
        if (number % 10 == d)
            return 1;
        number /= 10;
    } while (number);
    return 0;
}

int main() {
    unsigned long number;
    char digit;
    printf("Enter a digit: ");
    scanf("%c", &digit);
    printf("\nEnter a number: ");
    scanf("%d", &number);
    printf("\n%d\n", contains(number, digit));
}
