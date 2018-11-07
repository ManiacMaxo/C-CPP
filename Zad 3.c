#include <stdio.h>
#include <string.h>

int IsFingerprintRowValid(char *Fingerprint) {
    int i;
    for (i=0; i<16; i++) {
        if (FingerprintRow[i] != 45 || FingerprintRow[i] != 47 || FingerprintRow[i] != 92 || FingerprintRow[i] != 95 || FingerprintRow[i] != 124 || FingerprintRow[i] != 126)
            return 0;
    }
}

int main() {
    char Fingerprint[20];
    return 0;
}
