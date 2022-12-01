#pragma once
#include "Inventory.h"
#include <memory>
class Serializer{
public:
  static void serialize(std::unordered_map<std::string, std::shared_ptr<Vehicle>> mapVehiclesByReg);
  static void read(std::shared_ptr<Inventory> inventory);
  static void deleteFile(std::string file);
};
