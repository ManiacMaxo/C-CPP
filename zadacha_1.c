#include <stdio.h>
#include <math.h>

typedef struct {
    int diameter;
    int flow;
} tpipes;

typedef struct {
    tpipes inPipes[5];
    tpipes outPipes[5];
    int volume;
} tpool;

double fillTime(tpool pool) {
    double flowRate = 0;
    int numInPipes = sizeof(pool.inPipes) / sizeof(tpipes), numOutPipes = sizeof(pool.outPipes) / sizeof(tpipes);
    for (int i = 0; i < numInPipes; i++)
        // Q = v · π · (d / 2)²
        flowRate += pool.inPipes[i].flow * M_PI * pow(pool.inPipes[i].diameter / 2, 2);
    for (int i = 0; i < numOutPipes; i++)
        flowRate -= pool.outPipes[i].flow * M_PI * pow(pool.outPipes[i].diameter / 2, 2);
    return flowRate < 0 ? -1 : pool.volume / flowRate;
}

int main() {
    tpool pool;

    int numInPipes, numOutPipes;
    printf("Enter number of pipes: ");
    scanf("%d", &numInPipes);
    scanf("%d", &numOutPipes);
    printf("Enter in pipes: ");
    for (int i = 0; i < numInPipes; i++) {
        scanf("%d",&pool.inPipes[i].diameter);
        scanf("%d",&pool.inPipes[i].flow);
    }
    printf("Enter out pipes: ");
    for (int i = 0; i < numOutPipes; i++) {
        scanf("%d",&pool.outPipes[i].diameter);
        scanf("%d",&pool.outPipes[i].flow);
    }
    printf("Enter pool volume: ");
    scanf("%d", &pool.volume);

    printf("%f\n", fillTime(pool));
    return 0;
}