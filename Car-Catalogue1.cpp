#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>

//**********************************************************************************************************************

/*
Class car: Represents a car object with various attributes such as owner, model, VIN, mileage, MPG, price, and availability status.
*/

class car {
private:
    int index;
    std::string Owner;
    std::string Model;
    std::string Vin;
    int Mileage;
    int MPG;
    int Price;
    bool ForSale;
    car* Prev = nullptr;
    car* Next = nullptr;
public:
    // First the Setters
    void SetIndex(int newIndex) {
        index = newIndex;
    }
    void SetOwner(std::string newOwner) {
        Owner = newOwner;
    };
    void SetModel(std::string newModel) {
        Model = newModel;
    };
    void SetVin(std::string newVin) {
        Vin = newVin;
    };
    void SetMileage(int newMileage) {
        Mileage = newMileage;
    };
    void SetMPG(int newMPG) {
        MPG = newMPG;
    };
    void SetPrice(int newPrice) {
        Price = newPrice;
    };
    void SetSale(bool newSale) {
        ForSale = newSale;
    };
    void SetPrev(car* newPrev) {
        Prev = newPrev;
    };
    void SetNext(car* newNext) {
        Next = newNext;
    };
    // Next the Getters
    int GetIndex() {
        return index;
    }
    std::string GetOwner() {
        return Owner;
    };
    std::string GetModel() {
        return Model;
    };
    std::string GetVin() {
        return Vin;
    };
    int GetMileage() {
        return Mileage;
    };
    int GetMPG() {
        return MPG;
    };
    int GetPrice() {
        return Price;
    };
    bool GetSale() {
        return ForSale;
    };
    car* GetPrev() {
        return Prev;
    };
    car* GetNext() {
        return Next;
    };
};

//**********************************************************************************************************************

/*
Function declarations for program structure, defined after main function
*/

void fileLoad();

void optionsMenu(car*& head, std::vector<car*>& carCatalogue);

void printCatalogue(car* n);

void printCar(car* n);

car* findCar(car*& head);

void addCar(car*& head, std::vector<car*>& carCatalogue);

void editCar(car* n);

void deleteCar(car* n);

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
    addCar(head, carCatalogue);

    std::cout << std::endl << "Now please feel free to peruse the catalogue: " << std::endl;
    printCatalogue(head);

    do {
        optionsMenu(head, carCatalogue);
        std::cout << std::endl << "Would you like to change anything else? (Yes/No): ";
        std::getline(std::cin, Cont);
        std::transform(Cont.begin(), Cont.end(), Cont.begin(),
            [](unsigned char c) { return std::toupper(c); });
    } while (Cont == "YES");

    return 0;
}
//**********************************************************************************************************************

/*
optionsMenu function: Displays a menu of options to the user and prompts them to select an action.

STATUS: TESTING
*/

void optionsMenu(car*& head, std::vector<car*>& carCatalogue) {
    std::cout << std::endl << "***************************************" << std::endl;
    std::cout << "1) Print Specific Car" << std::endl;
    std::cout << "2) Add a Car" << std::endl;
    std::cout << "3) Edit a Car" << std::endl;
    std::cout << "4) Remove a Car" << std::endl;
    std::cout << std::endl << "***************************************" << std::endl;
    int selectedAction;
    std::cout << "Please enter number for desired selection: ";
    std::cin >> selectedAction;
    switch (selectedAction) {
    case 1: {
        car* n = findCar(head);
        printCar(n);
        break;
    }
    case 2: {
        addCar(head, carCatalogue);
        printCatalogue(head);
        break;
    }
    case 3: {
        car* n = findCar(head);
        editCar(n);
        printCar(n);
        break;
    }
    case 4: {
        car* n = findCar(head);
        deleteCar(n);
        printCatalogue(head);
        break;
    }
    default: {
        std::cout << std::endl << "you have not selected a valid option" << std::endl;
        break;
    }

    }
}

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

        std::cout << std::endl << "Would you like to add another car? (Yes/No): ";
        std::getline(std::cin, Cont);
        std::transform(Cont.begin(), Cont.end(), Cont.begin(),
            [](unsigned char c) { return std::toupper(c); });
    } while (Cont == "YES");
}

//**********************************************************************************************************************

/*
editCar function: Takes a pointer to a car object and allows the user to edit any of its attributes by selecting from a menu.

STATUS: TESTING
*/

void editCar(car* n) {

    std::string Cont = "YES";
    do {
        int choice;
        std::cout << std::endl << "***************************************" << std::endl;
        std::cout << std::endl << "1) - Index";
        std::cout << std::endl << "2) - Owner";
        std::cout << std::endl << "3) - Model";
        std::cout << std::endl << "4) - Vin";
        std::cout << std::endl << "5) - Mileage";
        std::cout << std::endl << "6) - MPG";
        std::cout << std::endl << "7) - Price";
        std::cout << std::endl << "8) - Availability";
        std::cout << std::endl << "***************************************" << std::endl;
        std::cout << std::endl << "Please enter number for desired selection: ";
        std::cin >> choice;
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

void deleteCar(car* n) {

    if ((n->GetPrev()) == nullptr) {

		n->GetNext()->SetPrev(nullptr);
    }
    else if ((n->GetNext()) == nullptr) {

		n->GetPrev()->SetNext(nullptr);
    }
    else {
        n->GetPrev()->SetNext(n->GetNext());
        n->GetNext()->SetPrev(n->GetPrev());
    }
    delete n;
    std::cout << std::endl << "Car deleted successfully." << std::endl;
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

    printCar(Pfound);
    return Pfound;
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
printCatalogue function: Takes a pointer to the head of the linked list of car objects and iterates through the list,

STATUS: WORKING
*/

void printCatalogue(car* n) {
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