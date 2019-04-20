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

void horizontal(int **matrix, int n) {
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

void vertical(int **matrix, int n) {
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

void diagonal_right(int **matrix, int n) {
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

void diagonal_left(int **matrix, int n) {
    int i, x, y, s;
    for (y = 0; y < n - 4; y++) {
        for (x = n; x > 2; x--) {
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
    int n;
    int matrix[15][15];
    printf("Enter size: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    horizontal(matrix, n);
    vertical(matrix, n);
    diagonal_right(matrix, n);
    diagonal_left(matrix, n);
    printf("%d %d %d %s\n", max, ly, lx, dir);
}
