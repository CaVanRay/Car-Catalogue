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

// This section updates the index by linked list inside each item
while(n != nullptr){
    n -> SetIndex(count);
    count++;
    n = n->GetNext();
 }

// This section updates the vector list to match the updated linked list
carCatalogue.clear();
car* n = head;
while (n != nullptr){
    carCatalogue.push_back(n);
    n = n->GetNext();
}
    
}

//**********************************************************************************************************************

int getInt(){


    
}

//**********************************************************************************************************************

double getDouble(){


    
}

//**********************************************************************************************************************

bool getYN(){


    
}

//**********************************************************************************************************************

string getVIN(){


    
}

//**********************************************************************************************************************
