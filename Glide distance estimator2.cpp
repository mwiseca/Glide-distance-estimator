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

    std::cout << "Enter a aircraft from index and a altitude to get the estimated glide distance.\n";
    std::cout << "Enter i for index and x to exit.\n";
    while (true) {
        std::cout << "Enter a aircraft in index.\n";
        while(true) {
            if (!getline(std::cin, search)) {
                checkInput();
                continue;
            }
            auto i = gr.find(search);
            if (search == "x") {
                exit(EXIT_SUCCESS);
            } else if (search == "i") {
                ind();
                std::cout << "Enter a aircraft in index.\n";
                continue;
            } else if (i == gr.end()) {
                std::cout << "\nEnter a aircraft in index only.\n\n";
                continue;
            } else {
                break;
            }
        }
        std::cout << "Enter a altitude.\n";
        while(true) {
            if (!getline(std::cin, altitude)) {
                checkInput();
                continue;
            }
            try {
                if (altitude == "i") {
                    ind();
                    std::cout << "Enter a altitude.\n";
                    continue;
                } else if (altitude == "x") {
                    exit(EXIT_SUCCESS);
                }
                double result = stod(altitude) * gr.at(search) / 5280;
                std::cout << "\nThe estimated glide distance is " << result << " miles.\n\n";
                break;
            } catch (std::invalid_argument) {
                std::cout << "\nEnter a valid altitude.\n\n";
            }
        }
    }

    return 0;
}

