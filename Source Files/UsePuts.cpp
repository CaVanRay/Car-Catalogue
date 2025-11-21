#include "CarCatHeaders.h"

//**********************************************************************************************************************

/*
optionsMenu function: Displays a menu of options to the user and prompts them to select an action.

STATUS: TESTING
*/

void optionsMenu(car*& head, std::vector<car*>& carCatalogue) {

    bool runP = true;

    do {
        std::cout << std::endl << "***************************************" << std::endl;
        std::cout << "1) Print Catalogue" << std::endl;
        std::cout << "2) Print Specific Car" << std::endl;
        std::cout << "3) Add a Car" << std::endl;
        std::cout << "4) Edit a Car" << std::endl;
        std::cout << "5) Remove a Car" << std::endl;
        std::cout << "6) Save Catalogue" << std::endl;
        std::cout << "7) Exit Program" << std::endl;
        std::cout << "***************************************" << std::endl;
        int selectedAction = getInt("Enter option: ");
        while (selectedAction < 1 || selectedAction > 7) {
            selectedAction = getInt("Invalid option. Try again: ");
        }
        switch (selectedAction) {
        case 1: {
            system("CLS");
            printCatalogue(head);
            break;
		}
        case 2: {
            system("CLS");
            car* n = findCar(head);
            printCar(n);
            break;
        }
        case 3: {
            system("CLS");
            addCar(head, carCatalogue);
            printCatalogue(head);
            break;
        }
        case 4: {
            system("CLS");
            car* n = findCar(head);
            editCar(n);
            printCar(n);
            break;
        }
        case 5: {
            system("CLS");
            car* n = findCar(head);
            deleteCar(head, carCatalogue, n);
            printCatalogue(head);
            break;
        }
        case 6: {
            system("CLS");
            saveCatalogue(head);
            break;
        }
        case 7: {
            system("CLS");
			runP = false;
            break;
        }
        default: {
            std::cout << std::endl << "Error: you have not selected a valid option" << std::endl;
            break;
        }

        }
	} while (runP);
}


//**********************************************************************************************************************

/*
printCatalogue function: Takes a pointer to the head of the linked list of car objects and iterates through the list,

STATUS: WORKING
*/

void printCatalogue(car* n) {

    if (n == nullptr) {
        std::cout << std::endl << "No cars are currently listed in catalogue." << std::endl;
    }

    while (n != nullptr) {
        std::cout << std::endl << "***************************************" << std::endl;
        std::cout << "Index#: " << n->GetIndex() << std::endl;
        std::cout << "Owner: " << n->GetOwner() << std::endl;
        std::cout << "Model: " << n->GetModel() << std::endl;
        std::cout << "VIN# : " << n->GetVin() << std::endl;
        std::cout << "Miles: " << n->GetMileage() << std::endl;
        std::cout << "MPG  : " << n->GetMPG() << std::endl;
        std::cout << "Price: $" << n->GetPrice() << std::endl;
        std::cout << "Status: ";
        if (n->GetSale()) {
            std::cout << "Still available" << std::endl;
        }
        else {
            std::cout << "Not available" << std::endl;
        }
        n = n->GetNext();
    }
    std::cout << std::endl;
}

//**********************************************************************************************************************

/*
printCar function: Takes a pointer to a car object and prints all of its details to the console.

STATUS: WORKING
*/

void printCar(car* n) {
    std::cout << std::endl << "***************************************" << std::endl;
    std::cout << "Owner: " << n->GetOwner() << std::endl;
    std::cout << "Model: " << n->GetModel() << std::endl;
    std::cout << "VIN# : " << n->GetVin() << std::endl;
    std::cout << "Miles: " << n->GetMileage() << std::endl;
    std::cout << "MPG  : " << n->GetMPG() << std::endl;
    std::cout << "Price: " << n->GetPrice() << std::endl;
    std::cout << "Status: ";
    if (n->GetSale()) {
        std::cout << "Still available" << std::endl;
    }
    else {
        std::cout << "Not available" << std::endl;
    }

}

//**********************************************************************************************************************

/*
findCar function: Takes a pointer to the head of the linked list of car objects and prompts the user to enter a valid car index.
It then iterates through the linked list to find the car with the matching index and returns a pointer to that car object.

STATUS: WORKING
*/

car* findCar(car*& head) {
    car* Pfound = nullptr;
    int indexSearch;

    do {
        std::cout << "\n***************************************\n";
        std::cout << "Enter valid car index: ";
        std::cin >> indexSearch;

        car* n = head;
        while (n != nullptr) {
            if (n->GetIndex() == indexSearch) {
                Pfound = n;
                break;
            }
            n = n->GetNext();
        }

        if (Pfound == nullptr)
            std::cout << "Car not found, choose another index.\n";

    } while (Pfound == nullptr);

    return Pfound;
}
//**********************************************************************************************************************
