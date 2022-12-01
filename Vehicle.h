#pragma once
 #include <ostream>
#include <sstream>
class Vehicle {

  friend std::ostream& operator<<(std::ostream& os, const Vehicle& v){
  v.serialize(os);
  return os;
}

public:
  Vehicle(std::string reg, std::string make, std::string model, std::string dateOfManufacture);
  virtual ~Vehicle() = default;
  virtual double costPerDay() = 0 ;
  std::string getReg() const;
  std::string getMake() const;
  std::string getModel() const;
  std::string getDateOfManufacture() const;
  int getAge();
  virtual std::string getTypeName() const = 0; 

  // static bool compareReg(const Vehicle& lhs, const Vehicle& rhs){
  //   return lhs.reg < lhs.reg;
  //   
  // }
  // 

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
  // I think this must be non const to allow for init type func. This breaks encapsulation, how to fix?
  std::string type;
  std::string const reg, make, model, dateOfManufacture;  
  //char make[];
};

// have a map of valid car names, .... did you mean toyota?

