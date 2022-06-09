#include <stdio.h>
#include <stdlib.h>

int main(void){

    int h;

    puts("段数を入れてください");
    printf("段数＝");
    scanf("%d", &h);
    printf("\n");

    char filename[] = "pyramid.txt";
    FILE *fp;

    fp = fopen(filename, "w");

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= (i - 1); j++){
            fprintf(fp, " ");
        }
        for(int j = 1; j <= (2 * h - (2 * i - 1)); j++){
            fprintf(fp, "%d", i % 10);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    
    return(0);
}