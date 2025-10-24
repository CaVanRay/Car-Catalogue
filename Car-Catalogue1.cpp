#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>
#include <cctype>

//***********************************************************************

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

//***********************************************************************

void printCatalogue(car* n) {
    int index = 1;
    while (n != nullptr) {
        std::cout << std::endl << "***************************************" << std::endl;
        n->SetIndex(index);
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
        index++;
        n = n->GetNext();
    }
    std::cout << std::endl;
}
 
//***********************************************************************

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

//***********************************************************************

car* findCar(){
    car* n;
    int choice;
    std::cout << std::endl << "How would you like to search?";
    std::cout << std::endl << "1) - Index";
    std::cout << std::endl << "2) - Owner";
    std::cout << std::endl << "3) - Model";
    std::cout << std::endl << "4) - Vin";
    std::cout << std::endl << "5) - Mileage";
    std::cout << std::endl << "6) - MPG";
    std::cout << std::endl << "7) - Price";
    std::cout << std::endl << "8) - Availability";
  return n;
}

//***********************************************************************

void editCar(car* n){
    
    car* m;
	int choice;
    std::cout << std::endl << "***************************************" << std::endl;
	std::cout << "Enter the index of the car you want to edit: ";
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
	case 1:
		int newIndex;
		std::cout << "Enter new index: ";
		std::cin >> newIndex;
		n->SetIndex(newIndex);
		break;
	case 2:
		std::string newOwner;
		std::cout << "Enter new owner: ";
		std::cin.ignore();
		std::getline(std::cin, newOwner);
		n->SetOwner(newOwner);
		break;


}

//***********************************************************************

void deleteCar(car* n){

	n->GetPrev()->SetNext(n->GetNext());
	n->GetNext()->SetPrev(n->GetPrev());
    delete n;
	std::cout << std::endl << "Car deleted successfully." << std::endl;
}

//***********************************************************************

int main() {
    char conti;
    car* head = nullptr;
    std::vector<car*> carCatalogue;
    size_t numberOfCars;
    do {

        std::string Owner;
        std::string Model;
        std::string Vin;
        int Mileage;
        int MPG;
        int Price;
        std::string Available;
        bool ForSale;
        //***********************************************************************
        std::cout << std::endl << "Please Add a vehical to the catalogue" << std::endl << std::endl;

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
        }
        else {
            head = newCar;
        }

        carCatalogue.push_back(newCar);

        std::cout << std::endl << std::endl << "Continue adding cars? (Y/N) :";
        std::cin >> conti;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (toupper(conti) == 'Y');

    std::cout << std::endl << "Now please feel free to peruse the catalogue: " << std::endl;
    printCatalogue(head);
    // Here is where I'll put the commands for options
    std::cout << std::endl << "***************************************" << std::endl;
    std::cout << "1) Print Specific Car" << std::endl;
    std::cout << "2) Add a Car" << std::endl;
    std::cout << "3) Edit a Car" << std::endl;
    std::cout << "4) Remove a Car" << std::endl;
    std::cout << std::endl << "***************************************" << std::endl;
    int selectedAction;
    std::cout << "Please enter number for desired selection: ";
    std::cin >> selectedAction;


    return 0;
}
