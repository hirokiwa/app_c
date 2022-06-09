#include <stdio.h>
#include <stdlib.h>

int main(void){
    char filename[] = "okeya.txt";
    FILE *fp;
    char data[80];

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("ファイル[%s]のオープンに失敗\n", filename);
        exit(1);
    }

    fgets(data, 80, fp);

    fclose(fp);
    
    char *data_p = data;
    for(int j = 0; 1; j++){
        if(*data_p == 'a'){
            printf("aは%d番目にあります。\n",j + 1);
        }else if(*data_p == '\0'){
            break;
        }
        data_p += 1;
    }
    
    return(0);
}