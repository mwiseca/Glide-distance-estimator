//WARNING: Educational demo only - NOT FOR USE IN REAL-WORLD AVIATION.
//PROVIDED "AS IS" with no warranty.


#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <stdio.h>
#include <string.h>
#include <string>
#define SIZE 25
#define MAX 24

void clean(){
    int clear;     
    while ((clear = getc(stdin)) != '\n' && clear != EOF) {     
    } 
}

void ind() {

    printf("               \n");
    printf("     aircraft a\n");
    printf("     aircraft b\n");
    printf("     aircraft c\n");
    printf("     aircraft d\n");
    printf("     aircraft e\n");
    printf("     aircraft f\n");
    printf("     aircraft g\n");
    printf("     aircraft h\n");
}

int main() {
    std::unordered_map<std::string, double> gr = {    
        {"aircraft a", 15},                                       
        {"aircraft b",  9},
        {"aircraft c", 17},
        {"aircraft d",  7},
        {"aircraft e", 16},
        {"aircraft f", 10},
        {"aircraft g", 17},
        {"aircraft h", 15}
    };
            
    char search[SIZE];
    char altitude[SIZE];
    double result;
    double x;
    char *ptr;
    

    printf("Enter a aircraft from index and a altitude to get the estimated glide distance.\n");
    printf("Enter i for index and x to exit.\n");
    while (1) {

        printf("Enter a aircraft in index.\n");
        while(1) {
            if (fgets(search, SIZE, stdin) == NULL) {
                printf("\nInvalid input.\n\n"); 
                clearerr(stdin);
                continue;
            }        
            search[strcspn(search, "\n")] = 0;
            if(strlen(search) >= MAX) {
                clean();
            } 
            auto c = gr.find(search);
            if (strcmp(search, "x") == 0) {
                exit(EXIT_SUCCESS);
            } else if (strcmp(search, "i") == 0) {
                ind();
                printf("Enter a aircraft in index.\n");
                continue;
            } else if (c == gr.end()) {
                printf("\nEnter a aircraft in index only.\n\n");
                continue;
            } else {
                break;
            }
        }
        printf("Enter a altitude.\n");
        while(1) {
            if (fgets(altitude, SIZE, stdin) == NULL) {
                printf("\nInvalid input.\n\n");
                clearerr(stdin);
                continue;
            }    
            altitude[strcspn(altitude, "\n")] = 0;
            if (strlen(altitude) >= MAX) {
                clean();
            }
            if (strcmp(altitude, "i") == 0) {
                ind();
                printf("Enter a altitude.\n");
                continue;
            } else if (strcmp(altitude, "x") == 0) {
                exit(EXIT_SUCCESS);
            }
            x = strtod(altitude, &ptr);
            if(x >= 100001 ||x <= -100001) {
                printf("\nEnter a altitude -100000 to 100000.\n\n");
            } else if(*ptr == 0x20) {
                printf("\nTry not to enter spaces between numbers.\n\n");
            } else if(ptr == altitude) {
                printf("\nEnter a number only.\n\n");
            } else if(*ptr != '\0') {
                printf("\nTry not to enter text after a number.\n\n");
            } else {
                break;
            }
        }
        result = x * gr.at(search) / 5280;
        printf("\nThe estimated glide distance is %lf miles.\n\n", result);
    }
    return 0;
}


















