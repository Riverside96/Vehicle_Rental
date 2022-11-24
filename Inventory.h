// INVENTORY HAS A QUESTION CLASS
// INVENTORY HAS A SERIALIZER
#pragma once 
#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"
#include <list>
#include <ostream>
#include <regex>
#include <string>
#include <unordered_map>
class Inventory{
public:
  void add(std::unique_ptr<Vehicle> v);
  void search(); 
  void sort();
  void serialize(std::ostream& file) const;
  void deserialize(std::istream& file);


private:

  std::map<std::string, std::unique_ptr<Vehicle>> mapVehiclesByReg;

  };



// static inline unordered_map<string, list<Vehicle*>> vehicleMap;
// static inline map<string, unique_ptr<Car>> carMap;
// static inline map<string, unique_ptr<Car>>::iterator carMapIterator = carMap.begin();



// decltype(vehicleMap)::iterator vehicleMapOuterIt;


