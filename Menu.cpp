#include "Menu.h"
#include "Bike.h"
#include "Car.h"
#include <iostream>
#include <ostream>
#include <regex>
#include "dateHelpers.h"
#include <memory.h>
#include <string>
#include <tuple>
  void Menu::displayOptions(){
    std::cout << "1) Add Vehicle\n" 
         << "2) Remove Vehicle\n"
         << "3) Search For Car\n"
         << "4) Search For Bike\n"
         << "5) Sort Vehicles By Registration\n"
         << "6) Sort By Cost Per Day\n"
         << "9) Exit\n";
};
  void Menu::removeVehicle(std::shared_ptr<Inventory> inventory){
   std::cin.ignore();
   std::string regToDelete;
   do {
   std::cout << "Enter the registration of the Vehicle you wish to delete, or enter q to quit:  \n";
   getline(std::cin, regToDelete);
   if (regToDelete == "q") break;

   if (inventory->checkKeyExists(regToDelete)) {
    std::string answer; 
    std::cout<< "Are you sure you want to delete this vehicle? [y/n]: "; 
    std::cin >> answer;
    if (isDeciderValid(answer)) {
      if (answer == "y") {inventory->remove(regToDelete);}
      break;
    } else complain();
    } else complain();

  } while (regToDelete!="quit");
   
   return;
};
  // std::string mod = "hello";
  void Menu::search(std::shared_ptr<Inventory> inventory, std::string mod){
    int opt(0), optInt(5);
    std::string answer(""), optStr("");

    bool broke(0);
    std::string q2 = (mod=="car") ? "Number of seats" : "Max engine size";
    std::string q3 = (mod=="car") ? "Number of doors" : "Two- or -Three-wheeler";
    std::cout << "Search for a "+mod+" by:\n"
              << "--------------------\n"
              << "1) Registration number\n"
              << "2) " << q2 << "\n"
              << "3) " << q3 << "\n"
              << "9) Return to main menu \n\n"<< std::endl;
    do{
      std::cout << "Please choose an option: ";
      std::cin >> opt;
      if(opt==1 || opt==2 || opt==3 || opt==9) {
      broke = 1; break;
    }else complain();
    } while (!broke);    
  
   if(mod=="car"){
    switch(opt){
      case 1:
        std::cout << "\nEnter Registration: ";
        enterReg(optStr, answer);
        break;
      case 2:
        std::cout << "\nEnter number of seats: ";
        enterSeats(optInt);
        break;
      case 3:
         std::cout << "\nEnter number of doors: ";
        enterDoors(optInt);
        break;
}
  } else {
    switch(opt){
      case 1:
        std::cout << "\nEnter registration: ";
        enterReg(optStr, answer);
        break;
      case 2:
        std::cout <<"Enter max engine size: ";
        enterEngineSize(optInt);
        break;
      case 3:
        std::cout << "Enter number of wheels: ";
        enterWheels(optInt);
        break;
    }
  }
  inventory->search(mod, opt,  optInt, optStr, inventory);
};

  void Menu::exit(std::shared_ptr<Inventory> inventory){
    std::cout << "Are you sure you want to quit? [y/n]\n\n";
    inventory->save();

}
  // we could maybe just private class member here instead  of passing in a reference 
  void Menu::deciderReset(std::string &decider){decider = "";}

  bool Menu::isDeciderValid(std::string decider){
    return bool (decider == "y" || decider == "n") ? true : false; }

  void Menu::complain(){
    std::cout << "Invalid Input" << std::endl;;
  };

  bool Menu::validateReg(std::string input){
  std::regex carRegRegex ("^[A-Z]{2}[0-9]{2}\\s[A-Z]{3}$");
  //return bool (regex_match(input, carRegRegex)) ? false : true;
  // std::smatch match; // dont think this is necassaRY
  bool found = regex_match(input, carRegRegex);
  return found;
};

std::string Menu::dateIntsToString(int day, int month, int year){
  std::ostringstream date;
  date <<day<<"/"<<month<<"/"<<year;
  std::string dateString = date.str();
  return dateString;
}

