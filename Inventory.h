// INVENTORY HAS A QUESTION CLASS
// INVENTORY HAS A SERIALIZER
#pragma once 
#include <algorithm>
#include <fstream>
#include "Vehicle.h"
#include <unordered_map>
#include <memory>
class Inventory{
public:
  void add(std::shared_ptr<Vehicle> v) ;
  void search(); 
  void sort(std::string mod);
  void serialize(std::ostream& file) const;
  void deserialize(std::istream& file);
  void save();
  bool checkKeyExists(std::string reg); 
  void remove(std::string regToDelete);
  // std::shared_ptr<std::map<std::string, std::unique_ptr<Vehicle>>> getMap(); 
  //
  static  bool compareReg(const std::shared_ptr<Vehicle> lhs, const std::shared_ptr<Vehicle> rhs){
    return lhs->getReg() < rhs->getReg();
  }
  static  bool compareCostPD(const std::shared_ptr<Vehicle> lhs, const std::shared_ptr<Vehicle> rhs){
    return lhs->costPerDay() < rhs->costPerDay();
  }



  
  void displayRegCostPerDayNType() const;
private:
  std::unordered_map<std::string, std::shared_ptr<Vehicle>> mapVehiclesByReg;
  std::ofstream file;
  };
