#include "Menu.h"
#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"
#include <list>
#include "Inventory.h"
#include "Car.h"
#include "dateHelpers.h"
#include <fstream>
#include "Serializer.h"


// add system login with regex



int main(int argc, char *argv[]) {

   // for (const auto& t : carMap){
   //   cout << *(t.second);
   // }
  //
  // //
  unique_ptr<Inventory> temp = make_unique<Inventory>();


  Menu::addVehicle(std::move(temp));

  // 
  // carMap.insert(make_pair("AA00 AAA", unique_ptr<Car>(new Car(5, 4, "AA00 AAA", "Skoda", "Fabia", "01/07/1997"))));
  // carMap.insert(make_pair("BB00 BBB", unique_ptr<Car>(new Car(5, 4, "BB00 BBB ", "Vauxhall", "Astra", "01/07/1994"))));
  // carMap.insert(make_pair("CC00 CCC", unique_ptr<Car>(new Car(5, 4, "CC00 CCC", "BMW", "320D", "01/07/2005"))));


  //carMap.insert(make_pair("AA00 AAA", unique_ptr<Car>(new Car(5, 4, "AA00 AAA", "Skoda", "Fabia", "01/07/1997"))));

  
  // Serializer::save();
  // Serializer::read();


   // for (const auto& t : carMap){
   //   cout << *(t.second);
   // }



  // Menu::displayOptions();
  int option = 0;
  do {
    cin >> option;
    switch (option) {
    case 1:
        Menu::addVehicle(std::move(temp));
        break;
    case 2:
        Menu::removeVehicle();
        break;
    case 3:
        Menu::searchForCar();
        break;
    case 4:
        Menu::searchForBike();
         break;
    case 5:
        Menu:: sortByRegistration();
        break;
    case 6:
        Menu::sortByCostPerDay();
        break;
    case 7:
        Menu::exit();
      break;
    }

  } while (option != 9);



  return 0;
}

