#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
void ind(){
   
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


int main(){
   std::map<std::string,double> gr = {
       {"aircraft a",      15},
       {"aircraft b",       9},
       {"aircraft c",      17},
       {"aircraft d",       7},
       {"aircraft e",      16},
       {"aircraft f",      10},
       {"aircraft g",      17},
       {"aircraft h",      15} 
};  

       char search [2000];
       char altitude [2000]; 


 printf("Enter a aircraft from index and a altitude to get the estimated glide distance.\n");
 printf("Enter i for index and x to exit.\n");
while(1){
        
	  printf("Enter a aircraft in index.\n");
	  while(fgets(search,2000,stdin)){
	  search[strcspn(search,"\n")]=0;
	  auto c = gr.find(search);
	  if(strcmp(search,"x")==0){
	  exit(EXIT_SUCCESS);}
	  else if(strcmp(search,"i")==0){
	  ind();
	  printf("Enter a aircraft in index.\n");
	  continue;}
	  else if(c == gr.end()){
          std::cout << "Enter a aircraft in index only.\n\n";
          continue;}
	  else{
		 break;} 
          }          	  
	    printf("Enter a altitude.\n");
	    while(fgets(altitude,2000,stdin)){
            altitude[strcspn(altitude,"\n")]=0;
            if(strcmp(altitude,"i")==0){
            ind();
	    printf("Enter a altitude.\n");
            continue;}
            else if(strcmp(altitude,"x")==0){
            exit(EXIT_SUCCESS);}
            double result = atof(altitude) *   gr.at(search) / 5280;
            if(atof(altitude) * gr.at(search) / 5280 == 0){
                printf("\nEnter a valid altitude only.\n\n");
               continue;}
	    else{
		 break;}
	    }
            double result = atof(altitude) *   gr.at(search) / 5280; 
            printf("\nThe estimated glide distance is %lf miles.\n\n",result);
       	
}
return 0;
}
