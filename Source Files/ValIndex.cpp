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

bool getYN(const std::string& prompt = "Enter (Y/N): ") {
    std::string input;

    while(true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        if (input.length() == 1 ) {
            char c = std::tolower(input[0]);

            if (c == 'y'){
                return true;
            }
            if (c == 'n'){
                return false;
            }
        }

        std::cout << "Invalid input. Please type 'y' or 'n'. \n";
    }
}

//**********************************************************************************************************************

bool isValidVin(const std::string& vin) {
    
    if (vin.length() != 17){
        return false;
    }

    for (char c : vin) {
        
        if (!std::isalnum(c)){
            return false;
        }

        char upper = std::toupper(c);
        if (upper == 'I' || upper == 'O' || upper == 'Q'){
            return false;
        }
    
    }

    return true;
}

//**********************************************************************************************************************

std::string getVIN(const std::string& prompt = "Enter VIN: "){
    std::string vin;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, vin);

        // trim whitespace
        vin.erase(0, vin.find_first_not_of(" \t\n\r"));
        vin.erase(vin.find_last_not_of(" \t\n\r") + 1);

        // uppercase everything
        for (char &c : vin){
            c = std::toupper(c);
        }

        if (isValidVin(vin)){
            return vin;
        }

        std::cout << "Invalid VIN. It must be 17 characters, alphanumeric, and cannot contain I, O, or Q. \n";
    }
}

//**********************************************************************************************************************
