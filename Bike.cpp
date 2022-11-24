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


ostream& operator<<(ostream &out, Bike& bike){
  out << bike.getReg() << ", " 
      << bike.getMake() << ", " \
      << bike.getModel() <<", "
      << bike.getDateOfManufacture()
      << ", " << bike.numOfWheels << ", "
      << bike.engineCC << endl;
  return out;
};


// void Bike::serialize(std::ostream &file, Bike& bike){file << bike;}



