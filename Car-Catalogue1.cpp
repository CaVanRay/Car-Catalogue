#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>
#include "CatFunc.h"
#include "Cars.h"
#include "savld.h"

//**********************************************************************************************************************
 
int main() {

    car* head = nullptr;

    std::vector<car*> carCatalogue;

    loadCatalogue(head, carCatalogue);

    printCatalogue(head);

    addCar(head, carCatalogue);

    printCatalogue(head);

    optionsMenu(head, carCatalogue);

    return 0;
}
//**********************************************************************************************************************