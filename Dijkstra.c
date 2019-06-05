#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *dist;
int **map;
/* 
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
 */

void print(int *dist, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");
}

int find(int start, int finish, int n) {
    int i, j;
    int *been = malloc(n * sizeof(int));
    for (j = 0; j < n; j++) {
        been[j] = 0;
        dist[j] = map[start][j];
        if (map[start][j] == 0) {
            dist[j] = INT_MAX;
        }
    }
    print(dist, n);
    been[start] = 1;
    for (i = 0; i < n; i++) {
        print(dist, n);
        for (j = 0; j < n; j++) {
            if (map[i][j] > 0 && !been[j] && j != finish) {
                if ((dist[i] + map[i][j]) < dist[j]) {
                    dist[j] = map[i][j];
                }
            }
            been[j] = 1;
        }
    }
    free(been);
    return dist[finish];
}

int main() {
    FILE *file = fopen("in.txt", "r");
    int n;
    fscanf(file, "%d", &n);
    map = malloc(n * sizeof(int));
    dist = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        map[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &map[i][j]);
        }
    }
    fclose(file);
    int start, finish;

    scanf("%d %d", &start, &finish);
    printf("%d\n", find(start, finish, n));
    free(map);
    free(dist);
}
