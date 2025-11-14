#include "CarCatHeaders.h"

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
