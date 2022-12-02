#include "Menu.h"
#include <iostream>
#include "Serializer.h"
#include "Inventory.h"
int main(int argc, char *argv[]) {

  // Serializer::deleteFile();
  auto inv = std::make_shared<Inventory>();
  Serializer::read(inv);

  int option;
  std::string menuMod;
  do {
  std::cout 
  << "Vehicle Rental System\n"      
  << "---------------------\n\n"
  << "Registration Number"
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
        break;
    case 2:
        Menu::removeVehicle(inv);
        break;
    case 3:
        Menu::search(inv, "car");
        break;
    case 4:
        Menu::search(inv, "bike");
         break;
    case 5:
        menuMod = "reg";
        break;
    case 6:
        menuMod = "costPD";
        break;
    case 9:
        Menu::exit(inv);
      break;
    }
  } while (option != 9);
  return 0;
}

