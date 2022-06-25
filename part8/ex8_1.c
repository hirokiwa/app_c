#include <stdio.h>
#include <stdlib.h>

int main(void){
    typedef struct node{
        int data;
        struct node *next;
    } NODE;

    int x;
    NODE *p;
    NODE *head = NULL;

    while (1){
        printf("data=");
        scanf("%d", &x);
        if(x == -1){
            break;
        }

        p = (NODE*)malloc(sizeof(NODE));
        p->next = head;
        p->data = x;
        head = p;
    }
    
    p = head;
    while (p){
        printf("%d-->", p->data);
        p = p->next;
    }

    printf("End\n");

    return(0);
}