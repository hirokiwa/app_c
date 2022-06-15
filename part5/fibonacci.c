#include <stdio.h>

int count = 0;

int fibonacci(int n){
    count++;

    if(n == 1 || n == 2){
        return(1);
    }else{
        return(fibonacci(n - 2) + fibonacci(n - 1));
    }
    
}

int main(void){

    int n;
    do{
        printf("フィボナッチ数列のn番目の要素を求めます。\n");
        printf("nとして1以上30以下の整数を入力してください。\n");
        printf("n=");
        scanf("%d",&n);
    }while(!(n > 0 || n <= 30));

    printf("%d番目のフィボナッチ数は%dです。\n", n, fibonacci(n));
    printf("finobacci関数呼び出し：%d回\n",count);

    return(0);
}