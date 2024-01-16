#include <stdio.h>
#include <string.h>

void ind(){  
	     printf("\n");
	     printf("     aircraft a\n"); 
	     printf("     aircraft b\n");       
	     printf("     aircraft c\n");       
	     printf("     aircraft d\n");       
	     printf("     aircraft e\n");
	     printf("     aircraft f\n");
	     printf("     aircraft g\n");
	     printf("     aircraft h\n\n");
             }	


int main(){

       	char ac [8]  [15] = {"aircraft a","aircraft b","aircraft c","aircraft d","aircraft e","aircraft f","aircraft g","aircraft h"}; 
	int gr [] = { 15, 9, 17, 7,16,10, 17,15};

    char aircraft [15];
    double glide_ratio;
    double alt;

 while(1){
printf("Enter a aircraft, x to exit or i for index.\n");
	fgets(aircraft,15,stdin);
	aircraft[strcspn(aircraft, "\n")] = 0;
	fflush(stdin);
	if(strcmp(aircraft,"i")==0){
	ind();
	continue;}
	else if(strcmp(aircraft,"x")==0){
	break;}
	printf("Enter a altitude to get a estamated straight line glide distance.\n");
	if(scanf("%lf", &alt)!=1){
        fflush(stdin); 
  printf("Enter a valid altitude.\n");
        printf("Start over.\n\n");
        continue;}
        fflush(stdin);		
 if(strcmp(aircraft,ac[0])==0){
 glide_ratio = gr[0];
}else if(strcmp(aircraft,ac[1])==0){
 glide_ratio = gr[1];
}else if(strcmp(aircraft,ac[2])==0){
 glide_ratio = gr[2];
}else if(strcmp(aircraft,ac[3])==0){
 glide_ratio = gr[3];
}else if(strcmp(aircraft,ac[4])==0){
 glide_ratio = gr[4];
}else if(strcmp(aircraft,ac[5])==0){
 glide_ratio = gr[5];
}else if(strcmp(aircraft,ac[6])==0){
 glide_ratio = gr[6];
}else if(strcmp(aircraft,ac[7])==0){
 glide_ratio = gr[7];}
 else{
     printf("Enter a aircraft from index only.\n");
     printf("\n");
     continue;}
	printf("The glide distance is %f",alt * glide_ratio  / 5280);
	printf(" miles.\n");
     }
return 0;
}
	
