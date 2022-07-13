#include <stdio.h>
#include <string.h>

#define QUEUE_SIZE 10

char queue[100];
char *top = NULL;
char *tail = NULL;

int enqueu(char *data){

    if(tail == top + QUEUE_SIZE - 1){
        puts("OVERFLOW!!");
        return(1);
    }else{
        if(top == NULL && tail == NULL){
            top = queue;
            tail = queue;
        }else{
            tail++;
        }

        *tail = *data;
    }

    return(0);
}

int dequeue(void){

    if(top == tail){
        if(top == NULL){
            puts("UNDERFLOW!!");
            return(1);
        }else{
            top = NULL;
            tail = NULL;
        }
    }else{
        top++;
    }

    return(0);
}

void queuePrint(void){
    printf("QUEUE[");

    char *point = top;

    for(; point != tail + 1 && top != NULL; point++){
        printf(" %c", *point);
    }

    printf(" ]\n");
}

int main(void){
    // command
    char command[30];
    char *point_command;
    char data[] = "ABCDEFGHIJKLMN";
    char *point_data;

    do{

        int re_enter = 0;
        do{
            printf("コマンドを入力してください。\n");
            fgets(command, 30, stdin);

            if(command[0] == 'Q' && command[1] == '\n'){
                puts("終了します。");
                return(0);
            }

            re_enter = 0;
            for(int i = 0; command[i] != '\n'; i++){
                if(!(command[i] == 'E' || command[i] == 'D')){
                    re_enter == 1;
                    break;
                }
            }

        }while(re_enter == 1);

        point_data = data;
        point_command = command;

        while(*point_command != '\n'){
            switch (*point_command){
                case 'E':
                    if(enqueu(point_data) == 0){
                        point_data++;
                    }
                    break;
                case 'D':
                    dequeue();
                    break;
                default:
                    break;
            }
            point_command++;
        }

        queuePrint();

        top = NULL;
        tail = NULL;

    } while(1);

    return(0);
}