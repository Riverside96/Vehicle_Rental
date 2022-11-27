#include "Menu.h"
#include <iostream>
// #include "Vehicle.h"
// #include "Car.h"
// #include "Bike.h"
// #include <list>
// #include "Inventory.h"
// #include "Car.h"
// #include "dateHelpers.h"
// #include <fstream>
// #include "Serializer.h"

// add system login with regex
#include "Inventory.h"
int main(int argc, char *argv[]) {

  auto inv = std::make_shared<Inventory>();
   

  int option;
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
          
  inv->displayRegCostPerDayNType();
  std::cout << "\n";
  Menu::displayOptions();
  option = 0;
    std::cin >> option;
    switch (option) {
    case 1:
        Menu::addVehicle(inv);
        // Menu::addVehicle(std::move(temp));
        break;
    case 2:
        Menu::removeVehicle(inv);
        break;
    case 3:
        Menu::searchForCar(inv);
        break;
    case 4:
        Menu::searchForBike(inv);
         break;
    case 5:
        Menu:: sortByRegistration(inv);
        break;
    case 6:
        Menu::sortByCostPerDay(inv);
        break;
    case 9:
        Menu::exit(inv);
        // Menu::exit(std::move(temp));
      break;
    }

  } while (option != 9);



  return 0;
}













   // for (const auto& t : carMap){
   //   cout << *(t.second);
   // }
  // carMap.insert(make_pair("AA00 AAA", unique_ptr<Car>(new Car(5, 4, "AA00 AAA", "Skoda", "Fabia", "01/07/1997"))));
  // carMap.insert(make_pair("BB00 BBB", unique_ptr<Car>(new Car(5, 4, "BB00 BBB ", "Vauxhall", "Astra", "01/07/1994"))));
  // carMap.insert(make_pair("CC00 CCC", unique_ptr<Car>(new Car(5, 4, "CC00 CCC", "BMW", "320D", "01/07/2005"))));


  //carMap.insert(make_pair("AA00 AAA", unique_ptr<Car>(new Car(5, 4, "AA00 AAA", "Skoda", "Fabia", "01/07/1997"))));

  // Serializer::save();
  // Serializer::read();


   // for (const auto& t : carMap){
   //   cout << *(t.second);
   // }


