#include <stdio.h>

int findBiggestDigitScore(unsigned int digit) {
    int max = digit%10;
        while(digit) {
            if(digit % 10 > max)
                max = digit % 10;
            digit /= 10;
        }
    return max;
}

int main(int argc, char **argv) {

}