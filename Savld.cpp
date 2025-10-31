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

// For saving your current catalogue to be used next time the program is run

// Status: In progress

// Needs the Catalogue vector and the header pointer pass from main

void saveCatalogue(car*& head, std::vector<car*>& carCatalogue) {

	std::ofstream outputFile("CarCatalogue.txt");

	if (outputFile.is_open()) {
		outputFile << "This is a test \n \n";
	}
	else {
		std::cerr << "Error: Unable to open file 'CarCatalogue.txt' \n";
	}

}

//**********************************************************************************************************************

// For loading previously saved catalogue into a new instance of program

// Status: in progress

// Needs the Catalogue vector and the header pointer pass from main

void loadCatalogue(car*& head, std::vector<car*>& carCatalogue) {

	std::ifstream inputFile("CarCatalogue.txt");

	if (!inputFile.is_open()) {
		std::cerr << "Error: Could not open file." << std::endl;
	}
	std::string line;
	while (std::getline(inputFile, line)) {

		std::cout << line << std::endl;

	}
	inputFile.close();
}

//**********************************************************************************************************************