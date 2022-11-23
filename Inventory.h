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
using namespace std;
class Inventory{
public:
  static void addVehicle();
  static void searchForCar();
  static void searchForBike(); 
  static void sortByRegistration();
  static void sortByCostPerDay();  
  static void exit();



private:

// should maybe change from const when we have a way for admin to change it 
  static inline constexpr int OLDEST_VALID_VEHICLE_YYYY = 1940;
  void deciderReset(string &decider);
  static bool isDeciderValid(string decider);
  static bool isDeciderValid(char *decider);
  static void decide();
  static void complain();
  static bool validateReg(string input) ;
  static int getYear();
  static bool checkdate(int d, int m, int y);
  static string dateIntsToString(int day, int month, int year); 
  static bool checkMakeInDatabase(string make);
  static bool checkModelInDatabase(string model);



  static inline list<Vehicle*> vehicleList;
  static inline list<Vehicle*>::iterator vehicleListIterator;

  static void SerializeSave();

  };



static inline unordered_map<string, list<Vehicle*>> vehicleMap;
static inline map< string, unique_ptr<Car>> carMap;
static inline map<string, unique_ptr<Car>>::iterator carMapIterator = carMap.begin();



// decltype(vehicleMap)::iterator vehicleMapOuterIt;


