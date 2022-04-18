#include <stdio.h>

int main(void){

    typedef enum koyomi{
        January = 1,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December
    } Calender;

    enum four_seasons{
        Spring,
        Summer,
        Autumn,
        Winter
    } season;

    int keyin, month;

    do{
        printf("\n月を1から12の数字で入れてください-->");
        scanf("%d",&keyin);
        month = (Calender)keyin;
        if((month < January) || (month > December)){
            printf("\nそんな月はありません。\n");
        }
    } while (!((month >= January) && (month <= December)));

    switch (month){
        case March:
        case April:
        case May:
            season = Spring;
            break;
        case June:
        case July:
        case August:
            season = Summer;
            break;
        case September:
        case October:
        case November:
            season = Autumn;
            break;
        case December:
        case January:
        case February:
            season = Winter;
            break;
        default:
            ("\nそんな月はありません。\n");
    }

    switch (season)
    {
    case Spring: printf("その季節は春です。\n\n"); break;
    case Summer: printf("その季節は夏です。\n\n"); break;
    case Autumn: printf("その季節は秋です。\n\n"); break;
    case Winter: printf("その季節は冬です。\n\n"); break;
    }

    return(0);
}