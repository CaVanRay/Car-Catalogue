#include "CarCatHeaders.h"

//**********************************************************************************************************************

/*
addCar function: Collects user input to create a new car object and adds it to the end of the linked list.
If the list is empty, the new car becomes the head of the list.

STATUS: WORKING
*/

void addCar(car*& head, std::vector<car*>& carCatalogue) {

    std::string Cont = "YES";
    do {

        std::cout << std::endl << "Please Add a vehicle to the catalogue" << std::endl << std::endl;

        int index;
        std::string Owner = getString("input car owner: ");
        std::string Model = getString("input car model: ");
        std::string Vin = getVIN("input car vin#: ");
        int Mileage = getInt("input car mileage: ");
        double MPG = getDouble("input car MPG: ");
        double Price = getDouble("input car price: ");
        bool ForSale = getYN("is car available for purchase? (Y/N): ");

        //***********************************************************************

        car* newCar = new car();
        newCar->SetOwner(Owner);
        newCar->SetModel(Model);
        newCar->SetVin(Vin);
        newCar->SetMileage(Mileage);
        newCar->SetMPG(MPG);
        newCar->SetPrice(Price);
        newCar->SetSale(ForSale);


        if (!carCatalogue.empty()) {
            newCar->SetPrev(carCatalogue.back());
            carCatalogue.back()->SetNext(newCar);
            newCar->SetIndex(carCatalogue.size() + 1);
        }
        else {
            head = newCar;
            newCar->SetIndex(1);
        }

        carCatalogue.push_back(newCar);

        system("CLS");

        std::cout << std::endl << "Would you like to add another car? (Yes/No): ";
        std::getline(std::cin, Cont);
        std::transform(Cont.begin(), Cont.end(), Cont.begin(),
            [](unsigned char c) { return std::toupper(c); });
    } while (Cont == "YES");

	// Update the index's of each item in linked list
	// Update the carCatalogue vector with linked list
	indexUpdate(head, carCatalogue);
}


//**********************************************************************************************************************

/*
editCar function: Takes a pointer to a car object and allows the user to edit any of its attributes by selecting from a menu.

STATUS: TESTING
*/

