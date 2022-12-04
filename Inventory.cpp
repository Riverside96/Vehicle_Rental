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
#include <ostream>
#include <sys/select.h>
#include <unistd.h>
#include <vector> 
#include <memory.h>
#include <cmath>
#include <filesystem>


void Inventory::search(std::string &vehType, int opt, int optInt,std::string &optStr, std::shared_ptr<Inventory> inv) {
  std::vector<std::shared_ptr<Vehicle>> unMap;

  
  std::vector<std::shared_ptr<Vehicle>> aux;
  aux.reserve(mapVehiclesByReg.size());
  for (const auto& [k, v] : mapVehiclesByReg){
    if (vehType == "car"){
      // casting is the issue I think
      // auto temp = std::dynamic_pointer_cast<Car>(v);
      std::shared_ptr<Car> temp = static_pointer_cast<Car>(v);
      switch (opt){
        case 1:
          if (v->getReg() == optStr){
            aux.push_back(v);
            } break;
        case 2:
          if (temp->getSeats() == optInt){
            aux.push_back(v); 
            } break;
        case 3: 
          if (temp->getDoors() == optInt){
            aux.push_back(v);
          } break;
      }   
    }else {
      std::shared_ptr<Bike> temp = std::static_pointer_cast<Bike>(v);
      switch (opt){
        case 1: 
          if (v->getReg() == optStr){
          aux.push_back(v);
        } break;
        case 2:
          if (temp->getEngineCC() == optInt){
            aux.push_back(v);
          } break;
        case 3:
          if (temp->getNumOfWheels() == optInt){
            aux.push_back(v);
          } break;
      }    
    }
  }

  if(!aux.empty()){
    std::cout << "list of cars matching that search:\n\n"
            << "Registration Number   Cost Per Day   Make    Model\n"
            << "-------------------   ------------   ----    -----\n";

    int i(1);
    for(const auto& veh : aux){
      std::cout << i <<"  ";
      display(veh, "reg");
      std::cout <<"              ";
      display(veh, "costPD");
      std::cout <<"    ";
      display(veh, "make");
      std::cout <<"     ";
      display(veh, "model");
      std::cout<<"\n";
      ++i;
    }

    int select;
    bool broke(0);
    do{
    std::cin.ignore();
    std::cin >> select;
    if(select>=1 && select <=i){
        broke=1;
        break;
      }else std::cout<<"out of range";
    } while (!broke);

    std::cout<< "\n\n\n\n\n\n\n\n";
    rentalDash(aux[select-1]->getReg(), inv);

  } else {
    std::cout << "No matches found\n"
              << "Press any key to return to main menu";
    std::cin.ignore();
    std::cin.get();



  }
    

};

  void Inventory::rentalDash(std::string reg, std::shared_ptr<Inventory> inv){
   std::cout << "Cost Per Day:           £";
   display(mapVehiclesByReg[reg], "costPD");
   std::cout << "\n";
   std::cout << "Total Rental Income";
   std::cout << "\n";
   std::cout << "Total Days Rented\n\n"

   << "1) Rent Vehicle\n"
   << "2) View historic rentals"
   << "9) Return to main menu\n\n"
   << "Please choose an option: ";

  int opt;
  bool broke(0);
  do{
    std::cin >> opt;
    if(opt==1 || opt==2 || opt ==9){
      broke = 1;
      break;
    }else {
      std::cout << "invalid input";
    }
  } while(!broke);

  switch(opt){
    case 1:
      rentVehicle(reg, inv);
      break;
    case 2:
      viewRentals(reg);
      break;
    case 9:
      return;
  }


}

  
  void Inventory::rentVehicle(std::string &reg, std::shared_ptr<Inventory> inv){
  std::string fName, lName, address; 
  int contact;
  std::cout << "\nEnter customers first name: ";
  std::cin >> fName;
  std::cout << "\nEnter customers last name: "; 
  std::cin >> lName;
  std::cout <<"\nEnter customers address: ";
  std::cin >> address;
  std::cout << "Enter customers contact number: ";
  std::cin >> contact;
  
  mapVehiclesByReg[reg]->startLease(fName, lName, address, contact);
  
        

}

  void Inventory::viewRentals(std::string  &reg){
  
}




  // use function pointers for this later, perfect excuse
  void Inventory::display(const std::shared_ptr<Vehicle> &veh, const std::string opt) const{
    if (opt == "reg") {std::cout<< veh->getReg();}
    if (opt == "costPD"){std::cout<< veh->costPerDay();}
    if (opt == "make"){std::cout<<veh->getMake();}
    if (opt == "model"){std::cout<< veh->getModel();}
    }
  

  //   std::vector<std::shared_ptr<Vehicle>> filtered;
  // unMap.reserve(mapVehiclesByReg.size());
  //      std::transform(mapVehiclesByReg.begin(), mapVehiclesByReg.end(), std::back_inserter(unMap),
  //       [](std::pair<std::string, std::shared_ptr<Vehicle>> const &p) {return p.second;});
  //       
  // if(opt==1){
  //   for(auto v : unMap){
  //     if(v->getReg().compare(optStr)){
  //       std::cout << "1)" 
  //                 << v->getReg() <<"        "
  //                 << v->costPerDay()<<"        "
  //                 << v->getMake()<<"         "
  //                 << v->getModel();
  //     }
  //   } 
  //   }else
  //   filtered.reserve(unMap.size());
  //     std::copy_if(mapVehiclesByReg.begin(), mapVehiclesByReg.end(), std::back_inserter(aux),
  //                  [&vehType, opt, optInt](std::pair<std::string, std::shared_ptr<Vehicle>>  &kv) {
  //                     if (vehType == "car"){
  //                       if (opt==2){
  //                         if(auto derived = std::dynamic_pointer_cast<Car>(kv.second)){
  //                           if(derived->getSeats()==optInt){
  //                           return kv.second;  
  //                          }
  //                         }
  //                      }else {
  //                        if(auto derived = std::dynamic_pointer_cast<Car>(kv.second)){
  //                          if(derived->getDoors()==optInt){
  //                            return kv.second;
  //                          }
  //                        }

  //                      }

  //                 
  //                  }
  //                    return 0;
  //     }

  // checkKeyExists()
  // if(inputModif=="Car"){
  // }
                 

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

  // if default jump to return?
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
}; 



