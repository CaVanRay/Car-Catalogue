#pragma once
#include <vector>
#include "Cars.h"

//Function declarations for program structure, defined after main function

// addCar() : adds cars to the catalogue
void addCar(car*& head, std::vector<car*>& carCatalogue);

// repCar() : swaps out existing car for a new car
void repCar(car* n);

// editCar() : changes selected value on an existing car
void editCar(car* n);

// deleteCar() : removes existing car from the catalogue
void deleteCar(car*& head, car*& tail, std::vector<car*>& carCatalogue, car* n);

void moveCar(car*& head, car*& tail, std::vector<car*>& carCatalogue, car* n);
