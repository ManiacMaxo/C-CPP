#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char dir[30];
int max = 0;
int lx, ly;  // largest, location

void apply(int sum, int x, int y) {
    max = sum;
    lx = x;
    ly = y;
}

void horizontal(int matrix[15][15], int n) {
    int i, x, y, s;
    for (y = 0; y < n; y++) {
        for (x = 0; x < n - 4; x++) {
            for (s = 1, i = 0; i < 4; i++) {
                s *= matrix[y][x + i];
            }
            if (s > max) {
                max = s;
                lx = x;
                ly = y;
                strcpy(dir, "horizontal");
            }
        }
    }
}

void vertical(int matrix[15][15], int n) {
    int i, x, y, s;
    for (x = 0; x < n; x++) {
        for (y = 0; y < n - 4; y++) {
            for (s = 1, i = 0; i < 4; i++) {
                s *= matrix[y + i][x];
            }
            if (s > max) {
                max = s;
                lx = x;
                ly = y;
                strcpy(dir, "vertical");
            }
        }
    }
}

void diagonal_right(int matrix[15][15], int n) {
    int i, x, y, s;
    for (y = 0; y < n - 4; y++) {
        for (x = 0; x < n - 4; x++) {
            for (s = 1, i = 0; i < 4; i++) {
                s *= matrix[y + i][x + i];
            }
            if (s > max) {
                max = s;
                lx = x;
                ly = y;
                strcpy(dir, "diagonal horizontal");
            }
        }
    }
}

void diagonal_left(int matrix[15][15], int n) {
    int i, x, y, s;
    for (y = 0; y < n - 4; y++) {
        for (x = n - 1; x > 3; x--) {
            for (s = 1, i = 0; i < 4; i++) {
                s *= matrix[y + i][x - i];
            }
            if (s > max) {
                max = s;
                lx = x - 4;
                ly = y + 4;
                strcpy(dir, "diagonal left");
            }
        }
    }
}

int main() {
    int n = 15;

    /* printf("Enter size: ");
    scanf("%d", &n);
    int(*matrix)[n] = malloc(sizeof(int[n][n])); */

    int matrix[15][15];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    horizontal(matrix, n);
    vertical(matrix, n);
    diagonal_right(matrix, n);
    diagonal_left(matrix, n);
    printf("%d %d %d %s\n", max, lx, ly, dir);
    // free(matrix);
}
