#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    FILE *fp;

    char *argv_p = argv[1];

    fp = fopen(argv_p, "w");

    fprintf(fp, "クレヨンしんちゃん");

    fclose(fp);
    
    return(0);
}