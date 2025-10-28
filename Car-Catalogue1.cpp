#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>
#include "CatFunc.h"

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

	// loadCatalogue(); // TO - DO: implement file loading function to read existing catalogue from file
	// printCatalogue(head); // to show loaded catalogue before any changes are made

    addCar(head, carCatalogue);

    // saveCatalogue(); // TO - DO: implement file saving function to write catalogue to file

    std::cout << std::endl << "Now please feel free to peruse the catalogue: " << std::endl;

    do {
        printCatalogue(head);
        optionsMenu(head, carCatalogue);
        std::cout << std::endl << "Would you like to choose another option? (Yes/No): ";
        std::getline(std::cin, Cont);
        std::transform(Cont.begin(), Cont.end(), Cont.begin(),
            [](unsigned char c) { return std::toupper(c); });
    } while (Cont == "YES");

    return 0;
}
//**********************************************************************************************************************