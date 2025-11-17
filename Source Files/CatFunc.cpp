#include "CarCatHeaders.h"

//**********************************************************************************************************************

/*
addCar function: Collects user input to create a new car object and adds it to the end of the linked list.
If the list is empty, the new car becomes the head of the list.

STATUS: WORKING
*/

void addCar(car*& head, std::vector<car*>& carCatalogue) {

    std::string Cont = "YES";
    do {
        int index;
        std::string Owner;
        std::string Model;
        std::string Vin = getVin("input car vin#: ");
        int Mileage = getInt("input car mileage: ");
        int MPG = getDouble("input car MPG: ");
        int Price = getDouble("input car price: ");
        bool ForSale = getYN("is car available for purchase? (Y/N): ");
        //***********************************************************************
        std::cout << std::endl << "Please Add a vehicle to the catalogue" << std::endl << std::endl;

        std::cout << "input car owner: ";
        std::getline(std::cin, Owner);

        std::cout << std::endl << "input car model: ";
        std::getline(std::cin, Model);

        //***********************************************************************

        car* newCar = new car();
        newCar->SetOwner(Owner);
        newCar->SetModel(Model);
        newCar->SetVin(Vin);
        newCar->SetMileage(Mileage);
        newCar->SetMPG(MPG);
        newCar->SetPrice(Price);
        newCar->SetSale(ForSale);


        if (!carCatalogue.empty()) {
            newCar->SetPrev(carCatalogue.back());
            carCatalogue.back()->SetNext(newCar);
            newCar->SetIndex(carCatalogue.size() + 1);
        }
        else {
            head = newCar;
            newCar->SetIndex(1);
        }

        carCatalogue.push_back(newCar);

        system("CLS");

        std::cout << std::endl << "Would you like to add another car? (Yes/No): ";
        std::getline(std::cin, Cont);
        std::transform(Cont.begin(), Cont.end(), Cont.begin(),
            [](unsigned char c) { return std::toupper(c); });
    } while (Cont == "YES");

	// Update the index's of each item in linked list
	// Update the carCatalogue vector with linked list
	indexUpdate(head, carCatalogue);
}


//**********************************************************************************************************************

/*
editCar function: Takes a pointer to a car object and allows the user to edit any of its attributes by selecting from a menu.

STATUS: TESTING
*/

void editCar(car* n) {

    std::string Cont = "YES";
    do {
        // system("CLS");
        printCar(n);
        int choice;
        std::cout << std::endl << "***************************************" << std::endl;
        std::cout << std::endl << "1) - Owner";
        std::cout << std::endl << "2) - Model";
        std::cout << std::endl << "3) - Vin";
        std::cout << std::endl << "4) - Mileage";
        std::cout << std::endl << "5) - MPG";
        std::cout << std::endl << "6) - Price";
        std::cout << std::endl << "7) - Availability";
        std::cout << std::endl << "***************************************" << std::endl;
        std::cout << "Please enter number for desired selection: ";
        while (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a valid number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch (choice) {
        case 1: {
            std::string newOwner;
            std::cout << "Enter new owner: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, newOwner);
            n->SetOwner(newOwner);
            break;
        }
        case 2: {
            std::string newModel;
            std::cout << "Enter new model: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, newModel);
            n->SetModel(newModel);
            break;
        }
        case 3: {
            std::string newVin = getVIN("Enter VIN: ");
            n->SetVin(newVin);
            break;
        }
        case 4: {
            int newMileage = getInt("Enter new mileage: ");
            n->SetMileage(newMileage);
            break;
        }
        case 5: {
            double newMPG = getDouble("Enter new MPG: ");
            n->SetMPG(newMPG);
            break;
        }
        case 6: {
            double newPrice = getDouble("Enter new price: ");
            n->SetPrice(newPrice);
            break;
        }
        case 7: {
            std::cout << "Is the car available for purchase? \n";
            bool newForSale = getYN("Enter (Y/N): ");
            n->SetSale(newForSale);
            break;
        }
        default: {
            std::cout << std::endl << "you have not selected a valid option" << std::endl;
            break;
        }
        }
        std::cout << std::endl << "Would you like to change anything else? (Yes/No): ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, Cont);
        std::transform(Cont.begin(), Cont.end(), Cont.begin(),
            [](unsigned char c) { return std::toupper(c); });
    } while (Cont == "YES");
}

//**********************************************************************************************************************

/*
deleteCar function: Takes a pointer to a car object and removes it from the linked list by updating the previous and next pointers

STATUS: TESTING
*/
// I think if I delete the first car in the catalogue, that it will break several functions that require head
// Testing this now

void deleteCar(car*& head, std::vector<car*>& carCatalogue, car* n) {

    if (n == nullptr) return;

    // If this is the head
    if (n->GetPrev() == nullptr) {
        head = n->GetNext();   // update head
        if (head != nullptr) { // if list not empty now
            head->SetPrev(nullptr);
        }
    }
    else if (n->GetNext() == nullptr) { // if this is the tail
        n->GetPrev()->SetNext(nullptr);
    }
    else { // middle of the list
        n->GetPrev()->SetNext(n->GetNext());
        n->GetNext()->SetPrev(n->GetPrev());
    }
    delete n;
	indexUpdate(head, carCatalogue);
    std::cout << std::endl << "Car deleted successfully." << std::endl;
}

//**********************************************************************************************************************
