#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, x, c, k, a[100];
    srand(0);
    for (i = 0; i < 100; i++) {
        a[i] = rand() % (100 + 1 - 0) + 0;
    }
    
    for(i=0; i<100; i++) {
        for(k=0; k<=99; k++){
            if(a[k]>a[k+1]){
                c = a[k];
                a[k] = a[k+1];
                a[k+1] = c;
            }
        }
    }
    
    printf("Number you want to find: ");
    scanf("%d", &x);
    
    for(i=0; i<=100 ;i++) {
        if(x==a[i])
            return 1;
    }
    return 0;
}
