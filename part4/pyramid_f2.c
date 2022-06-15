#include <stdio.h>
#include <stdlib.h>

int main(void){

    int h;

    puts("段数を入れてください");
    printf("段数＝");
    scanf("%d", &h);
    printf("\n");

    char filename[] = "pyramid_f1.txt";
    FILE *fp;

    fp = fopen(filename, "a");

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= (h - i); j++){
            fprintf(fp, " ");
        }
        for(int j = 1; j <= (i * 2 - 1); j++){
            fprintf(fp, "%d", (h - i + 1) % 10);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    
    return(0);
}