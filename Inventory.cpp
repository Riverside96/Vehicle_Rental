#include "Inventory.h"
// #include "Car.h"
// #include "dateHelpers.h"
// #include <string>
#include "InputValidators.h"
#include <iostream>
  
  void Inventory::add(std::unique_ptr<Vehicle> vehicle) {
    mapVehiclesByReg[vehicle -> getReg()] = std::move(vehicle);
};

  void Inventory::serialize(std::ostream& file) const {
    for (const auto& [reg, vehicle] : mapVehiclesByReg) {
      file << *vehicle;
      file << "\n";
  }
  // void Inventory::serialize(std::ostream& file) const {
  //   for (const auto& [reg, vehicle] : mapVehiclesByReg) {
  //     file << vehicle->getTypeName() << ' ';
  //     vehicle->serialize(file);
  //     file << "\n";
  // }

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

  // use copy_if here
  // // copy to vec for fast sorting 
  void Inventory::sort(){

  
};


