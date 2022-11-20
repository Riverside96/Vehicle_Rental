#pragma once 
#include <regex>
using namespace std;
#include <string>
class Inventory{
  public:
    static void addVehicle();
      
protected:


private:

// should maybe change from const when we have a way for admin to change it 
static inline constexpr int OLDEST_VALID_VEHICLE_YYYY = 1940;
//inline static const int OLDEST_VALID_VEHICLE_YYYY = 0;
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

  };
