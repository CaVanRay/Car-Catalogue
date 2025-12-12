#pragma once
#include <vector>
#include "Cars.h"

//Function declarations for program structure, defined after main function

void saveCatalogue(car*& head);

void loadCatalogue(car*& head, car*& tail, std::vector<car*>& carCatalogue);
