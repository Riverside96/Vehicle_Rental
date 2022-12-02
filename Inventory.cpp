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
#include <map>
#include <memory>
#include <vector> 
#include <memory.h>
#include <cmath>
#include <filesystem>

void Inventory::display(){
}


void Inventory::search(std::string vehType, int optMod){
  
  // checkKeyExists()
  // if(inputModif=="Car"){
  // }
};


void Inventory::remove(std::string regToDelete){
    // auto it = mapVehiclesByReg[regToDelete];
    // if(it->getTypeName() == "Car")
    Serializer::deleteFile(regToDelete);
    mapVehiclesByReg.erase(regToDelete);
};

  bool Inventory::checkKeyExists(std::string reg) const{
   return (mapVehiclesByReg.contains(reg)) ? 1 : 0; 
}; 

  std::vector<std::shared_ptr<Vehicle>>  Inventory::sort(std::string mod) const{
  std::vector<std::shared_ptr<Vehicle>> aux;
  aux.reserve(mapVehiclesByReg.size());
  std::transform(mapVehiclesByReg.begin(), mapVehiclesByReg.end(), std::back_inserter(aux),
    [](std::pair<std::string, std::shared_ptr<Vehicle>> const &p) {return p.second;});

  if (mod == "reg") { std::sort(aux.begin(), aux.end(), compareReg);}
  if (mod == "costPD") {std::sort(aux.begin(), aux.end(), compareCostPD);}
  return aux;
    }

  void Inventory::displayRegCostPerDayNType(std::vector<std::shared_ptr<Vehicle>> aux) const{
      for (const auto& key : aux) {
      std::cout << key->getReg()
                << "               "
                << "£"<<key->costPerDay()
                << "            "
                << key->getTypeName() << "\n";
  }
};   
  void Inventory::add(std::shared_ptr<Vehicle> vehicle) {
    mapVehiclesByReg[vehicle -> getReg()] = std::move(vehicle);
};

  void Inventory::addValidModel(std::string make, std::list<std::string> model){
    mapValidMakesModels.insert({make, model});
};
  void Inventory::printValidModelMap(){
    for(auto key : mapValidMakesModels){
      std::cout << "make: "<<key.first << " models:";
    for(auto value : key.second){
      std::cout << value << ", ";
    }
    std::cout << "\n";  
  }
}

  bool Inventory::isMakeInMap(std::string make){
    return mapValidMakesModels.contains(make) ? true : false; 
};
  bool Inventory::isModelInMap(std::string make, std::string model){
    for (auto value=mapValidMakesModels[make].begin(); value != mapValidMakesModels[make].end(); ++value){
      if (*value == model) break;
      return 0;
  }
    return 1;
};

  std::string Inventory::didYouMeanMake(std::string make){
    int tracker = make.length()+3;
    std::string lowestLeven;

    for (auto key : mapValidMakesModels){
    if (InputValidators::levenshteinDistance(key.first, make) < tracker){
      tracker = (InputValidators::levenshteinDistance(key.first, make));
      lowestLeven = key.first;
    }
  }   
  return lowestLeven;
};
  std::string Inventory::didYouMeanModel(std::string make, std::string model){
    int tracker = model.length()+3;
    std::string lowestLeven;
    for (auto value=mapValidMakesModels[make].begin(); value != mapValidMakesModels[make].end(); ++value){
      if(InputValidators::levenshteinDistance(*value, model) < tracker){
        tracker = (InputValidators::levenshteinDistance(*value, model));
        lowestLeven = *value;
    }
  }
  return lowestLeven;
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



