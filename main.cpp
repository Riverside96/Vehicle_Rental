#include "Menu.h"
#include <cstdlib>
#include <iostream>
#include <memory>
#include "Serializer.h"
#include "Inventory.h"
#include <ctime>
#include <string>
#include "dateHelpers.h"
void clearScreen(){std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";}
int main(int argc, char *argv[]) {


  // std::cout << dateHelpers::getCurrentDate();
  
  std::string testString = ("AA00 AAA");
  // Serializer::setLeaseEndDate(testString);

  // std::cout << "To start today, make serialize write to the end of the file rather than overwriting"
  //           << "Also make sure when we unRent(inv.cpp), that we alter NA to be todays date, function ready"
  //           << "Then get the rest of things up & running. Then we can spend the next few days fixing up add chars" 
  //           << "and dodgy functionality. Doable if we keep at it though. Keep her rolling, it's not that far off. "
  //           << "you're getting better for sure. That's what's important. We'll get there eventually in the long run"
  //           << "Take a deep breath & get grinding";



  auto inv = std::make_shared<Inventory>();

  Serializer::read(inv);
  Serializer::readHistorySet(inv);
  Serializer::readCurrentlyLeasedSet(inv);



  int option;
  std::string menuMod;
  do {


  std::cout 
  << "Vehicle Rental System\n"      
  << "---------------------\n\n" << "Registration Number"
  << "    Cost Per Day"
  << "    Vehicle Type\n"
  << "-------------------"
  << "    ------------"
  << "    ------------\n";
    
  auto sorted = inv->sort(menuMod);
  inv->displayRegCostPerDayNType(sorted);

  std::cout << "\n";
  Menu::displayOptions();
  option = 0;
    std::cin >> option;
    switch (option) {
    case 1:
        Menu::addVehicle(inv);
        clearScreen();
        break;
    case 2:
        Menu::removeVehicle(inv);
        clearScreen();
        break;
    case 3:
        Menu::search(inv, "car");
        clearScreen();
        break;
    case 4:
        Menu::search(inv, "bike");
        clearScreen(); 
        break;
    case 5:
        menuMod = "reg";
        clearScreen();
        break;
    case 6:
        menuMod = "costPD";
        clearScreen();
        break;
    case 9:
        Menu::exit(inv);
        clearScreen();
        break;
    }
  } while (option != 9);
  return 0;
}

