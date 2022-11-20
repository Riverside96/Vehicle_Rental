#include "Menu.h"
#include <iostream>
#include "vehicle.h"
#include "car.h"
#include "bike.h"
#include <list>
#include "Inventory.h"

#include "dateHelpers.h"

using namespace std;

// add system login with regex


void addVehicle(){};
void removeVehicle();
void searchForCar();
void searchForBike();
void sortByRegistration();
void sortByCostPerDay();
void exit();

int main(int argc, char *argv[]) {




  Inventory::addVehicle();
  

 //  list<vehicle*> vehicleList;
 //  list<vehicle*>::iterator vehicleListIterator;

  
 //  car *a= new car(2, "abc", "honda", "civic", 20);
 //  car *b = new car(4, "abc", "toyota", "prius", 10);
 //  bike *c = new bike(125, 2, "123", "yammy", "YZF", 5);

 //  
 //  vehicleList.push_back(a);
 //  vehicleList.push_back(b);
 //  vehicleList.push_back(c);
 //  


 //  // for (vehicleListIterator = vehicleList.begin();vehicleListIterator != vehicleList.end();vehicleListIterator++){
 //  //     cout << (*vehicleListIterator)->costPerDay() << endl;
 //  //     cout << (*vehicleListIterator)->getModel() << endl;
 //  //   }

 //  
 //  // Free pointers
 //    for (vehicleListIterator = vehicleList.begin();vehicleListIterator != vehicleList.end();vehicleListIterator++){
 //      delete *vehicleListIterator;
 //  }

 //   vehicleList.clear(); // List is deleted.

 // 


 //  Menu::displayOptions();
 //  int option = 0;
 //  // do {
 //  //   cin >> option;
 //  //   switch (option) {
 //  //   case 1:
 //  //     addVehicle();
 //  //     break;
 //  //   case 2:
 //  //     removeVehicle();
 //  //     break;
 //  //   case 3:
 //  //     searchForCar();
 //  //     break;
 //  //   case 4:
 //  //     searchForBike();
 //  //     break;
 //  //   case 5:
 //  //     sortByRegistration();
 //  //     break;
 //  //   case 6:
 //  //     sortByCostPerDay();
 //  //     break;
 //  //   case 7:
 //  //     exit();
 //  //     break;
 //  //   }

 //  // } while (option != 9);



  return 0;
}

// void addVehicle(){};
// void removeVehicle();
// void searchForCar();
// void searchForBike();
// void sortByRegistration();
// void sortByCostPerDay();
// void exit();