void editCar(car* n) {

    std::string Cont = "YES";
    do {
        // system("CLS");
        printCar(n);
        int choice;
        std::cout << std::endl << "***************************************" << std::endl;
        std::cout << std::endl << "1) - Owner";
        std::cout << std::endl << "2) - Model";
        std::cout << std::endl << "3) - Vin";
        std::cout << std::endl << "4) - Mileage";
        std::cout << std::endl << "5) - MPG";
        std::cout << std::endl << "6) - Price";
        std::cout << std::endl << "7) - Availability";
        std::cout << std::endl << "***************************************" << std::endl;
        std::cout << "Please enter number for desired selection: ";
        while (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a valid number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch (choice) {
        case 1: {
            std::string newOwner;
            std::cout << "Enter new owner: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, newOwner);
            n->SetOwner(newOwner);
            break;
        }
        case 2: {
            std::string newModel;
            std::cout << "Enter new model: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, newModel);
            n->SetModel(newModel);
            break;
        }
        case 3: {
            std::string newVin = getVIN("Enter VIN: ");
            n->SetVin(newVin);
            break;
        }
        case 4: {
            int newMileage = getInt("Enter new mileage: ");
            n->SetMileage(newMileage);
            break;
        }
        case 5: {
            double newMPG = getDouble("Enter new MPG: ");
            n->SetMPG(newMPG);
            break;
        }
        case 6: {
            double newPrice = getDouble("Enter new price: ");
            n->SetPrice(newPrice);
            break;
        }
        case 7: {
            std::cout << "Is the car available for purchase? \n";
            bool newForSale = getYN("Enter (Y/N): ");
            n->SetSale(newForSale);
            break;
        }
        default: {
            std::cout << std::endl << "you have not selected a valid option" << std::endl;
            break;
        }
        }
        std::cout << std::endl << "Would you like to change anything else? (Yes/No): ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, Cont);
        std::transform(Cont.begin(), Cont.end(), Cont.begin(),
            [](unsigned char c) { return std::toupper(c); });
    } while (Cont == "YES");
}

//**********************************************************************************************************************

/*
deleteCar function: Takes a pointer to a car object and removes it from the linked list by updating the previous and next pointers

STATUS: TESTING
*/
// I think if I delete the first car in the catalogue, that it will break several functions that require head
// Testing this now

void deleteCar(car*& head, std::vector<car*>& carCatalogue, car* n) {

    if (n == nullptr) return;

    // If this is the head
    if (n->GetPrev() == nullptr) {
        head = n->GetNext();   // update head
        if (head != nullptr) { // if list not empty now
            head->SetPrev(nullptr);
        }
    }
    else if (n->GetNext() == nullptr) { // if this is the tail
        n->GetPrev()->SetNext(nullptr);
    }
    else { // middle of the list
        n->GetPrev()->SetNext(n->GetNext());
        n->GetNext()->SetPrev(n->GetPrev());
    }
    delete n;
	indexUpdate(head, carCatalogue);
    std::cout << std::endl << "Car deleted successfully." << std::endl;
}

//**********************************************************************************************************************

void moveCar(car*& head, std::vector<car*>& carCatalogue, car*n){
	/* 
	This will be the moveCar() function
	Pretty self-explanitory, it moves cars up and down the list

	STATUS: Planning

    needed inputs:
		- get index of position to move to
		- compare indexes and either move up or down, if up you go with prev pointers, if down you go with next pointers
		- If manaully overwriting items as they move, you will need to store the data of the car being moved in temp variables
	*/

	// get current catalogue size
	car* Pcount = head;
    int listSize = 0;
    while (Pcount != nullptr) {
            listSize++;
            Pcount = Pcount->GetNext();
    }

	// get current index #
	int currentindex = n->GetIndex();

	// get desired index #
	do {
	int newindex = getInt("Enter desired new index for car: ");
	
		while (newindex < 1 || newindex > listSize){
			newindex = getInt("Invalid index, Try again: ");
		}
	}
	
	std::cout >> endl >> endl;
	std::cout >> "Desired index: " >> newindex >> endl;
	std::cout >> "Current index: " >> currentindex >> endl;

	// create temp pointers for newPrev & newNext to be set after changes are made
	car* newPrev; 
	car* newNext;
	
	// compare current index to desired index
	if(newindex < currentindex){
		// if the new index is smaller, begin incrementing down one at a time
		do{
			// set temp pointers for after changes are made
			
			newPrev = ((GetPrev()->GetPrev()) != nullptr) ? (GetPrev()->GetPrev()) : nullptr; 
			newNext = GetPrev();
			
			// now change the surrounding items working from furthest out inward
			
			//if((GetPrev()->GetPrev()) != nullptr){
			GetPrev()->GetPrev()->SetNext(n);
			//}
			
			GetPrev()->SetPrev(n);

			// I need to check if there is a next item after n
			//if((n->GetNext()) != nullptr){			
			GetPrev()->SetNext(n->GetNext());
			GetNext()->SetPrev(n->GetPrev());
			//}
			
			// I need to check if there is item before previous item or is it the head of list
			//if((n->GetPrev()->GetPrev() != nullptr){
			n->SetPrev(newPrev);
			n->SetNext(newNext);
			//}
			
		}while(newindex < currentindex)
	}
	if(newindex > currentindex){
		// if the new index is larger, begin incrementing up one at a time
		do{
			newPrev = n->GetNext();
		}while(newindex > currentindex)
	}
	if(newindex == currentindex){
		// If newindex == current index, then no change is required
		std::cout >> "No change required, returning to main menu";
	}
}

//**********************************************************************************************************************
