#include "Inventory.h"
#include "InputValidators.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector> 
#include <memory.h>
  void Inventory::remove(std::string regToDelete){
    mapVehiclesByReg.erase(regToDelete);
};

  
  bool Inventory::checkKeyExists(std::string reg){
   return (mapVehiclesByReg.contains(reg)) ? 1 : 0; 
}; 

 
  void Inventory::sort(std::string mod){
  std::vector<std::shared_ptr<Vehicle>> aux;
  // std::copy_if(mapVehiclesByReg.begin(), mapVehiclesByReg.end(), aux.begin(), ())
  //

  aux.reserve(mapVehiclesByReg.size());
  std::transform(mapVehiclesByReg.begin(), mapVehiclesByReg.end(), std::back_inserter(aux),
    [](std::pair<std::string, std::shared_ptr<Vehicle>> const &p) {return p.second;});


  if (mod == "reg") { std::sort(aux.begin(), aux.end(), compareReg);}
  if (mod == "costPD") {std::sort(aux.begin(), aux.end(), compareCostPD);}
  for (const auto& v : aux) {
    std::cout << *v;
  }
 }

  void Inventory::displayRegCostPerDayNType() const{
    for (const auto& [reg, vehicle] : mapVehiclesByReg) {
    std::cout << vehicle->getReg();
    std::cout << "               ";
    std::cout << "£"<<vehicle->costPerDay();
    std::cout << "            ";
    std::cout << vehicle->getTypeName() << "\n";
  }
};   
  void Inventory::add(std::shared_ptr<Vehicle> vehicle) {
    mapVehiclesByReg[vehicle -> getReg()] = std::move(vehicle);
};
  void Inventory::serialize(std::ostream& file) const {
    for (const auto& [reg, vehicle] : mapVehiclesByReg) {
      file << vehicle->getTypeName(); 
      file << *vehicle;
      file << "\n";
  }
};
  void Inventory::deserialize(std::istream& file) {} ;

  void Inventory::save(){
  file.open("test.txt", std::ios_base::out | std::ios_base::trunc);
  if(file.is_open()){
    serialize(file);
    file.close();
   } else {
    std::cout << "Could not save as database could not be found";
  }
}
  // finish tmoz. Too tired
  void Inventory::search(){
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



  


