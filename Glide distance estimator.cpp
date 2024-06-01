#include <iostream>
#include <string>
#include <map>
void ind(){
using namespace std;
 cout << "               \n";
 cout << "     aircraft a\n";
 cout << "     aircraft b\n";
 cout << "     aircraft c\n";
 cout << "     aircraft d\n";
 cout << "     aircraft e\n";
 cout << "     aircraft f\n";
 cout << "     aircraft g\n";
 cout << "                \n";
}


int main(){
   std::map<std::string,double> gr = {
       {"aircraft a",      15},
       {"aircraft b",       9},
       {"aircraft c",      17},
       {"aircraft d",       7},
       {"aircraft e",      10},
       {"aircraft f",      17},
       {"aircraft g",      15}
};
       std::string search;
       std::string altitude; 

while(true){
         try{ 
	  std::cout << "Enter a aircraft name, i for index x to exit.\n";
	  getline(std::cin,search);
	  if(search == "x"){
	  break;}
	  else if(search == "i"){
	  ind();
	  continue;}
	  std::cout << "Enter a altitude, i for index x to exit.\n";
	  getline(std::cin,altitude);
	  if(altitude == "i"){
	  ind();
	  continue;}
	  else if(altitude == "x"){
	  break;}
	  double result = stod(altitude) *   gr.at(search) / 5280;
          std::cout << "The estimated glide distance is " << result << " miles.\n\n";
	}catch(std::out_of_range){
	 std::cout << "Enter a aircraft in index.\n\n";
	}catch(std::invalid_argument){
	 std::cout << "Enter a valid altitude.\n\n";
	}
}

return 0;
}
