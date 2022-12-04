#include "Car.h"
#include <ostream>
// #include "Vehicle.h"
// #include <iostream>

Car::Car(std::string reg, std::string make, std::string model, std::string dateOfManufacture, int numOfDoors, int numOfSeats)
:Vehicle(reg, make, model, dateOfManufacture), numOfDoors(numOfDoors), numOfSeats(numOfSeats) {initType(); }

// Car::Car(int numOfDoors, int numOfSeats, string reg, string make, string model, string dateOfManufacture)
// :numOfDoors(numOfDoors), numOfSeats(numOfSeats), Vehicle(reg, make, model, dateOfManufacture){initType();}


Car::~Car(){
  std::cout << "Car with registration : " << getReg() << "destroyed\n";
};

std::string Car::getTypeName() const {
    return "Car";
  }

int Car::getSeats(){return numOfSeats;}
int Car::getDoors(){return numOfDoors;}



double Car::costPerDay(){
  int costAsPence = 2500 - (age*150) - (numOfDoors*200);
  return penceToPounds(perDayCostCap(costAsPence));
  
};


