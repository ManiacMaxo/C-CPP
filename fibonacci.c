#include <stdio.h>

int fibo(int n){
    int a=1, b=1, c=0, i;
    for(i=0; i<n; i++){
        c = a + b;
        a = b; 
        b = c;
    }
    return c;
}

int main(){
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("The %dth number of fibonacci is: %d \n", n, fibo(n));
}
