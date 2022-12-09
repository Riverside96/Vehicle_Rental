#pragma once
#include "HistoryInstance.h"
#include "Inventory.h"
#include <memory>
class Serializer{
public:
  static void serialize(std::unordered_map<std::string, std::shared_ptr<Vehicle>> mapVehiclesByReg);
  static void serialize(std::unique_ptr<HistoryInstance> historyinstance); 
  static void read(std::shared_ptr<Inventory> inventory);
  static HistoryInstance** read(std::string reg, int &nullHistArrSizeToReturn, std::shared_ptr<Inventory> inv);
  static void deleteFile(std::string file);
};
