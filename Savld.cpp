#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>
#include "CatFunc.h"
#include "Cars.h"
#include "UsePuts.h"
#include "Savld.h"

const std::string FILE_NAME = "CarCatalogue.txt";

//**********************************************************************************************************************
// Save current catalogue to be used next time the program is run
//**********************************************************************************************************************

void saveCatalogue(car*& head) {
    std::ofstream outputFile(FILE_NAME);
    if (!outputFile.is_open()) {
        std::cerr << "[Error] Could not open " << FILE_NAME << " for writing.\n";
        return;
    }

    car* current = head;
    while (current != nullptr) {
        outputFile << current->GetIndex() << '|'
            << current->GetOwner() << '|'
            << current->GetModel() << '|'
            << current->GetVin() << '|'
            << current->GetMileage() << '|'
            << current->GetMPG() << '|'
            << current->GetPrice() << '|'
            << (current->GetSale() ? 1 : 0) << '\n';
        current = current->GetNext();
    }

    outputFile.close();
    std::cout << "[Info] Catalogue saved successfully to " << FILE_NAME << "\n";
}

//**********************************************************************************************************************
// Load previously saved catalogue into a new instance of the program
//**********************************************************************************************************************

void loadCatalogue(car*& head, std::vector<car*>& carCatalogue) {
    std::ifstream inputFile(FILE_NAME);

    if (!inputFile.is_open()) {
        std::cout << "[Info] No existing catalogue found. Starting fresh.\n";
        return;
    }

    carCatalogue.clear();
    head = nullptr;

    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string token;

        int index, mileage, mpg, price;
        std::string owner, model, vin;
        bool forSale;

        std::getline(ss, token, '|'); index = std::stoi(token);
        std::getline(ss, owner, '|');
        std::getline(ss, model, '|');
        std::getline(ss, vin, '|');
        std::getline(ss, token, '|'); mileage = std::stoi(token);
        std::getline(ss, token, '|'); mpg = std::stoi(token);
        std::getline(ss, token, '|'); price = std::stoi(token);
        std::getline(ss, token, '|'); forSale = (std::stoi(token) != 0);

        car* newCar = new car();
        newCar->SetIndex(index);
        newCar->SetOwner(owner);
        newCar->SetModel(model);
        newCar->SetVin(vin);
        newCar->SetMileage(mileage);
        newCar->SetMPG(mpg);
        newCar->SetPrice(price);
        newCar->SetSale(forSale);

        if (!carCatalogue.empty()) {
            newCar->SetPrev(carCatalogue.back());
            carCatalogue.back()->SetNext(newCar);
        }
        else {
            head = newCar;
        }

        carCatalogue.push_back(newCar);
    }

    inputFile.close();
    std::cout << "[Info] Catalogue loaded successfully from " << FILE_NAME << "\n";
}
