#pragma once
#include <memory>
#include "HistoryInstance.h"
// #include <memory.h>
class Vehicle {
  friend std::ostream& operator<<(std::ostream& os, const Vehicle& v){
  v.serialize(os);
  return os;
}
public:
  Vehicle(std::string reg, std::string make, std::string model, std::string dateOfManufacture);
  virtual ~Vehicle() = default;
  virtual int costPerDay() = 0 ;
  std::string getReg() const;
  std::string getMake() const;
  std::string getModel() const;
  std::string getDateOfManufacture() const;
  int getAge();
  virtual std::string getTypeName() const = 0; 
  void startLease(std::string &fName, std::string &Lname, int houseNum, std::string &address, std::string &contact);
  void endLease();

 protected:
  virtual void serialize(std::ostream& os) const{
    os << "Registration: " << reg << " "
       << "Make: " << make << " "
       << "Model: " << model <<  " "
       << "Manufactured: " << dateOfManufacture << " ";
  }
  int age;
  int perDayCostCap(int costPD);
  double penceToPounds(int pence);
  int calculateAge();
  void initType(int numOfWheels);
  void initType();
private:

  std::string type;
  std::string const reg, make, model, dateOfManufacture;  
  std::shared_ptr<HistoryInstance> tempHistoryStore;
  };

