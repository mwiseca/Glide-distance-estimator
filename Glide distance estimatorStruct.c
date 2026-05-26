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

struct Glide {
    char  *keys;
    double  values;
};



void keys(){
    printf("    aircraft a\n");
    printf("    aircraft b\n");
    printf("    aircraft c\n");
    printf("    aircraft d\n");
    printf("    aircraft e\n");
    printf("    aircraft f\n");
    printf("    aircraft g\n");
}

int main(){
    struct Glide g1[] = {
        {"aircraft a",  15},
        {"aircraft b",   9},
        {"aircraft c",  17}, 
        {"aircraft d",   7}, 
        {"aircraft e",  10},
        {"aircraft f",  17},
        {"aircraft g",  15}, 
    }; 
   
    char select[50];
    char altitude[25];
    long int alt;
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
        for(int i = 0; i <7 ;i++){
            if(strcmp(select, g1[i].keys)==0){
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
    double result = alt *  g1[number].values / 5280;
    printf("\nThe estimated glide distance is %lf miles.\n\n", result);
    memset(altitude, '\0', sizeof(altitude));    
    }
return 0;
}


