#include <stdio.h>

char dir[13];
int lx, ly;  // largest, location

void apply(int sum, int *largest, int x, int y) {
    largest = sum;
    lx = x;
    ly = y;
}

int largest_sum_matrix(int **arr) {
    int largest_sum = -1, sum;
    for (int y = 0; y < 15; y++) {
        for (int x = 0; x < 15; x++) {
            if (y >= 3) {  // up
                sum = arr[y][x] + arr[y - 1][x] + arr[y - 2][x] + arr[y - 3][x];
                if (sum > largest_sum) {
                    apply(sum, largest_sum, x, y);
                    strcpy(dir, "up");
                }
            }
            if (y <= 11) {  // down
                sum = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 3][x];
                if (sum > largest_sum) {
                    apply(sum, largest_sum, x, y);
                    dir = "down";
                }
            }
            if (x >= 3) {  // left
                sum = arr[y][x] + arr[y][x - 1] + arr[y][x - 2] + arr[y][x - 3];
                if (sum > largest_sum) {
                    apply(sum, largest_sum, x, y);
                    dir = "left";
                }
            }
            if (x <= 11) {  // right
                sum = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y][x + 3];
                if (sum > largest_sum) {
                    apply(sum, largest_sum, x, y);
                    dir = "right";
                }
            }

            if (y >= 3 && x >= 3) {  // up & left
                sum = arr[y][x] + arr[y - 1][x - 1] + arr[y - 2][x - 2] + arr[y - 3][x - 3];
                if (sum > largest_sum) {
                    apply(sum, largest_sum, x, y);
                    dir = "up & left";
                }
            }
            if (y >= 3 && x <= 11) {  // up  & right
                sum = arr[y][x] + arr[y - 1][x + 1] + arr[y - 2][x + 2] + arr[y - 3][x + 3];
                if (sum > largest_sum) {
                    apply(sum, largest_sum, x, y);
                    dir = "up & right";
                }
            }
            if (y <= 11 && x >= 3) {  // down  & left
                sum = arr[y][x] + arr[y - 1][x - 1] + arr[y - 2][x - 2] + arr[y - 3][x - 3];
                if (sum > largest_sum) {
                    apply(sum, largest_sum, x, y);
                    dir = "down & left";
                }
            }
            if (y <= 11 && x <= 11) {  // down  & right
                sum = arr[y][x] + arr[y - 1][x + 1] + arr[y - 2][x + 2] + arr[y - 3][x + 3];
                if (sum > largest_sum) {
                    apply(sum, largest_sum, x, y);
                    dir = "down & right";
                }
            }
        }
    }
}

int main() {
    int arr[15][15];
}
