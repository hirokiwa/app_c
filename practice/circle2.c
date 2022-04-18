// int 半径を与えて円の面積を表示

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SQR(x) (x * x)

int main(int argc, char *argv[]){
    if(argc != 2){
        puts("引数の個数が違います。");
        exit(1);
    }

    float area = (SQR(atoi(argv[1]))) * M_PI;
    printf("円の面積＝%.2f\n", area);

    return(0);
}