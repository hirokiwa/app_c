#include <stdio.h>

#define STACK_SIZE 100
int stack[STACK_SIZE];
int stack_num;

int push(int push_data){
    if(stack_num >= STACK_SIZE){
        return(0);
    }

    stack[stack_num] = push_data;
    stack_num++;

    return(1);
}

int pop(int *pop_data){
    if(stack_num == 0){
        return(0);
    }

    *pop_data = stack[stack_num - 1];
    
    stack_num--;
    return(1);
}

void stackPrint(){
    printf("STACK[");
    for(int i = 0; i < stack_num; i++){
        printf("%3d", stack[i]);
    }
    printf("]\n");
}

int main(void){
    int p_value;
    stack_num = 0;

    for(int i = 1; i <= 5; i++){
        push(i);
        printf("push\t%d：",i);
        stackPrint();
    }

    for(int i = 1; i <= 3; i++){
        pop(&p_value);
        printf("pop\t%d：", p_value);
        stackPrint();
    }

    for(int i = 6; i <= 9; i++){
        push(i);
        printf("push\t%d：", i);
        stackPrint();
    }

    while (stack_num > 0){
        pop(&p_value);
        printf("pop\t%d：", p_value);
        stackPrint();
    }

    return(0);
}