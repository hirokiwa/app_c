#include <stdio.h>

int main(void){
    char he;
    scanf("%s",&he);

    if(he="へ"){
        puts("ひらがな");
    }else if(he="ヘ"){
        puts("カタカナ");
    }
    return(0);
}