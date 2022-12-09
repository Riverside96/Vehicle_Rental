#pragma once
#include "Vehicle.h"
class Bike: public Vehicle {


 virtual void serialize(std::ostream &os) const override {
    Vehicle::serialize(os);
    os << "Wheels: " << numOfWheels << " "
       << "CC: " << engineCC << "\n";
  }


public:
  Bike(std::string reg, std::string make, std::string model, std::string dateOfManufacture, int numOfWheels, int engineCC);
  ~Bike();

  int getNumOfWheels();
  int getEngineCC();
  int costPerDay() override;


  std::string getTypeName() const override;


private:
  const int numOfWheels;
  const int engineCC;
};
