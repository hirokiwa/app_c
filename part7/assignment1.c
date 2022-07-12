#include <stdio.h>
#include <string.h>

#define STACK_SIZE 10
char stack[STACK_SIZE];
char *top = NULL;

int push(char *data){

    if(top == &stack[STACK_SIZE - 1]){
        puts("OVERFLOW!!");
        return(1);
    }else{
        if(top == NULL){
            top = stack;
        }else{
            top++;
        }

        *top = *data;
    }

    return(0);
}

int pop(void){
    if(top == NULL){
        puts("UNDERFLOW!!");
        return(1);
    }else{
        top--;
    }

    return(0);
}

void stackPrint(void){
    printf("STACK[");

    char *point = top;

    for( ; point + 1 != stack; point--){
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
                return(0);
            }

            re_enter = 0;
            for(int i = 0; command[i] != '\n'; i++){
                if(!(command[i] == 'P' || command[i] == 'O')){
                    re_enter == 1;
                    break;
                }
            }

        }while(re_enter == 1);

        point_data = data;
        point_command = command;

        while(*point_command != '\n'){
            switch (*point_command){
                case 'P':
                    push(point_data);
                    point_data++;
                    break;
                case 'O':
                    pop();
                    break;
                default:
                    break;
            }
            point_command++;
        }

        stackPrint();

    } while(1);

    return(0);
}