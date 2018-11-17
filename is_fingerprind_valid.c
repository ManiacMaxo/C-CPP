#include <stdio.h>
#include <string.h>

int IsFingerprintValid(char *Fingerprint) {
    int i;
    if (strlen(Fingerprint) != 16)
        return 0;
    for (i=0; i<16; i++) {
        if (Fingerprint[i] != 45 || Fingerprint[i] != 47 || Fingerprint[i] != 92 || Fingerprint[i] != 95 || Fingerprint[i] != 124 || Fingerprint[i] != 126)
            return 0;
    }
    return 1;
}

int main(int argc, char **argv) {
    int i;
    for (i=0; i<argc; i++)
        printf("Row %d is: %d", i, IsFingerprintValid(argv[i]));
    return 0;
}
