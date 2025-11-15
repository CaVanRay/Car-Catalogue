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
    
car* n = head;
int count = 1; 
    
while(n != nullptr){
    n -> SetIndex(count);
 }
    
}

//**********************************************************************************************************************


void inputValidate(){


  
}

//**********************************************************************************************************************
