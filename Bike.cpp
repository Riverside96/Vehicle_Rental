#include "Bike.h"
#include "Vehicle.h"
#include <iostream>
#include <cmath>
using namespace std;

  int Bike::getNumOfWheels(){return numOfWheels;}
  int Bike::getEngineCC(){return engineCC;}



Bike::Bike(string reg, string make, string model, string dateOfManufacture, int numOfWheels, int engineCC)
  : numOfWheels(numOfWheels), engineCC(engineCC), Vehicle(reg, make, model, dateOfManufacture) {
  //does this need to be here?
  initType(numOfWheels);
};
Bike::~Bike(){};

double Bike::costPerDay (){
  int costAsPence = 1500 + (ceil(engineCC/100)*100);
  return penceToPounds(perDayCostCap(costAsPence));
};
