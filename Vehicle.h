#pragma once
 #include <ostream>
#include <sstream>
#include <list>
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

  void startLease(std::string &fName, std::string &Lname, std::string &address, int contact);
  void endLease();


    struct HistoryInstance{
    HistoryInstance(std::string fName, std::string lName, std::string address, int contact);
    // ~HistoryInstance();
    std::string leaseStart, leaseEnd, fName, lName, address, contact;
  };



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
  std::list<Vehicle::HistoryInstance> historyList; 
  
  // class HistoryInstance{
  //   public:
  //     HistoryInstance();
  //     ~HistoryInstance();
  //   private:
  //     std::string leaseStart, leaseEnd, fName, lName, address, contact;
  //     
  // struct HistoryInstance{
  //   HistoryInstance();
  //   ~HistoryInstance();
  //   std::string leaseStart, leaseEnd, fName, lName, address, contact;
  };

// have a map of valid car names, .... did you mean toyota?

