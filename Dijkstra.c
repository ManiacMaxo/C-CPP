#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *dist;
int **map;

int find(int start, int finish, int from, int n) {
    if (dist[start] > 0) {
        return dist[start];
    }
    int min = INT_MAX, res;
    dist[start] = min;
    for (int i = 0; i < n; i++) {
        if (i == from) {  // skip the branch we came from
            continue;
        }
        if (map[start][i] > 0) {  // is there a direct connection?
            if (i == finish) {    // is that the final node we're looking for?
                res = map[start][i];
            } else {  // recursive dive
                res = map[start][i] + find(i, finish, start, n);
            }
        }
        if (res < min) min = res;
        //        if (min == 1) break;  // don't go further if distance of 1 is found.
    }
    dist[start] = min;
    return min;
}

int main() {
    FILE *file = fopen("in.txt", "r");
    int n;
    fscanf(file, "%d", &n);
    map = malloc(n * sizeof(int));
    dist = malloc(n * n * sizeof(int));
    for (int i = 0; i < n; i++) {
        map[i] = malloc(n * sizeof(int));
        dist[i] = 0;
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &map[i][j]);
        }
    }
    fclose(file);
    int start, finish;

    scanf("%d %d", &start, &finish);
    printf("%d\n", find(start, finish, start, n));
}
