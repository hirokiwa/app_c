#include <stdio.h>

int main(void){
    typedef struct person{
        char name[20];
        char seibetsu;
        int age;
        float height;
        float weight;
        struct person *next;
    } MYDATA;

    MYDATA natsuko = {"Yamada Natsuko", 'f', 25, 155.3, 48.5};
    MYDATA akiko = {"Suzuki Akiko", 'f', 18, 152.8, 46.0};
    MYDATA ichiro = {"Fujita Ichiro", 'm', 28, 160.5, 50.2};

    natsuko.next = &akiko;
    akiko.next = &ichiro;
    ichiro.next = NULL;

    for(MYDATA *poin = &natsuko; poin; poin = poin->next){
        printf("%s\t[性別=%c,年齢=%d歳,身長=%5.1fセンチ, 体重=%5.1fキロ]\n",poin->name,poin->seibetsu, poin->age, poin->height, poin->weight);
    }

    return(0);
}