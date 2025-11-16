#include "CarCatHeaders.h"

//**********************************************************************************************************************

/*
ValIndex functions: Validates the catalogue index as well as any inputs

STATUS: Designing
*/

//**********************************************************************************************************************

// The entire catalogue will need to be passed to indexUpdate()
// The size of the existing catalogue taken
// and then it will re-iterate through the linked list of items to re-set each index?

void indexUpdate(car*& head, std::vector<car*>& carCatalogue){
    
car* n = head;
int count = 1; 

// This section updates the index by linked list inside each item
while(n != nullptr){
    n -> SetIndex(count);
    count++;
    n = n->GetNext();
 }

// This section updates the vector list to match the updated linked list
carCatalogue.clear();
car* n = head;
while (n != nullptr){
    carCatalogue.push_back(n);
    n = n->GetNext();
}
    
}

//**********************************************************************************************************************

int getInt(const std::string& prompt){

    // value to grab
    int intValue;

    // will continuously loop until break
    while(true) {
        std::cout << prompt;

        // Try reading an int
        if (std::cin >> intValue) {
            // on success, return value, breaking the loop
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return intValue;
        }

        // if it reaches here that means input failed
        std::cout << "Invalid number. Please try again. \n";

        // Clear input
        std::cin.clear();

        // Throw away invalid characters
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

//**********************************************************************************************************************

double getDouble(const std::string& prompt){

    // value to grab
    double dValue;

    // will continouosly loop until break
    while(true) {
        std::cout << prompt;

        //Try reading a double
        if(std::cin >> dValue) {
            // on success, return value, breaking the loop
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return dValue;
        }

        // if it reaches here that means input failed
        std::cout << "Invalid number. Please try again. \n";

        // Clear input
        std::cin.clear();

        // Throw away invalid characters
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

//**********************************************************************************************************************

bool getYN(const std::string& prompt){


    
}

//**********************************************************************************************************************

string getVIN(const std::string& prompt){


    
}

//**********************************************************************************************************************
