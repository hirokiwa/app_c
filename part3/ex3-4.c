#include <stdio.h>

void saidai(int *x, int *y, int *z){
    *x = (*x > *y)? *x : *y;
    *x = (*x > *z)? *x : *z;
}

int main(void){

    int x,y,z;

    printf("xの整数を入力してください。x=");
    scanf("%d",&x);
    printf("yの整数を入力してください。y=");
    scanf("%d",&y);
    printf("zの整数を入力してください。z=");
    scanf("%d",&z);

    saidai(&x, &y, &z);

    printf("最大値は%d\n",x);

    return(0);
}