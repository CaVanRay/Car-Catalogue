#pragma once
#include <vector>
#include "Cars.h"


// Functions to validate inputs & index

void indexUpdate(car*& head, std::vector<car*>& carCatalogue);

int getInt();

double getDouble();

bool getYN();

string getVIN();
