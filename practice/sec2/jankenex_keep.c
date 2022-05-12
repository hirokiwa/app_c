#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum janken{
    Gu = 0,
    Choki = 2,
    Pa = 5
} JPON;

int saikoro(void){
    int sai, n;
    srand((unsigned)time(NULL));
    n = rand();
    sai = n % 5 + 1;
    return(sai);
}

int sysjan(int sainome){
    int pon;
    switch(sainome){
        case 1:
        case 2:
            pon = 0;
            break;
        case 3:
        case 4:
            pon = 2;
            break;
        case 5:
        case 6:
            pon = 5;
            break;
    }
    return((JPON)pon);
}

void watashinoken(JPON ken){
    switch(ken){
        case Gu:
            printf("私はグーを出しました。\n");
            break;
        case Choki:
            printf("私はチョキを出しました。\n");
            break;
        case Pa:
            printf("私はパーを出しました。\n");
            break;
    }
}

void anatanoken(JPON ken){
    switch(ken){
        case Gu:
            printf("あなたはグーを出しました。\n");
            break;
        case Choki:
            printf("あなたはチョキを出しました。\n");
            break;
        case Pa:
            printf("あなたはパーを出しました。\n");
            break;
    }
}

int shoubu(JPON kenin, JPON kenout){
    int shoubukekka;
    switch(kenin){
        case Gu:
            if(kenout == Gu) shoubukekka = 0;
            else if(kenout == Choki) shoubukekka = 1;
            else shoubukekka = -1;
            break;
        case Choki:
            if(kenout == Gu) shoubukekka = -1;
            else if(kenout == Choki) shoubukekka = 0;
            else shoubukekka = 1;
            break;
        case Pa:
            if(kenout == Gu) shoubukekka = 1;
            else if(kenout == Choki) shoubukekka = -1;
            else shoubukekka = 0;
            break;
    }
    return(shoubukekka);
}

void kekka(int shoubukekka){
    if(shoubukekka == -1) printf("\nあなたの負けです。\n");
    else if(shoubukekka == 1) printf("\nあなた勝ちです。\n");
    else if(shoubukekka == 0) printf("\nあいこです。\n");
    else printf("\n引数のエラーです。\n");
}

int main(void){

    JPON choken;
    JPON sysken;
    int ken_buf;
    int sai;
    int shoubukekka;
    int cont;
    int score[3] = {0};

    do{
        do{
            printf("\nじゃんけんをしましょう。\n");
            printf("\nグーは0 チョキは2 パーは5 を入れます。\n");
            printf("\nじゃんけぽん！はいどうぞ：\a");
            scanf("%d", &ken_buf);
            choken = (JPON)ken_buf;
            if((choken != Gu) && (choken != Choki) && (choken != Pa)){
                printf("\n＠＠＠＠正しく入れてください！＠＠＠＠\n");
            }
        } while(!(choken == Gu || choken == Choki || choken == Pa));

        sai = saikoro();
        sysken = sysjan(sai);

        shoubukekka = shoubu(choken, sysken);

        printf("\a");
        anatanoken(choken);
        watashinoken(sysken);
        kekka(shoubukekka);

        score[shoubukekka + 1] += 1;
        printf("入力側 %d勝%d敗%d分け\n", score[2], score[0], score[1]);

        printf("\n続けますか？\n");
        printf("続ける：１/終わる：０\n");
        scanf("%d", &cont);
    } while(cont == 1);

    printf("\n終わります。おつかれさまでした。\n\n");

    return(0);
}