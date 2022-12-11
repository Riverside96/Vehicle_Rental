#include "Inventory.h"
#include "Bike.h"
#include "Car.h"
#include "HistoryInstance.h"
#include "InputValidators.h"
#include "Serializer.h"
#include <algorithm>
#include <dirent.h>
#include <ios>
#include <iostream>
#include <iterator>
#include <memory>
#include <ostream>
#include <string>
#include <sys/select.h>
#include <unistd.h>
#include <vector> 
#include <memory.h>
#include <cmath>
#include <filesystem>



void Inventory::addCurrentlyLeased(std::string &reg){
  currentlyLeased.insert(reg);
};
void Inventory::removeCurrentlyLeased(std::string &reg){
  currentlyLeased.erase(reg);
};
bool Inventory::checkIfCurrentlyLeased(std::string &reg){
  return currentlyLeased.contains(reg) ? true : false;
};


void Inventory::addHasHistory(std::string &reg){
  hasHistorySet.insert(reg);
};
void Inventory::printHasHistory(){
  for(auto reg : hasHistorySet){
    std::cout << reg << "\n";
  }
}
bool Inventory::checkHasHistory(std::string &reg){
  return hasHistorySet.contains(reg) ? true : false;
}
double Inventory::getCostPerDay(std::string &reg){
  return mapVehiclesByReg[reg]->costPerDay();
}
void Inventory::search(std::string &vehType, int opt, int optInt,std::string &optStr, std::shared_ptr<Inventory> inv) {
  std::vector<std::shared_ptr<Vehicle>> unMap;
  std::vector<std::shared_ptr<Vehicle>> aux;
  aux.reserve(mapVehiclesByReg.size());
  for (const auto& [k, v] : mapVehiclesByReg){
    if (vehType == "car"){
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
          std::cout <<  temp->getDoors();
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

  if(aux.empty()){
    std::cout << "No matches found\n"
              << "Press any key to return to main menu";
    std::cin.ignore();
    std::cin.get();
  } else {
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
  Serializer::readHistorySet(inv);
  Serializer::readCurrentlyLeasedSet(inv);
    rentalDash(aux[select-1]->getReg(), inv);

  } 
};

//================================================================================//
  void Inventory::rentalDash(std::string reg, std::shared_ptr<Inventory> inv){
  // Serializer::readHistorySet(inv);
  // Serializer::readCurrentlyLeasedSet(inv);
  bool stopCall(0);
  do{

  int totalRentDays(0), totalRentCost(0);
    
    if(checkHasHistory(reg)){
    std::cout << checkHasHistory(reg);
   int storeSize;
   HistoryInstance** historyStore = Serializer::read(reg, storeSize, inv);
   totalRentDays = (*historyStore[0]).getTotalRentalDays();
   totalRentCost = (*historyStore[0]).getTotalRentalCost();
  for(int i=0; i < storeSize; i++){
    delete historyStore[i];
    }
    delete[] historyStore;
    historyStore = nullptr;
  }

 
  std::cout<< "\n\n\n\n\n\n\n\n";
  std::string title =  reg + ": " + mapVehiclesByReg[reg]->getMake() + " " + mapVehiclesByReg[reg]->getModel();
  std::cout <<  title << "\n";
  for(int i = 0; i < title.length(); i++){std::cout << "-";}

   std::cout << "\nCost Per Day:           £";
   std::cout << mapVehiclesByReg[reg]->costPerDay() << "\n";

   std::cout << "Total Rental Income:    £"<<totalRentCost<<"\n";
   std::cout << "Total Days Rented:      "<<totalRentDays<<"\n";
  
  if (!checkIfCurrentlyLeased(reg)){
  std::cout << "\n\n1) Rent Vehicle\n";
  } else {
    std::cout << "\n\n1) End Vehicle Lease\n";
  }

  std::cout << "2) View historic rentals\n"
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

      if (!checkIfCurrentlyLeased(reg)){
        rentVehicle(reg, inv);
      } else {
        unRentVehicle(reg, inv);
      }
      break;
    case 2:
      if(checkHasHistory(reg)){
      viewRentals(reg, inv, stopCall);
      } else {
        std::cout << "No history to display. Press any key to return to menu";
        std::cin.ignore();
        std::cin.get();
        return;
      }
      break;
    case 9:
      return;
    }
  }while (stopCall==(0));
}

  void Inventory::rentVehicle(std::string &reg, std::shared_ptr<Inventory> inv){
  std::string fName, lName, address, contact;
  int houseNum;
  std::cout << "\nEnter customers first name: ";
  std::cin >> fName;
  std::cout << "\nEnter customers last name: "; 
  std::cin >> lName;
  std::cout <<"\nEnter house number: ";
  std::cin >> houseNum;
  std::cout <<"\nEnter customers address number: ";
  std::cin.ignore();
  std::getline(std::cin, address);
  std::cout << "\nEnter customers contact number: ";
  std::cin >> contact;

  mapVehiclesByReg[reg]->startLease(fName, lName, houseNum, address, contact);
  hasHistorySet.insert(reg);
  addCurrentlyLeased(reg);
   Serializer::writeHistorySet(hasHistorySet);
   Serializer::writeCurrentlyLeasedSet(currentlyLeased);
}

  void Inventory::unRentVehicle(std::string &reg, std::shared_ptr<Inventory> inv){
    
    Serializer::setLeaseEndDate(reg);
    removeCurrentlyLeased(reg);
    Serializer::writeCurrentlyLeasedSet(currentlyLeased);
    // need more logic for changing NA to current date. 
  
  }



//================================================================================//
  void Inventory::viewRentals(std::string &reg, std::shared_ptr<Inventory> inv, bool &stopCall){
    if(checkHasHistory(reg)){
    std::cout << checkHasHistory(reg);
   int storeSize;
   HistoryInstance** historyStore = (Serializer::read(reg, storeSize, inv));
   int current(0);
   bool thisLoopStop=0;
  do{
    
  std::cout<< "\n\n\n\n\n\n\n\n";
  std::string title =  reg + ": " + mapVehiclesByReg[reg]->getMake() + " " + mapVehiclesByReg[reg]->getModel();
  std::cout <<  title << "\n";
  for(int i = 0; i < title.length(); i++){std::cout << "-";} std::cout << "\n";

  int opt;
  std::cout 
    <<"Rental:                "<<current+1<<" of "<<storeSize<<"\n"
    <<"Date From:             "<<(*historyStore[current]).getLeaseStart() <<"\n"
    <<"Date To:               "<<(*historyStore[current]).getLeaseEnd() <<"\n"
    <<"Total Cost:            "<<(*historyStore[current]).getTotalRentalCost() <<"\n"
    <<"Customer Name          "<<(*historyStore[current]).getName() <<"\n"
    <<"Customer Address       "<<(*historyStore[current]).getAddress() <<"\n"
    <<"Customer Number        "<<(*historyStore[current]).getContact() << "\n\n"
    << "1) View the next record\n"
    << "2) View the previous record\n"
    << "9) Return to the vehicle information screen\n\n"
    << "Please Choose an option: ";
    std::cin >> opt;
    switch(opt){
      case 1: 
      if(current<storeSize-1){current++;}
      continue;
    case 2: 
      if(current>0){current--;}
      continue;
    case 9:
       for(int i=0; i < storeSize; i++){
    delete historyStore[i];
    }
    delete[] historyStore;
    historyStore = nullptr;
    
    thisLoopStop=true;
    }
    
       
  }  while (thisLoopStop==0);
}
}
//================================================================================//








  // use function pointers for this later, perfect excuse
  void Inventory::display(const std::shared_ptr<Vehicle> &veh, const std::string opt) const{
    if (opt == "reg") {std::cout<< veh->getReg();}
    if (opt == "costPD"){std::cout<< veh->costPerDay();}
    if (opt == "make"){std::cout<<veh->getMake();}
    if (opt == "model"){std::cout<< veh->getModel();}
    }
  
void Inventory::remove(std::string regToDelete){
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
