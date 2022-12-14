#pragma once
#include "Vehicle.h"
#include <ostream>
#include <iostream>
class Car: public Vehicle {
  virtual void serialize(std::ostream &os) const override {
    Vehicle::serialize(os);
    os << "Seats: " << numOfSeats << " "
       << "Doors: " << numOfDoors << " " <<  "\n";
  }

public:
  Car(std::string reg, std::string make, std::string model, std::string dateOfManufacture, int numOfDoors, int numOfSeats) ;
  ~Car();
  int costPerDay() override; 

  std::string getTypeName() const override;

 int getSeats();
  int getDoors();



private:
  int numOfDoors;
  int numOfSeats;
};
