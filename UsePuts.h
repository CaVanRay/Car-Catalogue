#pragma once
#include <vector>
#include "Cars.h"


// Functions to handle any inputs & outputs

void optionsMenu(car*& head, std::vector<car*>& carCatalogue);

void printCatalogue(car* n);

void printCar(car* n);

void findCar();
