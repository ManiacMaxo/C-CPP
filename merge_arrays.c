#include <stdio.h>

void sort(int *a, int l) {
    int i, j, swap;
    for (i=0; i<l-1; i++){
        for (j=0; j<l-i-1; j++) {
            if (a[j]>a[j+1]){
                swap = a[j];
                a[j] = a[j+1];
                a[j+1] = swap;
            }
        }
    }
}


void my_print(int a[], int l) {
    int i;
    for (i=0; i<l; i++) {
        printf("%d: %d\n", i, a[i]);
    }
}

int main() {
    int a[20], b[20], swap[40], i, aIDX = 0, bIDX = 0, aLEN, bLEN;
    
    printf("How many elements in A and B:\n");
    scanf("%d", &aLEN);
    scanf("%d", &bLEN);
    
    // filling arrays
    printf("elements in array A:\n");
    for (i=0; i<aLEN; i++) {
        scanf("%d", &a[i]);
    }
    printf("elements in array B:\n");
    for (i=0; i<bLEN; i++) {
        scanf("%d", &b[i]);
    }
    
    sort(a, aLEN);
    printf("a sorted:\n");
    my_print(a, aLEN);
    sort(b, bLEN);
    printf("b sorted:\n");
    my_print(b, bLEN);
    
    // merge
    for (i=0; i<aLEN+bLEN; i++){
        if (i==bLEN-1 || b[bIDX] > a[aIDX]) {
            swap[i] = a[aIDX];
            aIDX++;
        } else {
            swap[i] = b[bIDX];
            bIDX++;
        }
    }
    printf("swap sorted:\n");
    my_print(swap, aLEN+bLEN);
}
