#include <stdio.h>
#define NUMBER 4

int main(void){
    typedef struct club{
        int bangou;
        char namae[20];
        char seibetsu;
        int nenrei;
        float shinchou;
        float taijuu;
    } GYM;

    GYM fitness[]={
        {1401, "Yamada", 'm', 40, 170.2, 67.9},
        {1402, "Suzuki", 'f', 22, 152.4, 47.9},
        {1403, "Nakano", 'f', 30, 160.5, 50.2},
        {1404, "Morita", 'm', 52, 168.3, 72.4}
    };

    GYM *p = fitness;
    
    float sum = 0;

    // average age
    for(int i = 0; i < NUMBER; i++){
        sum += p->nenrei;
        p++;
    }
    printf("平均年齢：%.1f\n\n",sum/NUMBER);

    // average height
    sum = 0;
    p = fitness;
    for(int i = 0; i < NUMBER; i++){
        sum += p->shinchou;
        p++;
    }
    printf("平均身長：%.2f\n\n",sum/NUMBER);

    // average weight
    sum = 0;
    p = fitness;
    for(int i = 0; i < NUMBER; i++){
        sum += p->taijuu;
        p++;
    }
    printf("平均体重：%.2f\n\n",sum/NUMBER);

    // maximum weight
    p = fitness + 1;
    GYM *value = fitness;
    for(int i = 0; i < NUMBER - 1; i++){
        if(value->taijuu < p->taijuu){
            value = p;
        }
        p++;
    }
    printf("体重の最大値：%.1f\n", value->taijuu);
    printf("会員番号：%d\n\n", value->bangou);

    // minimum height
    p = fitness + 1;
    value = fitness;
    for(int i = 0; i < NUMBER - 1; i++){
        if(value->shinchou > p->shinchou){
            value = p;
        }
        p++;
    }
    printf("身長の最小値%.1f\n", value->shinchou);
    printf("会員番号：%d\n\n", value->bangou);

    return(0);
}