#pragma once
using namespace std;
#include <string>
#include <iostream>
class vehicle {
public:
  vehicle(string reg, string make, string model, int age);
  virtual ~vehicle() = default;
  virtual double costPerDay() = 0 ;
  string getModel();
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
  string type;
  string const reg, make, model, dateOfManufacture;  
  //char make[];
};

// have a map of valid car names, .... did you mean toyota?
