// INVENTORY HAS A QUESTION CLASS
// INVENTORY HAS A SERIALIZER
#pragma once 
#include "Inventory.h"
#include <list>

class Menu{
public:

  static void enterReg(std::string &registration, std::string &answer);
  static void enterManufactureDate(std::string &dateOfManufacture);
  static void enterVehicleType(std::string &vehicleType, std::string &answer);
  static void enterDoors(int &numOfDoors);
  static void enterWheels(int &numOfWheels);
  static void enterEngineSize(int &engineCC);
  static void enterMake(std::string &make, auto &inventory, std::string &answer);
  static void enterMake(char* make, auto &inventory, std::string &answer);

  static void enterModel(std::string &make, std::string &model, std::string &answer, auto &inventory);
  static void enterSeats(int &seats);

  static void displayOptions();
  static void addVehicle(std::shared_ptr<Inventory> inventory);
  static void removeVehicle(std::shared_ptr<Inventory> inventory);
  static void search(std::shared_ptr<Inventory> inventory, std::string mod);
  // static void searchForBike(std::shared_ptr<Inventory> Inventory); 
  static void sortByRegistration(std::shared_ptr<Inventory> inventory);
  static void sortByCostPerDay(std::shared_ptr <Inventory> inventory);  
  static void exit(std::shared_ptr<Inventory> inventory);

private:
// should maybe change from const when we have a way for admin to change it 
  // add a mutatable in the admin sect
  static inline constexpr int OLDEST_VALID_VEHICLE_YYYY = 1940;
  void deciderReset(std::string &decider);
  static bool isDeciderValid(std::string decider);
  static bool isDeciderValid(char *decider);
  static void decide();
  static void complain();
  static bool validateReg(std::string input) ;
  static int getYear();
  static std::string dateIntsToString(int day, int month, int year); 
  static bool checkMakeInDatabase(std::string make);
  static bool checkModelInDatabase(std::string model);

  static inline std::list<Vehicle*> vehicleList;
  static inline std::list<Vehicle*>::iterator vehicleListIterator;

  static void SerializeSave();
  };
