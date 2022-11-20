#include "bike.h"
#include "vehicle.h"
#include <iostream>
#include <cmath>



bike::bike(int engineCC, int numOfWheels, string reg, string make, string model, int age)
  :engineCC(engineCC), numOfWheels(numOfWheels), vehicle(reg, make, model, age) {
  initType(numOfWheels);
};
bike::~bike(){};

double bike::costPerDay (){
  int costAsPence = 1500 + (ceil(engineCC/100)*100);
  return penceToPounds(perDayCostCap(costAsPence));
};


