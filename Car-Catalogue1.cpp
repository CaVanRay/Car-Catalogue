#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>
#include "CatFunc.h"
#include "Cars.h"
#include "Savld.h"

//**********************************************************************************************************************
 
int main() {

    car* head = nullptr;

    std::vector<car*> carCatalogue;

    loadCatalogue(head, carCatalogue);

    printCatalogue(head);

    optionsMenu(head, carCatalogue);

    return 0;
}
//**********************************************************************************************************************