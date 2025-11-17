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
        std::string Vin;
        int Mileage;
        int MPG;
        int Price;
        std::string Available;
        bool ForSale;
        //***********************************************************************
        std::cout << std::endl << "Please Add a vehicle to the catalogue" << std::endl << std::endl;

        std::cout << "input car owner: ";
        std::getline(std::cin, Owner);


        std::cout << std::endl << "input car model: ";
        std::getline(std::cin, Model);


        std::cout << std::endl << "input car vin#: ";
        std::getline(std::cin, Vin);


        std::cout << std::endl << "input car mileage: ";
        std::cin >> Mileage;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        std::cout << std::endl << "input car MPG: ";
        std::cin >> MPG;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        std::cout << std::endl << "input car price: ";
        std::cin >> Price;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << std::endl << "is car available for purchase? (Yes/No): ";
        std::getline(std::cin, Available);
        std::transform(Available.begin(), Available.end(), Available.begin(),
            [](unsigned char c) { return std::toupper(c); });
        if (Available == "YES") {
            ForSale = true;
        }
        else {
            ForSale = false;
        }
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
        std::cout << std::endl << "1) - Index"; // TO-DO Replace with re-order option
        std::cout << std::endl << "2) - Owner";
        std::cout << std::endl << "3) - Model";
        std::cout << std::endl << "4) - Vin";
        std::cout << std::endl << "5) - Mileage";
        std::cout << std::endl << "6) - MPG";
        std::cout << std::endl << "7) - Price";
        std::cout << std::endl << "8) - Availability";
        std::cout << std::endl << "***************************************" << std::endl;
        std::cout << "Please enter number for desired selection: ";
        while (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a valid number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch (choice) {
        case 1: {
            int newIndex;
            std::cout << "Enter new index: ";
            std::cin >> newIndex;
            n->SetIndex(newIndex);
            break;
        }
        case 2: {
            std::string newOwner;
            std::cout << "Enter new owner: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, newOwner);
            n->SetOwner(newOwner);
            break;
        }
        case 3: {
            std::string newModel;
            std::cout << "Enter new model: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, newModel);
            n->SetModel(newModel);
            break;
        }
        case 4: {
            std::string newVin;
            std::cout << "Enter new vin#: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, newVin);
            n->SetVin(newVin);
            break;
        }
        case 5: {
            int newMileage;
            std::cout << "Enter new mileage: ";
            std::cin >> newMileage;
            n->SetMileage(newMileage);
            break;
        }
        case 6: {
            int newMPG;
            std::cout << "Enter new MPG: ";
            std::cin >> newMPG;
            n->SetMPG(newMPG);
            break;
        }
        case 7: {
            int newPrice;
            std::cout << "Enter new price: ";
            std::cin >> newPrice;
            n->SetPrice(newPrice);
            break;
        }
        case 8: {
            std::string newAvailable;
            bool newForSale;
            std::cout << "Is the car available for purchase? (Yes/No): ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, newAvailable);
            std::transform(newAvailable.begin(), newAvailable.end(), newAvailable.begin(),
                [](unsigned char c) { return std::toupper(c); });
            if (newAvailable == "YES") {
                newForSale = true;
            }
            else {
                newForSale = false;
            }
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
