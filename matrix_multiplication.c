#include <stdio.h>
#include <string.h>

char dir[30];
int max = 0;
int lx, ly;  // largest, location

void apply(int sum, int x, int y) {
    max = sum;
    lx = x;
    ly = y;
}

void horizontal(int matrix[15][15]) {
    int i, x, y, s;
    for (y = 0; y < 15; y++) {
        for (x = 0; x < 15 - 4; x++) {
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

void vertical(int matrix[15][15]) {
    int i, x, y, s;
    for (x = 0; x < 15; x++) {
        for (y = 0; y < 15 - 4; y++) {
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

void diagonal_right(int matrix[15][15]) {
    int i, x, y, s;
    for (y = 0; y < 15 - 4; y++) {
        for (x = 0; x < 15 - 4; x++) {
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

void diagonal_left(int matrix[15][15]) {
    int i, x, y, s;
    for (y = 0; y < 15 - 4; y++) {
        for (x = 14; x > 2; x--) {
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
    int matrix[15][15];
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    horizontal(matrix);
    vertical(matrix);
    diagonal_right(matrix);
    diagonal_left(matrix);
    printf("%d %d %d %s\n", max, ly, lx, dir);
}
