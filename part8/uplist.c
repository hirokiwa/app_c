#include <stdio.h>
#include <stdlib.h>

int main(void){
    typedef struct uplinklist{
        int value;
        struct uplinklist *next;
    }upNODE;

    upNODE *end = (upNODE*)malloc(sizeof(upNODE));
    end->value = -1;
    end->next = NULL;

    upNODE *top = (upNODE*)malloc(sizeof(upNODE));
    top->value = 0;
    top->next = end;

    upNODE *wp;

    while (1){
        int number;
        do{
        printf("数字を入力してください。終了する場合は-1\n");
        scanf("%d", &number);
        }while(!(number == -1 || number > 0));

        if(number == -1){
            break;
        }

        wp = (upNODE*)malloc(sizeof(upNODE));
        wp->value = number;

        upNODE *wr = NULL;

        for(upNODE *wq = top; wq != NULL; wq = wq->next){
            if(wq->value > number || wq->value == -1){
                wr->next = wp;
                wp->next = wq;
                break;
            }
            wr = wq;
        }
    }

    for(wp = top->next; wp->next; wp = wp->next){
        printf("[%3d]-->\n", wp->value);
    }

    printf("End\n");

    return(0);
}