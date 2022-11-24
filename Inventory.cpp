#include "Inventory.h"
#include "Car.h"
#include "dateHelpers.h"
#include <bits/ranges_algo.h>
#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <algorithm>
#include <utility>
#include "InputValidators.h"

  void Inventory::add(std::unique_ptr<Vehicle> vehicle) {
    mapVehiclesByReg[vehicle -> getReg()] = std::move(vehicle);
};

  void Inventory::serialize(std::ostream& file) const {
    for (const auto& [reg, vehicle] : mapVehiclesByReg) {
      file << vehicle;
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

















  // finish tmoz. Too tired
  void Inventory::search(){
    string reg;
    char answer;

    cout << "enter the reg of the vehicle you would like to view details of: ";
    do{
      cin >> reg;
      if(!InputValidators::validateReg(reg)){
        cout << "I can't find that in the database, would you like to try again? [Y/n]";
        cin >> answer;
        if(answer == 'n'){return;}
           } 
     }while (!InputValidators::isDeciderValid(answer));
}; 

  // use copy_if here
  // // copy to vec for fast sorting 
  void Inventory::sort(){

  
};


