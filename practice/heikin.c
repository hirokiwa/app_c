// int２つの整数を与えて平均を表示

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc != 3){
        puts("引数の個数が違います。");
        exit(1);
    }

    float average;
    average = (float)(atoi(argv[1]) + atoi(argv[2])) / 2;
    printf("平均＝%f\n",average);

    return(0);
}