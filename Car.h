#pragma once
#include "Vehicle.h"
#include <ostream>
#include <iostream>
class Car: public Vehicle {
public:
  Car(int numOfDoors, int numOfSeats, std::string reg, std::string make, std::string model, std::string dateOfManufacture);
  ~Car();
  double costPerDay(); 


    
  // void serialize(std::ostream &file, Car& car);
  friend std::ostream& operator<<(std::ostream &out, Car& car);
  void serialize(std::ostream& file);
  
//void operator+(ostream &file, Car& car);



// friend std::ostream& operator<<(std::ostream& strm, const car& c){
//   strm << c.numOfDoors << " " << c.reg << " " << c.make << " " << c.model << " " << c.dateOfManufacture;



private:
  int numOfDoors;
  int numOfSeats;
};
