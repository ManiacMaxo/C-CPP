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

void largest_sum_matrix(int matrix[15][15]) {
    int sum;
    for (int y = 0; y < 15; y++) {
        for (int x = 0; x < 15; x++) {
            if (y < 12) {
                sum = matrix[y][x] + matrix[y + 1][x] + matrix[y + 2][x] + matrix[y + 3][x];
                if (sum > max) {
                    apply(sum, x, y);
                    strcpy(dir, "vertical");
                }
            }
            if (x < 12) {
                sum = matrix[y][x] + matrix[y][x + 1] + matrix[y][x + 2] + matrix[y][x + 3];
                if (sum > max) {
                    apply(sum, x, y);
                    strcpy(dir, "horizontal");
                }
            }
            if (y < 12 && x > 2) {
                sum = matrix[y][x] + matrix[y - 1][x - 1] + matrix[y - 2][x - 2] + matrix[y - 3][x - 3];
                if (sum > max) {
                    apply(sum, x, y);
                    strcpy(dir, "diagonal left");
                }
            }
            if (y < 12 && x < 12) {
                sum = matrix[y][x] + matrix[y - 1][x + 1] + matrix[y - 2][x + 2] + matrix[y - 3][x + 3];
                if (sum > max) {
                    apply(sum, x, y);
                    strcpy(dir, "diagonal right");
                }
            }
        }
    }
}

/*

void horizontal(int matrix[15][15]) {
    int i, x, y, s;
    for (y = 0; y < 15; y++) {
        for (x = 0; x < 15 - 4; x++) {
            for (s = 0, i = 0; i < 4; i++) {
                s += matrix[y][x + i];
            }
            if (s > max) {
                max = s;
                lx = x;
                ly = y;
                strcpy(dir, "horizontal");
            }
        }
    }
    //printf("%d %d %d %s\n", max, ly, lx, dir);
}

void vertical(int matrix[15][15]) {
    int i, x, y, s;
    for (x = 0; x < 15; x++) {
        for (y = 0; y < 15 - 4; y++) {
            for (s = 0, i = 0; i < 4; i++) {
                s += matrix[y + i][x];
            }
            if (s > max) {
                max = s;
                lx = x;
                ly = y;
                strcpy(dir, "vertical");
            }
        }
    }
    //printf("%d %d %d %s\n", max, ly, lx, dir);
}

void diagonal_right(int matrix[15][15]) {
    int i, x, y, s;
    for (y = 0; y < 15 - 4; y++) {
        for (x = 0; x < 15 - 4; x++) {
            for (s = 0, i = 0; i < 4; i++) {
                s += matrix[y + i][x + i];
            }
            if (s > max) {
                max = s;
                lx = x;
                ly = y;
                strcpy(dir, "diagonal horizontal");
            }
        }
    }
    //printf("%d %d %d %s\n", max, ly, lx, dir);
}

void diagonal_left(int matrix[15][15]) {
    int i, x, y, s;
    for (y = 0; y < 15 - 4; y++) {
        for (x = 14; x > 2; x--) {
            for (s = 0, i = 0; i < 4; i++) {
                s += matrix[y + i][x - i];
            }
            if (s > max) {
                max = s;
                lx = x;
                ly = y;
                strcpy(dir, "diagonal left");
            }
        }
    }
    //printf("%d %d %d %s\n", max, ly, lx, dir);
}
 */
int main() {
    int matrix[15][15];
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    /* 
    horizontal(matrix);
    vertical(matrix);
    diagonal_right(matrix);
    diagonal_left(matrix);
    */
    largest_sum_matrix(matrix);
    printf("%d %d %d %s\n", max, ly, lx, dir);
}
