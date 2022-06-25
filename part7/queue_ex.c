#include <stdio.h>

#define QUEUE_SIZE 100
int queue[QUEUE_SIZE];
int post;

int enqueue(int enq_data){
    if(post >= QUEUE_SIZE){
        return(0);
    }

    queue[post] = enq_data;
    post++;

    return(1);
}

int dequeue(int *deq_data){
    if(post <= 0){
        return(0);
    }

    *deq_data = queue[0];

    if(post > 1){
        for(int i = 0; i < post - 1; i++){
            queue[i] = queue[i + 1];
        }
    }

    post--;
    return(1);
}

void queuePrint(){
    printf("QUEUE[");
    for(int i = 0; i < post; i++){
        printf("%3d",queue[i]);
    }
    printf("]\n");
}

int main(void){
    int d_value;
    post = 0;

    for(int i = 1; i <= 7; i++){
        printf("Enqueue%3d：\t",i);
        enqueue(i);
        queuePrint();
    }

    for(int i = 1; i <= 4; i++){
        dequeue(&d_value);
        printf("Dequeue%3d：\t",d_value);
        queuePrint();
    }

    for(int i = 8; i <= 15; i++){
        printf("Enqueue%3d：\t",i);
        enqueue(i);
        queuePrint();
    }

    while (post > 0){
        dequeue(&d_value);
        printf("Dequeue%3d：\t",d_value);
        queuePrint();
    }
    
    return(0);
}