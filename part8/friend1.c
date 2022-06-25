#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    struct tomodachi{
        char name[30];
        int age;
        struct tomodachi *chain;
    };

    struct tomodachi dummy;
    struct tomodachi *top;
    struct tomodachi *wx;
    struct tomodachi *wp;
    
    char sei[30];
    int toshi;

    //setting dummy data
    top = &dummy;
    strcpy(top->name, "dumdum");
    top->age = -999;
    top->chain = NULL;
    wp = top;

    while(1){
        printf("名前(姓のみ)をローマ字で入れよ。終了はqを入れよ。\n");
        scanf("%s", sei);
        if(sei[0] == 'q'){
            break;
        }

        do{
            printf("年齢(0歳以上)を入れよ\n");
            scanf("%d", &toshi);
            
        }while(toshi < 0);

        wx = (struct tomodachi*)malloc(sizeof(struct tomodachi));
        strcpy(wx->name, sei);
        wx->age = toshi;
        wx->chain = NULL;
        wp->chain = wx;
        wp = wx;
    }

    for(wp = top->chain; wp != NULL; wp = wp->chain){
        printf("[名前：%s\t年齢：%d]-->\n", wp->name, wp->age);
    }

    printf("End\n");

    return(0);    
}