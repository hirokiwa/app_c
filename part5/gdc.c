#include <stdio.h>

int gcd(int m, int n){

    int r = m % n;

    if(r == 0){
        return(n);
    }else{
        return(gcd(n, r));
    }
}

int main(void){
    int m, n;
    do{
        printf("m,n(m >= n)の最大公約数を求めます\n");
        printf("m=");
        scanf("%d",&m);
        printf("n=");
        scanf("%d",&n);
    }while(!(m >= n));

    printf("%d,%dの最大公約数は%dです。\n", n, m, gcd(m,n));

    return(0);
}