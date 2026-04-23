//WARNING: Educational demo only - NOT FOR USE IN REAL-WORLD AVIATION.
//PROVIDED "AS IS" with no warranty.


#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <errno.h>
void flush(){
    int clear;
    while ((clear = getc(stdin)) != '\n' && clear != EOF) {
    }
}

void keys(){
    printf("    aircraft a\n");
    printf("    aircraft b\n");
    printf("    aircraft c\n");
    printf("    aircraft d\n");
    printf("    aircraft e\n");
    printf("    aircraft f\n");
    printf("    aircraft g\n");
    printf("    aircraft h\n");
}

int main(){
    char key [8] [50];
    sprintf(key[0], "aircraft a");
    sprintf(key[1], "aircraft b");
    sprintf(key[2], "aircraft c");
    sprintf(key[3], "aircraft d");
    sprintf(key[4], "aircraft e");
    sprintf(key[5], "aircraft f");
    sprintf(key[6], "aircraft g");
    sprintf(key[7], "aircraft h");

    double value [8];
    value[0] = 15;
    value[1] =  9;
    value[2] = 17;
    value[3] =  7;
    value[4] = 16;
    value[5] = 10;
    value[6] = 17;
    value[7] = 15;


    char select[50];
    char altitude[25];
    long int alt;
    double gr;
    char *ptr;

    printf("Enter a aircraft from index and a altitude to get the estimated glide distance.\n");
    printf("Enter i for index and x to exit.\n");
    while(1){
        printf("Enter a aircraft.\n");
        while(fgets(select,sizeof(select),stdin) == NULL) {
            clearerr(stdin);
            printf("\nInvalid input\n\n");
        }
        select[strcspn(select,"\n")]=0;
        if(strlen(select) >= 49) {
            flush();
        }
        if(strcmp(select,"i")==0) {
            keys();
        }else if(strcmp(select,"x")==0) {
            break;
        }
        int number = -1;
        for(int i = 0; i < 8;i++){
            if(strcmp(select, key[i])==0){
                number = i;
            }
        }
        if(number == -1){
            printf("\nEnter a aircraft in index.\n\n");
            continue;
        }
        printf("Enter a altitude.\n");
        while(1) {
        if(fgets(altitude,sizeof(altitude),stdin) == NULL) {
            clearerr(stdin);
            printf("\nInvalid input.\n\n");
            continue;
            } 
            altitude[strcspn(altitude,"\n")]=0;
            if(strlen(altitude) >= 24) {
                flush();
            }
            
            if(strcmp(altitude,"i")==0) {
                keys();
                printf("\nEnter a altitude.\n\n");
                continue;
            }else if(strcmp(altitude,"x")==0) {
                exit(EXIT_SUCCESS);
            }
             errno = 0;
            alt = strtol(altitude,&ptr,10);
            if(errno == ERANGE) {
                printf("\nYou entered to many numbers.\n\n");
            } else if(*ptr == 0x20) {
                printf("\nTry not to enter spaces between numbers.\n\n");
            } else if(ptr == altitude) {
                printf("\nEnter a number only.\n\n");
            } else if(*ptr != '\0') {
                printf("\nTry not to enter text after a number.\n\n");                   
            }else{
                break;     
        }
    }
    double result = alt *  value[number] / 5280;
    printf("\nThe estimated glide distance is %lf miles.\n\n", result);
    memset(altitude, '\0', sizeof(altitude));    
    }
return 0;
}


