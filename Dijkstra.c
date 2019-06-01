#include <limits.h>
#include <stdio.h>

int *dist;
int **map;

int main() {
    FILE *file = fopen("in.txt", "r");
    int n = atoi(fgetc(file));
    *dist = malloc(n * sizeof(int));
    **map = malloc(n * n * sizeof(int));
}

int find(int start, int finish, int from, int n) {
    if (dist[start] > 0) {
        return dist[start];
    }
    int min = INT_MAX, res;
    for (int i = 0; i < n; i++) {
        if (map[start][i] == from) {
            continue;
        }
        if (map[start][i] > 0) {
            if (map[start][i] == finish) {
                res = map[start][i];
            } else {
                res = find(map[start][i], finish, from, n);
            }
        }
    }
}

/* 
glob[N] = [0..0]
find(start, finish, from) {
    if glob[start] > 0 return glob[start]
    min = 2^16
    for (each element in "start" row)
        if element == from continue
        if value > 0 {
            if col == finish
                res = value
            else
                res = find(col, finish)
            if res < min then min = res
        }
    glob[start] = min
    return min
}
 */