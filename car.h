#pragma once
#include "vehicle.h"
class car: public vehicle {
public:
  car(int numOfDoors, string reg, string make, string model, int age);
  ~car();
  double costPerDay(); 
private:
  int numOfDoors = 2;
};
