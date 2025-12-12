#include "CarCatHeaders.h"

//**********************************************************************************************************************
 
int main() {

    car* head = nullptr;
    car* tail = nullptr;

    std::vector<car*> carCatalogue;

    loadCatalogue(head, tail, carCatalogue);

    printCatalogue(head);

    optionsMenu(head, carCatalogue);

    return 0;
}
//**********************************************************************************************************************
