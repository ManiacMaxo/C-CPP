#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LEN 20

char S[2][16];

char F(char x) { return S[0][x >> 6] + S[1][x >> 4]; }

void encrypt(char L, char R, char* out) {
    for (short i = 0; i < 16; i++) {
        R = R ^ F(L);
        L = L ^ F(R);
    }

    int temp = L;
    L = R;
    R = temp;

    out[0] = L;
    out[1] = R;
}

void decrypt(char L, char R, char* out) {
    for (short i = 0; i < 16; i++) {
        R = R ^ F(L);
        L = L ^ F(R);
    }

    int temp = L;
    L = R;
    R = temp;

    out[0] = L;
    out[1] = R;
}

void init_boxes(char* key) {
    int len = strlen(key);
    for (short i = 0; i < 2; i++) {
        for (short j = 0; j < 16; j++) {
            S[i][j] = key[(i * 16 + j) % len];
            // printf("i = %d\tj = %d\tlen = %d\tc = %c\n", i, j, len, S[i][j]);
        }
        // printf("\n");
    }
}

void perform_encryption(char* text, char* key, char* encrypted) {
    init_boxes(key);
    int len = strlen(text), i;
    char out[2];
    for (i = 1; i < len; i += 2) {
        encrypt(text[i - 1], text[i], out);
        encrypted[i - 1] = out[0];
        encrypted[i] = out[1];
    }
    encrypted[i - 1] = '\0';
}

void perform_decryption(char* encrypted, char* decrypted) {
    int len = strlen(encrypted), i;
    char out[2];
    for (i = 1; i < len; i += 2) {
        decrypt(encrypted[i - 1], encrypted[i], out);
        decrypted[i - 1] = out[0];
        decrypted[i] = out[1];
    }
    decrypted[i - 1] = '\0';
}

int main(int argc, char** argv) {
    char* key = "asdfG";
    char* text = "albalanica";
    init_boxes(key);
    char encrypted[MAX_TEXT_LEN + 1];
    perform_encryption(text, key, encrypted);
    printf("encrypted: %s\n", encrypted);

    char decrypted[MAX_TEXT_LEN + 1];
    perform_decryption(encrypted, decrypted);
    printf("decrypted: %s\n", decrypted);
}
