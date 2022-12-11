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
#include <set>
class Inventory{
public:
  void display(const std::shared_ptr<Vehicle> &veh, const std::string opt) const;
  void add(std::shared_ptr<Vehicle> v) ;

  void addValidModel(std::string make, std::list<std::string> model);
  void printValidModelMap();
  bool isMakeInMap(std::string make);
  bool isModelInMap(std::string make, std::string model);
  std::string didYouMeanMake(std::string make);
  std::string didYouMeanModel(std::string make, std::string model);
  double getCostPerDay(std::string &reg);

  void addHasHistory(std::string &reg);
  void printHasHistory();
  bool checkHasHistory(std::string &reg);

  void addCurrentlyLeased(std::string &reg);
  void removeCurrentlyLeased(std::string &reg);
  bool checkIfCurrentlyLeased(std::string &reg);
  void unRentVehicle(std::string &reg, std::shared_ptr<Inventory> inv);

  void search(std::string &vehType, int opt, int optModInt, std::string &optModStr, std::shared_ptr<Inventory> inv);
  
  void rentalDash(std::string reg, std::shared_ptr<Inventory> inv);

  void rentVehicle(std::string &reg, std::shared_ptr<Inventory> inv);
  void viewRentals(std::string &reg, std::shared_ptr<Inventory> inv, bool &stopCall);


  // void search() const; 
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
  std::set<std::string> hasHistorySet;
  std::set<std::string> currentlyLeased;
  std::map<std::string, std::list<std::string>> mapValidMakesModels;
  std::ofstream file;
  };
