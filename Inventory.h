// INVENTORY HAS A QUESTION CLASS
// INVENTORY HAS A SERIALIZER
#pragma once 
#include <fstream>
#include "Vehicle.h"
#include <map>
#include <memory>
class Inventory{
public:
  void add(std::unique_ptr<Vehicle> v) ;
  void search(); 
  void sort();
  void serialize(std::ostream& file) const;
  void deserialize(std::istream& file);
  void save();
private:
  std::map<std::string, std::unique_ptr<Vehicle>> mapVehiclesByReg;
  std::ofstream file;
  };
