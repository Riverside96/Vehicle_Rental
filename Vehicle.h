#pragma once
#include <string>
#include <iostream>
class Vehicle {
public:
  Vehicle(std::string reg, std::string make, std::string model, std::string dateOfManufacture);
  virtual ~Vehicle() = default;
  virtual double costPerDay() = 0 ;

  std::string getReg();
  std::string getMake();
  std::string getModel();
  std::string getDateOfManufacture();

  int getAge();
protected:
  int age;
  int perDayCostCap(int costPD);
  double penceToPounds(int pence);

  int calculateAge();

  void initType(int numOfWheels);
  void initType();
private:
  // I think this must be non const to allow for init type func. This breaks encapsulation, how to fix?
  std::string type;
  std::string const reg, make, model, dateOfManufacture;  
  //char make[];
};

// have a map of valid car names, .... did you mean toyota?
