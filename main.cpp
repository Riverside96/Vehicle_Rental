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



  // std::string testdate = "2012/06/30";
  // int y, m, d;
  // dateHelpers::strToYYYYMMDD(testdate, y, m, d) ;
  // std::cout << "  year: " << y
  //           << "  month: " << m
  //           << "  day: " << d
  //           << "\n";



  int testStrToChange;


  // Serializer::deleteFile();
  auto inv = std::make_shared<Inventory>();
  Serializer::read(inv);
  Serializer::readHistorySet(inv);
  Serializer::readCurrentlyLeasedSet(inv);


  inv->printHasHistory();
  //
  
  // std::string testing = ("TT00 TTT");
  // std::string testing2 = ("MM00 MMM");
  // std::string testing3 = ("RR00 RRR");
  // inv->addHasHistory(testing);
  // inv->addHasHistory(testing2);
  // inv->addHasHistory(testing3);

  // Serializer::read("LL00 LLL", testStrToChange, inv);
  

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

