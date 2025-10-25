#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>
#include <cctype>

//**********************************************************************************************************************

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
    car* Prev;
    car* Next;
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

void optionsMenu(car*& head, std::vector<car*>& carCatalogue);

void printCatalogue(car* n);

void printCar(car* n);

car* findCar();

void addCar(car*& head, std::vector<car*>& carCatalogue);

void editCar(car* n);

void deleteCar(car* n);

//**********************************************************************************************************************

int main() {
    std::string Cont = "YES";
    car* head = nullptr;
    std::vector<car*> carCatalogue;
    size_t numberOfCars;
    addCar(head, carCatalogue);

    std::cout << std::endl << "Now please feel free to peruse the catalogue: " << std::endl;
    printCatalogue(head);

    do {
        optionsMenu(head, carCatalogue);
        std::cout << std::endl << "Would you like to change anything else? (Yes/No): ";
        std::cin.ignore();
        std::getline(std::cin, Cont);
        std::transform(Cont.begin(), Cont.end(), Cont.begin(),
            [](unsigned char c) { return std::toupper(c); });
    } while (Cont == "YES");

    return 0;
}
//**********************************************************************************************************************

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
        car* n = findCar();
        printCar(n);
        break;
    }
    case 2: {
        addCar(head, carCatalogue);
        printCatalogue(head);
        break;
    }
    case 3: {
        car* n = findCar();
        editCar(n);
        printCar(n);
        break;
    }
    case 4: {
        car* n = findCar();
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

        // Check for a head, if there isn't one create one, if there is one check array of pointers for size and then append new car to the end

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
            newCar->SetIndex((carCatalogue.size+1));
        }
        else {
            head = newCar;
            newCar->SetIndex(1)
        }

        carCatalogue.push_back(newCar);

        std::cout << std::endl << "Would you like to add another car? (Yes/No): ";
        // std::cin.ignore(); was causing issues, I think it is safe to remove
        std::getline(std::cin, Cont);
        std::transform(Cont.begin(), Cont.end(), Cont.begin(),
            [](unsigned char c) { return std::toupper(c); });
    } while (Cont == "YES");
}

//**********************************************************************************************************************

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
            std::cin.ignore(); // Need better solution for all these ignore()'s
            std::getline(std::cin, newOwner);
            n->SetOwner(newOwner);
            break;
        }
        case 3: {
            std::string newModel;
            std::cout << "Enter new model: ";
            std::cin.ignore();
            std::getline(std::cin, newModel);
            n->SetModel(newModel);
            break;
        }
        case 4: {
            std::string newVin;
            std::cout << "Enter new vin#: ";
            std::cin.ignore();
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
            std::cin.ignore();
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
        std::cin.ignore();
        std::getline(std::cin, Cont);
        std::transform(Cont.begin(), Cont.end(), Cont.begin(),
            [](unsigned char c) { return std::toupper(c); });
    } while (Cont == "YES");
}
//**********************************************************************************************************************

void deleteCar(car* n) {

    // Need to add checks to avoid problems with 
    // Head or tail
    if ((n->GetPrev()) == nullptr) {

    }
    else if ((n->GetNext()) == nullptr) {

    }
    else {
        n->GetPrev()->SetNext(n->GetNext());
        n->GetNext()->SetPrev(n->GetPrev());
    }
    delete n;
    std::cout << std::endl << "Car deleted successfully." << std::endl;
}

//**********************************************************************************************************************

car* findCar() {
    car* n = nullptr;
    std::cout << std::endl << "***************************************" << std::endl;
    std::cout << "Enter the index of the car: ";
    std::cin << indexSearch;
    // search for index here - will return match or state "Car not found, choose another index"
    printCar(n);
    return n;
}

//**********************************************************************************************************************

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