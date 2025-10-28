#pragma once

//Function declarations for program structure, defined after main function

void saveCatalogue();

void loadCatalogue();

void optionsMenu(car*& head, std::vector<car*>& carCatalogue);

void printCatalogue(car* n);

void printCar(car* n);

car* findCar(car*& head);

void addCar(car*& head, std::vector<car*>& carCatalogue);

void editCar(car* n);

void deleteCar(car*& head, std::vector<car*>& carCatalogue, car* n);
