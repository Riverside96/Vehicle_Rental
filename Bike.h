#pragma once
#include "Vehicle.h"
class Bike: public Vehicle {



public:
  Bike(std::string reg, std::string make, std::string model, std::string dateOfManufacture, int numOfWheels, int engineCC);
  ~Bike();

  int getNumOfWheels();
  int getEngineCC();


  double costPerDay();

private:
  const int numOfWheels;
  const int engineCC;
};
