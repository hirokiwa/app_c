#include <stdio.h>

int kaijou(int n){

    if(n == 0){
        return(1);
    }else{
        return(n * kaijou(n - 1));
    }
    
}

int main(void){
    for (int i = 0; i <= 10; i++){
        printf("%d!\t=%d\n", i, kaijou(i));
    }

    return(0);
}