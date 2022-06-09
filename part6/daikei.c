// 20,15,13,277.5
// 25,14,17,311.5

#include <stdio.h>

void set(int *data){
    printf("下辺＝");
    scanf("%d", data);
    printf("上辺＝");
    scanf("%d", data+1);
    printf("高さ＝");
    scanf("%d", data+2);
}

int main(void){
    typedef struct daikei{
        int kahen;
        int jouhen;
        int takasa;
    } data;
    
    data da, db, dc;

    puts("台形Aの値を入力せよ");
    set(&da);
    puts("台形Bの値を入力せよ");
    set(&db);

    printf("台形Aの面積は%.2fです。\n",(double)((double)(da.jouhen + da.kahen) / 2 * da.takasa));
    printf("台形Bの面積は%.2fです。\n",(double)((double)(db.jouhen + db.kahen) / 2 * db.takasa));

    dc.jouhen = da.jouhen + db.jouhen;
    dc.kahen = da.kahen + db.kahen;
    dc.takasa = da.takasa + db.takasa;

    printf("台形Cの面積は%.2fです。\n",(double)((double)(dc.jouhen + dc.kahen / 2) * dc.takasa));

    return(0);
}