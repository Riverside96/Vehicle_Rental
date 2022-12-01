// INVENTORY HAS A QUESTION CLASS
// INVENTORY HAS A SERIALIZER
#pragma once 
#include <algorithm>
#include <fstream>
#include "Vehicle.h"
#include <unordered_map>
#include <map>
#include <memory>
#include <vector>
#include <list>
class Inventory{
public:
  void display();
  void add(std::shared_ptr<Vehicle> v) ;

  void addValidModel(std::string make, std::list<std::string> model);
  void printValidModelMap();
  bool isMakeInMap(std::string make);
  bool isModelInMap(std::string make, std::string model);
  std::string didYouMeanMake(std::string make);
  std::string didYouMeanModel(std::string make, std::string model);

  void search() const; 
   std::vector<std::shared_ptr<Vehicle>>  sort(std::string mod = "0") const;
  // void serialize(std::ostream& file) const;
  void save() const;
  bool checkKeyExists(std::string reg) const; 
  void remove(std::string regToDelete);
  static  bool compareReg(const std::shared_ptr<Vehicle> lhs, const std::shared_ptr<Vehicle> rhs) {
    return lhs->getReg() < rhs->getReg();
  }
  static  bool compareCostPD(const std::shared_ptr<Vehicle> lhs, const std::shared_ptr<Vehicle> rhs){
    return lhs->costPerDay() < rhs->costPerDay();
  }
  void displayRegCostPerDayNType(std::vector<std::shared_ptr<Vehicle>> aux) const;
private:
  std::unordered_map<std::string, std::shared_ptr<Vehicle>> mapVehiclesByReg;
  std::map<std::string, std::list<std::string>> mapValidMakesModels;
  std::ofstream file;
  };
