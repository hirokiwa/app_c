// じゃんけんをした後に「続けますか？」というメッセージを表示
// 続ける場合は１、やめる場合は１以外の数を入力
// 累積の勝敗（入力側　〇勝〇敗〇分け）

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum janken{
    Gu = 0,
    Choki = 2,
    Pa = 5
} JPON;

int sysjan(void){
    int sai, pon;

    srand((unsigned)time(NULL));
    sai = rand() % 3;

    switch(sai){
        case 0:
            pon = 0;
            printf("私はグーを出しました。\n");
            break;
        case 1:
            pon = 2;
            printf("私はチョキを出しました。\n");
            break;
        case 2:
            pon = 5;
            printf("私はパーを出しました。\n");
            break;
    }
    return((JPON)pon);
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
            if(kenout == Gu) shoubukekka = 2;
            else if(kenout == Choki) shoubukekka = 0;
            else shoubukekka = 1;
            break;
        case Choki:
            if(kenout == Gu) shoubukekka = 1;
            else if(kenout == Choki) shoubukekka = 2;
            else shoubukekka = 0;
            break;
        case Pa:
            if(kenout == Gu) shoubukekka = 0;
            else if(kenout == Choki) shoubukekka = 1;
            else shoubukekka = 2;
            break;
    }

    if(shoubukekka == 0) printf("\nあなたの勝ちです。\n");
    else if(shoubukekka == 1) printf("\nあなた負けです。\n");
    else if(shoubukekka == 2) printf("\nあいこです。\n");
    else printf("\n引数のエラーです。\n");

    return(shoubukekka);
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

        printf("\a");
        anatanoken(choken);

        sysken = sysjan();
        shoubukekka = shoubu(choken, sysken);

        score[shoubukekka] += 1;
        printf("入力側 %d勝%d敗%d分け\n", score[0], score[1], score[2]);

        printf("\n続けますか？\n");
        printf("続ける：１/終わる：０\n");
        scanf("%d", &cont);
    } while(cont == 1);

    printf("\n終わります。おつかれさまでした。\n\n");

    return(0);
}
