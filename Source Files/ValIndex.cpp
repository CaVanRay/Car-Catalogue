#include "CarCatHeaders.h"

//**********************************************************************************************************************

/*
ValIndex functions: Validates the catalogue index as well as any inputs

STATUS: Designing
*/

//**********************************************************************************************************************

// The entire catalogue will need to be passed to indexUpdate()
// The size of the existing catalogue taken
// and then it will re-iterate through the linked list of items to re-set each index?

void indexUpdate(car*& head, std::vector<car*>& carCatalogue){
  
      if (n == nullptr) {
          std::cout << std::endl << "No cars are currently listed in catalogue." << std::endl;
      }
      while (n != nullptr) {
              std::cout << std::endl << "***************************************" << std::endl;
              std::cout << "Index#: " << n->GetIndex() << std::endl;
              std::cout << "Owner: " << n->GetOwner() << std::endl;
              std::cout << "Model: " << n->GetModel() << std::endl;
              std::cout << "VIN# : " << n->GetVin() << std::endl;
              std::cout << "Miles: " << n->GetMileage() << std::endl;
              std::cout << "MPG  : " << n->GetMPG() << std::endl;
              std::cout << "Price: $" << n->GetPrice() << std::endl;
              std::cout << "Status: ";
              if (n->GetSale()) {
                  std::cout << "Still available" << std::endl;
              }
              else {
                  std::cout << "Not available" << std::endl;
              }
              n = n->GetNext();
          }
          std::cout << std::endl;
      }
  
}

//**********************************************************************************************************************


void inputValidate(){


  
}

//**********************************************************************************************************************
