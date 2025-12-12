#pragma once
#include <vector>
#include "Cars.h"

//Function declarations for program structure, defined after main function
  
void addCar(car*& head, std::vector<car*>& carCatalogue);

void editCar(car* n);

void deleteCar(car*& head, std::vector<car*>& carCatalogue, car* n);

void moveCar(car*& head, car*& tail, std::vector<car*>& carCatalogue, car* n);
