//WARNING: Educational demo only - NOT FOR USE IN REAL-WORLD AVIATION.
//PROVIDED "AS IS" with no warranty.

#include <iostream>
#include <map>
#include <string>

void checkInput() {
    std::cerr << "\nInvalid input.\n\n";
    std::cin.clear();
}

void ind() {
    using namespace std;
    cout << "               \n";
    cout << "     aircraft a\n";
    cout << "     aircraft b\n";
    cout << "     aircraft c\n";
    cout << "     aircraft d\n";
    cout << "     aircraft e\n";
    cout << "     aircraft f\n";
    cout << "     aircraft g\n";
    cout << "               \n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::map<std::string, double> gr = {         
        {"aircraft a", 15},
        {"aircraft b",  9},
        {"aircraft c", 17},
        {"aircraft d",  7},
        {"aircraft e", 10},
        {"aircraft f", 17},
        {"aircraft g", 15}
    };
        
    std::string search;
    std::string altitude;

    ind();
    std::cout << "Enter a aircraft from index and a altitude to get the estimated glide distance.\n";
    std::cout << "Enter i for index and x to exit.\n";
    while (true) {
        try {
            std::cout << "Enter a aircraft in index.\n";
            while(!getline(std::cin, search)) {
                checkInput();
            }
            if (search == "x") {
                break;
            } else if (search == "i") {
                ind();
                continue;
            }
            std::cout << "Enter a altitude.\n";
            while(!getline(std::cin, altitude)) {
                checkInput();
            }
            if (altitude == "i") {
                ind();
                continue;
            } else if (altitude == "x") {
                break;
            }
            double result = stod(altitude) * gr.at(search) / 5280;
            std::cout << "\nThe estimated glide distance is " << result << " miles.\n\n";
        } catch (std::out_of_range) {
            std::cout << "Enter a aircraft in index.\n\n";
        } catch (std::invalid_argument) {
            std::cout << "Enter a valid altitude.\n\n";
        }
    }

    return 0;
}

