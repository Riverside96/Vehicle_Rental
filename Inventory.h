// INVENTORY HAS A QUESTION CLASS
// INVENTORY HAS A SERIALIZER
#pragma once 
#include <algorithm>
#include <fstream>
#include "Vehicle.h"
#include <unordered_map>
#include <memory>
#include <vector>
class Inventory{
public:
  void display();
  void add(std::shared_ptr<Vehicle> v) ;
  void search() const; 
  void sort(std::string mod = "0") const;
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
  std::ofstream file;
  };
