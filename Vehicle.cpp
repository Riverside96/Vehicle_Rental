#include "Car.h"
#include "dateHelpers.h"
#include "Vehicle.h"

Vehicle::Vehicle(std::string reg, string make, string model, string dateOfManufacture)
:reg(reg), make(make), model(model), dateOfManufacture(dateOfManufacture){}

std::string Vehicle::getReg() const {return reg;}
std::string Vehicle::getMake() const {return make;}
std::string Vehicle::getModel() const {return model;}
std::string Vehicle::getDateOfManufacture()const {return dateOfManufacture;}

void Vehicle::initType(){type = "car";}
//get around not bein able to set value in derived class constructor 
void Vehicle::initType(int numOfWheels){
  // if(type != "car"){
    std::string tricOrBic = (numOfWheels == 2) ? "bicicle" : "tricicle";
    type = tricOrBic;
  }
// }
//
// needs to change. If both dates are first of july, 
// it depends on whether the date of manufacture is before or after
// first 1st of july
int Vehicle::getAge(){
  // int currentYr = dateHelpers::getYear();
  // int again = currentYr - dateHelpers::getYearFromDateString(dateOfManufacture);\
  // return again;
  return (dateHelpers::getYear()) - (dateHelpers::getYearFromDateString(dateOfManufacture));
};

int Vehicle::perDayCostCap(int costPD){costPD = (costPD<10000) ? 10000 : costPD; return costPD;}
double Vehicle::penceToPounds(int pence){return (double)pence/100;};
