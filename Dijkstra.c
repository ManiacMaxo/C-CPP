#include <stdio.h>
#include <stdlib.h>
#define MAX_DIST 999

int find(int start, int finish, int n, int map[n][n]) {  // using dijkstra pathfinding algorithm
    int dist[n], been[n];
    int next;
    int i, j;

    for (i = 0; i < n; i++) {
        been[i] = 0;              // blank slate
        dist[i] = map[start][i];  // distance from first point
    }
    been[start] = 1;

    for (i = 0; i < n; i++) {  // find next point
        if (dist[i] != -1 && dist[i] != MAX_DIST) {
            next = i;
            break;
        }
    }

    for (int k = 1; k < n - 1; k++) {
        for (j = 0; j < n; j++) {
            if (dist[next] + map[next][j] < dist[j] && been[j] == 0 && next != j) {
                dist[j] = dist[next] + map[next][j];
            }
        }

        been[next] = 1;
        for (i = 0; i < n; i++) {
            if (dist[i] != MAX_DIST && been[i] == 0 && i != finish) {
                next = i;
                break;
            }
        }
    }
    return dist[finish];
}

int main() {
    FILE *file = fopen("in.txt", "r");
    int n;
    fscanf(file, "%d", &n);
    int map[n][n];

    for (int i = 0; i < n; i++) {  // set adj matrix
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &map[i][j]);
            if (map[i][j] == 0) {
                map[i][j] = MAX_DIST;  // easier to check if route is shorter
            }
        }
    }
    fclose(file);

    int start, finish;
    printf("Enter start and finish: ");
    scanf("%d %d", &start, &finish);
    printf("%d\n", find(start, finish, n, map));
}
