#include "Car.h"
#include "HistoryInstance.h"
#include "Serializer.h"
#include "dateHelpers.h"
#include "Vehicle.h"
#include <utility>

Vehicle::Vehicle(std::string reg, std::string make, std::string model, std::string dateOfManufacture)
:reg(reg), make(make), model(model), dateOfManufacture(dateOfManufacture){}

std::string Vehicle::getReg() const {return reg;}
std::string Vehicle::getMake() const {return make;}
std::string Vehicle::getModel() const {return model;}
std::string Vehicle::getDateOfManufacture()const {return dateOfManufacture;}

void Vehicle::initType(){type = "car";}
void Vehicle::initType(int numOfWheels){
    std::string tricOrBic = (numOfWheels == 2) ? "bicicle" : "tricicle";
    type = tricOrBic;
  }
// needs to change. If both dates are first of july, 
// it depends on whether the date of manufacture is before or after
// first 1st of july
int Vehicle::getAge(){
  return (dateHelpers::getYear()) - (dateHelpers::getYearFromDateString(dateOfManufacture));
};
void Vehicle::startLease(std::string &fName, std::string &Lname, int houseNum, std::string &address, std::string &contact){
  Serializer::serialize(std::make_unique<HistoryInstance>(reg, fName, Lname, houseNum, address, contact));
  // std::cout << this->reg;
};
void Vehicle::endLease(){
};
int Vehicle::perDayCostCap(int costPD){costPD = (costPD<1000) ? costPD : 1000; return costPD;}
double Vehicle::penceToPounds(int pence){return (double)pence/100;};


