#include "Inventory.h"
#include "Bike.h"
#include "Car.h"
#include "InputValidators.h"
#include "Serializer.h"
#include <algorithm>
#include <dirent.h>
#include <ios>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector> 
#include <memory.h>
#include <cmath>
#include <filesystem>

void Inventory::display(){
  
}

void Inventory::remove(std::string regToDelete){
    // auto it = mapVehiclesByReg[regToDelete];
    // if(it->getTypeName() == "Car")
    Serializer::deleteFile(regToDelete);
    mapVehiclesByReg.erase(regToDelete);
};

  
  bool Inventory::checkKeyExists(std::string reg) const{
   return (mapVehiclesByReg.contains(reg)) ? 1 : 0; 
}; 

 

  // ask sir how to handle it not maintaining it's state after leaving following function
  // it's not destructing as it's displaying. 
  void Inventory::sort(std::string mod) const{
  std::vector<std::shared_ptr<Vehicle>> aux;
  // std::copy_if(mapVehiclesByReg.begin(), mapVehiclesByReg.end(), aux.begin(), ())
  //

  aux.reserve(mapVehiclesByReg.size());
  std::transform(mapVehiclesByReg.begin(), mapVehiclesByReg.end(), std::back_inserter(aux),
    [](std::pair<std::string, std::shared_ptr<Vehicle>> const &p) {return p.second;});


  if (mod == "reg") { std::sort(aux.begin(), aux.end(), compareReg);}
  if (mod == "costPD") {std::sort(aux.begin(), aux.end(), compareCostPD);}
  // for (const auto& v : aux) {
  //   std::cout << *v;
  // }
  // displayRegCostPerDayNType(aux);

  }

  void Inventory::displayRegCostPerDayNType(std::vector<std::shared_ptr<Vehicle>> aux) const{
    // for (const auto& [reg, vehicle] : mapVehiclesByReg) {
    // std::cout << vehicle->getReg();
    // std::cout << "               ";
    // std::cout << "£"<<vehicle->costPerDay();
    // std::cout << "            ";
    // std::cout << vehicle->getTypeName() << "\n";

    for (const auto& key : aux) {
      std::cout << key->getReg();
      std::cout << "               ";
      std::cout << "£"<<key->costPerDay();
      std::cout << "            ";
      std::cout << key->getTypeName() << "\n";
  }
};   
  void Inventory::add(std::shared_ptr<Vehicle> vehicle) {
    mapVehiclesByReg[vehicle -> getReg()] = std::move(vehicle);
};
  void Inventory::save() const{
   Serializer::serialize(mapVehiclesByReg);
}
  // finish tmoz. Too tired
  void Inventory::search() const{
    std::string reg;
    char answer;

    std::cout << "enter the reg of the vehicle you would like to view details of: ";
    do{
      std::cin >> reg;
      if(!InputValidators::validateReg(reg)){
        std::cout << "I can't find that in the database, would you like to try again? [Y/n]";
        std::cin >> answer;
        if(answer == 'n'){return;}
           } 
     }while (!InputValidators::isDeciderValid(answer));
}; 



  


