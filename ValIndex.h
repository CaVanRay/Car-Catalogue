#pragma once
#include <vector>
#include "Cars.h"


// Functions to validate inputs & index

void indexUpdate(car*& head, std::vector<car*>& carCatalogue);

std::string getString(const std::string& prompt);

int getInt(const std::string& prompt);

double getDouble(const std::string& prompt);

bool getYN(const std::string& prompt);

std::string getVIN(car*& head, const std::string& prompt);
