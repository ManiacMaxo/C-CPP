#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void print(int *dist, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");
}

int dijkstra(int start, int finish, int n, int map[n][n]) {
    int dist[n], been[n];
    int next;
    int i, j;

    for (i = 0; i < n; i++) {  // distance from first point
        been[i] = 0;
        dist[i] = map[start][i];
    }
    been[start] = 1;

    for (i = 0; i < n; i++) {  // find next point
        if (dist[i] != -1 && dist[i] != INT_MAX) {
            next = i;
            break;
        }
    }

    for (int k = 1; k < n - 1; k++) {
        print(dist, n);
        for (j = 0; j < n; j++) {
            if (dist[next] + map[next][j] < dist[j] && been[j] == 0 && next != j) {
                dist[j] = dist[next] + map[next][j];
            }
        }

        been[next] = 1;
        for (i = 0; i < n; i++) {
            if (dist[i] != INT_MAX && been[i] == 0 && i != finish) {
                next = i;
                break;
            }
        }
    }
    return dist[finish];
}
/* 
int find(int start, int finish, int n, int map[n][n]) {
    int dist[n];  // from start to point i
    int *been = malloc(n * sizeof(int));
    i, j, next;

    for (i = 0; i < n; i++) {  // from first point
        dist[i] = map[start][i];
        been[i] = 0;
    }
    been[start] = 1;
    print(dist, n);

    for (i = 0; i < n; i++) {  // next from first
        if (dist[i] != -1 && dist[i] != INT_MAX) {
            next = i;
            break;
        }
    }

    for (i = 0; i < n - 1; i++) {  // every other point except the finish
        print(dist, n);
        printf("next: %d\n", next);
        for (j = 0; j < n; j++) {
            if (!been[j] && j != finish) {
                if (dist[next] + map[i][j] < dist[j]) {
                    dist[j] = map[i][j] + dist[next];
                }
            }
        }
        been[next] = 1;
        for (int k = 0; k < n; k++) {
            if (dist[k] != INT_MAX && !been[k] && k != finish) {
                next = k;
                break;
            }
        }
    }
    free(been);
    return dist[finish];
}
 */
int main() {
    FILE *file = fopen("in.txt", "r");
    int n;
    fscanf(file, "%d", &n);
    int map[n][n];

    for (int i = 0; i < n; i++) {  // set adj matrix
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &map[i][j]);
            if (map[i][j] == 0) {
                map[i][j] = INT_MAX;
            }
        }
    }
    fclose(file);
    int start, finish;

    printf("Enter start and finish:");
    scanf("%d %d", &start, &finish);
    printf("%d\n", dijkstra(start, finish, n, map));
}
