#include "car.h"
#include <iostream>
using namespace std;

car::car(int numOfDoors, string reg, string make, string model, int age)
:numOfDoors(numOfDoors), vehicle(reg, make, model, age){initType();}
car::~car(){};

double car::costPerDay(){
  int costAsPence = 250 - (age*150) - (numOfDoors*200);
  return penceToPounds(perDayCostCap(costAsPence));
  
};


