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

// Status: To-Do

void saveCatalogue() {

	std::ofstream outputFile("CarCatalogue.txt");

	if (outputFile.is_open) {
		outputFile << "This is a test \n \n";
	}

}

//**********************************************************************************************************************

// For loading previously saved catalogue into a new instance of program

// Status: To-Do

void loadCatalogue() {

}

//**********************************************************************************************************************