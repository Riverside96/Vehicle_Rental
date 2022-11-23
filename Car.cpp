#include "Car.h"
#include <iostream>
using namespace std;

Car::Car(int numOfDoors, int numOfSeats, string reg, string make, string model, string dateOfManufacture)
:numOfDoors(numOfDoors), Vehicle(reg, make, model, dateOfManufacture){initType();}
Car::~Car(){};



ostream& operator<<(ostream &out, Car& car){
  out << car.getReg() << ", " 
      << car.getMake() << ", " \
      << car.getModel() <<", "
      << car.getDateOfManufacture()
      << ", " << car.numOfDoors << ", "
      << car.numOfSeats << endl;
  return out;

}

double Car::costPerDay(){
  int costAsPence = 250 - (age*150) - (numOfDoors*200);
  return penceToPounds(perDayCostCap(costAsPence));
  
};


