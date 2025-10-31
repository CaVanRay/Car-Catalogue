#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>
#include "CatFunc.h"
#include "Cars.h"
#include "savld.h"

//**********************************************************************************************************************
 
int main() {

	// This is where program checks for existing catalogue file to load
	// changes to catalogue would be saved to file as they are made in case of unexpected shutdown
	// If no file is found, program creates new catalogue
    
    /*
	File Load Status: NOT STARTED

	Main Status: WORKING
    */


    std::string Cont = "YES";
    car* head = nullptr;
    std::vector<car*> carCatalogue;

    loadCatalogue();

	// printCatalogue(head); // to show loaded catalogue before any changes are made

    addCar(head, carCatalogue);

    saveCatalogue();

    std::cout << std::endl << "Now please feel free to peruse the catalogue: " << std::endl;

    do {
        printCatalogue(head);
        optionsMenu(head, carCatalogue);
        std::cout << std::endl << "Would you like to choose another option? (Yes/No): ";
        std::getline(std::cin, Cont);
        std::transform(Cont.begin(), Cont.end(), Cont.begin(),
            [](unsigned char c) { return std::toupper(c); });
    } while (Cont == "YES");

    return 0;
}
//**********************************************************************************************************************