// to implement when we have hooked up a database to a lookup table
// also implement did you mean 
 bool Menu::checkMakeInDatabase(std::string make){
  return  make == "make" ? 1 : 0;
}
 bool Menu::checkModelInDatabase(std::string model){
  return model == "model" ? 1 : 0;
}

  void Menu::enterReg(std::string &registration, std::string &answer){
    bool broke(0);
    do {
      //cin >> answer; no blank spaces allowed, find out how to limit chars (at a later date if we have time )
      getline(std::cin, answer);
      if(validateReg(answer)) {
        registration = answer;
        broke=1; break;
      } else complain();
    } while (!broke);

};
// fix infin loop when entering letters instead of ints
// also should be shorts not ints probs
  void Menu::enterManufactureDate(std::string &dateOfManufacture){
    bool broke(0);
    int day, month, year;
  do{
  std::cout << "Day: "; std::cin >> day;
  std::cout << "Month: "; std::cin >> month;
  std::cout << "Year: "; std::cin >> year;
  if(dateHelpers::checkdate(day, month, year, OLDEST_VALID_VEHICLE_YYYY)) {
    dateOfManufacture = dateIntsToString(day, month, year); broke=1; break;
    } else complain(); 
  } while (!broke);
};

  void Menu::enterVehicleType(std::string &vehicleType, std::string &answer){
    bool broke(0);
    do {
      std::cin >> answer;
      if(isDeciderValid(answer)){
        vehicleType = (answer == "y") ? "Car" : "Motorcycle"; broke=1; break; 
      }else complain(); 
  } while (!broke);   
};

  void Menu::enterDoors(int numOfDoors){
    bool broke(0);
    do {
      std::cin >> numOfDoors;
      if(numOfDoors == 3 || numOfDoors == 5){
      broke=1; 
      break;
    } else complain();
    } while (!broke);  

};
  void Menu::enterWheels(int numOfWheels){
    bool broke(0); 
    do {
      std::cin >> numOfWheels;
      if(numOfWheels == 2 || numOfWheels == 3) {
      broke=1;
      break;
    } else complain();
    } while (!broke);  
};
  void Menu::enterEngineSize(int &engineCC){
    bool broke(0);
    do {
      std::cin >> engineCC;
      if(engineCC == 50 || 
        engineCC == 125 || 
        engineCC == 250 ||
        engineCC == 400 ||
        engineCC == 600 ||
        engineCC == 650 ||
        engineCC == 1000){
        broke = 1; 
        break;
     }else complain();
    } while (!broke);  
};
  void Menu::enterMake(std::string &make, auto &inventory, std::string &answer){
    bool broke(0);
    do {
      std::cin >> make;
      if (inventory->isMakeInMap(make)) break;
      else {
          make = inventory->didYouMeanMake(make);
          std::cout << "Did you mean " << make << "? [y/n]: ";
          std::cin >> answer;
          if(!isDeciderValid(answer)) complain();
          if(answer=="y") broke=1; break;
        }
  } while (!broke);
};
  void Menu::enterModel(std::string &make, std::string &model, std::string &answer, auto &inventory){
  bool broke(0);
  do {
    std::cin >> model;
    // if (checkMakeInDatabase(model)) break;
    if (inventory->isModelInMap(make, model)) break;
    else {
      model = inventory->didYouMeanModel(make, model);
      std::cout << "Did you mean " << model << " ? [y/n]:  ";
      std::cin >> answer;
      if(!isDeciderValid(answer)) complain(); 
      if(answer == "y") broke=1;
    }
  } while (!broke);
};

  void Menu::enterSeats(int &seats){
  bool broke(0);
  do{
    std::cin >> seats;
    if (seats == 2 || seats == 4 || seats == 5){
      broke=1;
      break;
    } else complain();
  }while (!broke); 
};

  void Menu::addVehicle(std::shared_ptr<Inventory> inventory){
  std::cin.ignore();
  // const int until_break (-1);
  // const int broke(1);
  std::string answer;

  int numOfWheels(0), numOfDoors(0), seats(0), engineCC(0);
  std::string vehicleType, registration, dateOfManufacture, make, model; 

  // could add a if b is entered, jump back to last question method later 
  std::cout << "\n\nYou may now enter the vehicle details\n";
  std::cout << "you may quit at any point during registration " << 
          "by entering q at any of the following prompts\n\n";


    // add a generic function that prompts user if answer is correct ( allows for all data types output)
  // try checking each index is wihtin a range to speed up later // or maybe a faster way to use regex
  std::cout << "What is the registration of the vehicle?, Ensure caps & space, eg [AA00 AAA]\n";
  enterReg(registration, answer);

  std::cout << "What is the date of manufacture? [DD/MM/YYYY]" << std::endl;
  enterManufactureDate(dateOfManufacture);
 
  std::cout << "Is the vehicle you would like to add a car? [y/n]: " <<std::endl;
  enterVehicleType(vehicleType, answer);

   if (vehicleType == "Car") {
    std::cout << "How many doors does the car have ?" <<std::endl;
    enterDoors(numOfDoors);
  }
     if (vehicleType == "Motorcycle") {
    std::cout << "How many wheels does the motorcycle have?" <<std::endl;
    enterWheels(numOfWheels);
  }
   if (vehicleType == "Motorcycle") {
    std::cout << "Engine Size?" <<std::endl;
    enterEngineSize(engineCC);
  }
  std::cout << "Make of the Vehicle? [DD/MM/YYYY]" << std::endl;
  enterMake(make, inventory, answer);

  std::cout << "Model of the Vehicle? [DD/MM/YYYY]" << std::endl;\
  enterModel(make, model, answer, inventory);
   if (vehicleType == "Car"){
    std::cout << "How many seats?: ";
    enterSeats(seats);
  }
    if (vehicleType == "Car") {
    // inventory->add(make_unique<Car>(numOfDoors, seats, registration, make, model, dateOfManufacture));
    inventory->add(make_unique<Car>(registration, make, model, dateOfManufacture, numOfDoors, seats));
   }
  if (vehicleType == "Motorcycle"){
    inventory->add(make_unique<Bike>(registration, make, model, dateOfManufacture, numOfWheels, engineCC));
    }
  return;
  }
