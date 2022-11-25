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

  std::shared_ptr<Inventory> temp = std::make_shared<Inventory>();

  int option;
  do {
  Menu::displayOptions();
  option = 0;
    std::cin >> option;
    switch (option) {
    case 1:
        Menu::addVehicle(temp);
        // Menu::addVehicle(std::move(temp));
        break;
    case 2:
        Menu::removeVehicle(temp);
        break;
    case 3:
        Menu::searchForCar(temp);
        break;
    case 4:
        Menu::searchForBike(temp);
         break;
    case 5:
        Menu:: sortByRegistration(temp);
        break;
    case 6:
        Menu::sortByCostPerDay(temp);
        break;
    case 9:
        Menu::exit(temp);
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


