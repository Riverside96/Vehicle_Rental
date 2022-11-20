#include "dateHelpers.h"
#include "vehicle.h"


vehicle::vehicle(string reg, string make, string model, int age)
:reg(reg), make(make), model(model), age(age){}


string vehicle::getModel(){return model;}
void vehicle::initType(){type = "car";}
//get around not bein able to set value in derived class constructor 
void vehicle::initType(int numOfWheels){
  // if(type != "car"){
    string tricOrBic = (numOfWheels == 2) ? "bicicle" : "tricicle";
    type = tricOrBic;
  }
// }


// needs to change. If both dates are first of july, 
// it depends on whether the date of manufacture is before or after
// first 1st of july
int vehicle::getAge(){
  // int currentYr = dateHelpers::getYear();
  // int again = currentYr - dateHelpers::getYearFromDateString(dateOfManufacture);\
  // return again;
  return (dateHelpers::getYear()) - (dateHelpers::getYearFromDateString(dateOfManufacture));
};



int vehicle::perDayCostCap(int costPD){costPD = (costPD<10000) ? 10000 : costPD; return costPD;}
double vehicle::penceToPounds(int pence){return (double)pence/100;};
