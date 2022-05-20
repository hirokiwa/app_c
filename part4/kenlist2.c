#include <stdio.h>
#include <stdlib.h>

int main(void){
    char filename[] = "kenmei.txt";
    FILE *fp;
    char ken[10][20];

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("ファイル[%s]のオープンに失敗\n", filename);
        exit(1);
    }

    int k = 0;
    while(fgets(ken[k], 20, fp) != NULL){
        k++;
    }
    
    fclose(fp);

    puts("配列の県名は以下の通りです。");
    for(int i = 0; i <= k; i++){
        printf("%s", ken[i]);
    }

    return(0);
}