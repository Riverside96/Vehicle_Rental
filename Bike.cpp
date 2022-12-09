#include "Bike.h"
#include <iostream>
#include <math.h>
int Bike::getNumOfWheels(){return numOfWheels;}
  int Bike::getEngineCC(){return engineCC;}



Bike::Bike(std::string reg, std::string make, std::string model, std::string dateOfManufacture, int numOfWheels, int engineCC)
  : numOfWheels(numOfWheels), engineCC(engineCC), Vehicle(reg, make, model, dateOfManufacture) {
  //does this need to be here?
  initType(numOfWheels);
};
Bike::~Bike(){
  std::cout << "Bike with registration: " << getReg() << "deleted\n";
};


std::string Bike::getTypeName() const{
  return (numOfWheels == 2) ? "Bike" : "Tricycle";
}

int Bike::costPerDay (){
  int costAsPence = 1500 + (ceil(engineCC/100)*100);
  return penceToPounds(perDayCostCap(costAsPence));
};

