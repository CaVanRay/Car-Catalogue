#pragma once


//**********************************************************************************************************************

/*
Class car: Represents a car object with various attributes such as owner, model, VIN, mileage, MPG, price, and availability status.
*/

class car {
private:
    int index;
    std::string Owner;
    std::string Model;
    std::string Vin;
    int Mileage;
    int MPG;
    int Price;
    bool ForSale;
    car* Prev = nullptr;
    car* Next = nullptr;
public:
    // First the Setters
    void SetIndex(int newIndex) {
        index = newIndex;
    }
    void SetOwner(std::string newOwner) {
        Owner = newOwner;
    };
    void SetModel(std::string newModel) {
        Model = newModel;
    };
    void SetVin(std::string newVin) {
        Vin = newVin;
    };
    void SetMileage(int newMileage) {
        Mileage = newMileage;
    };
    void SetMPG(int newMPG) {
        MPG = newMPG;
    };
    void SetPrice(int newPrice) {
        Price = newPrice;
    };
    void SetSale(bool newSale) {
        ForSale = newSale;
    };
    void SetPrev(car* newPrev) {
        Prev = newPrev;
    };
    void SetNext(car* newNext) {
        Next = newNext;
    };
    // Next the Getters
    int GetIndex() {
        return index;
    }
    std::string GetOwner() {
        return Owner;
    };
    std::string GetModel() {
        return Model;
    };
    std::string GetVin() {
        return Vin;
    };
    int GetMileage() {
        return Mileage;
    };
    int GetMPG() {
        return MPG;
    };
    int GetPrice() {
        return Price;
    };
    bool GetSale() {
        return ForSale;
    };
    car* GetPrev() {
        return Prev;
    };
    car* GetNext() {
        return Next;
    };
};

//**********************************************************************************************************************