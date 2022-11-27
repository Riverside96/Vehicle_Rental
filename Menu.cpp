#include "Menu.h"
#include "Bike.h"
#include "Car.h"
#include <iostream>
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
  std::string mod = "hello";
  void Menu::searchForCar(std::shared_ptr<Inventory> inventory){return;};
  void Menu::searchForBike(std::shared_ptr<Inventory> inventory){std::cout << "not implemented\n\n"; return ;}; 
  void Menu::sortByRegistration(std::shared_ptr<Inventory> inventory) {inventory->sort("reg");};
  void Menu::sortByCostPerDay(std::shared_ptr<Inventory> inventory) {inventory->sort("costPd");};  
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
  std::smatch match; // dont think this is necassaRY
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


  void Menu::addVehicle(std::shared_ptr<Inventory> inventory){


  //=============//
  int numOfWheels, numOfDoors, seats, engineCC;
  std::string vehicleType, registration, dateOfManufacture, make, model; 

  numOfWheels = 4;
  numOfDoors = 3;
  seats = 4;
  vehicleType = "Car";
  engineCC = 125;
  registration = "TT00 TTT";
  dateOfManufacture = "01/07/1996";
  make = "make";
  model = "make";

 if (vehicleType == "Car") {
    // inventory->add(make_unique<Car>(numOfDoors, seats, registration, make, model, dateOfManufacture));
    inventory->add(make_unique<Car>(registration, make, model, dateOfManufacture, numOfDoors, seats));
    registration = "ZZ00 ZZZ";
    inventory->add(make_unique<Car>(registration, make, model, dateOfManufacture, numOfDoors, seats));
    registration = "BB00 BBB";
    inventory->add(make_unique<Car>(registration, make, model, dateOfManufacture, numOfDoors, seats));
    registration = "FF00 FFF";
    inventory->add(make_unique<Car>(registration, make, model, dateOfManufacture, numOfDoors, seats));
    registration = "JJ00 JJJ";
    inventory->add(make_unique<Car>(registration, make, model, dateOfManufacture, numOfDoors, seats));
    registration = "YY00 YYY";
    inventory->add(make_unique<Car>(registration, make, model, dateOfManufacture, numOfDoors, seats));
   }
  vehicleType = "Motorcycle";
  registration = "MM00 MMM";

  if (vehicleType == "Motorcycle"){
    inventory->add(make_unique<Bike>(registration, make, model, dateOfManufacture, numOfWheels, engineCC));
    }
  //====================//
  


    // std::vector<int> nums{3, 4, 2, 8, 15, 267};
    // auto List<auto> guess{"hey", 3};
    // // ranges::for_each(as_const(nums), print);
    // auto print = [](const auto& n) { cout << n ;};
    // for_each(nums.begin(), nums.end(), print);


  // we could have an overloaded reset that takes a string & a bool or something
  // maybe have a function with a variable number of inputs instead..... variadic?
  // we could pass a number ie 3, it would then do a valid input check for inputs 1, 2, & 3.
  //
  //

  // save repetition with overloaded 
  // Decide(char yesOrNo string nameOfValueToSet int valueToSet string outputErrorMsg)
  // Decide(char yesOrNo string nameOfValueToSet string valueToSet string outputErrorMsg)
  // Decide()

 // 
 //  string test = dateIntsToString(5, 3, 21);
 //  cout << test;
 // 

  // //decide vehicle type ==================================
  //
  //
 //  std::cin.ignore();
 //  const int until_break (-1);
 //  const int broke(1);
 //  std::string answer;


 //  int numOfWheels, numOfDoors, seats, engineCC;
 //  std::string vehicleType, registration, dateOfManufacture, make, model; 


 //  // could add a if b is entered, jump back to last question method later 
 //  std::cout << "\n\nYou may now enter the vehicle details\n";
 //  std::cout << "you may quit at any point during registration " << 
 //          "by entering q at any of the following prompts\n\n";


 //    // add a generic function that prompts user if answer is correct ( allows for all data types output)

 //  // try checking each index is wihtin a range to speed up later // or maybe a faster way to use regex
 //  std::cout << "What is the registration of the vehicle?, Ensure caps & space, eg [AA00 AAA]\n";
 //  do {
 //    //cin >> answer; no blank spaces allowed, find out how to limit chars (at a later date if we have time )
 //    getline(std::cin, answer);
 //    if(validateReg(answer)) {
 //      registration = answer;
 //      break;
 //    } else complain();
 //  } while (until_break!=broke);

 //  std::cout << "What is the date of manufacture? [DD/MM/YYYY]" << std::endl;
 //  int day, month, year; 
 //  do{
 //  std::cout << "Day: "; std::cin >> day;
 //  std::cout << "Month: "; std::cin >> month;
 //  std::cout << "Year: "; std::cin >> year;
 //  if(dateHelpers::checkdate(day, month, year, OLDEST_VALID_VEHICLE_YYYY)) {
 //    dateOfManufacture = dateIntsToString(day, month, year); break;
 //    } else complain(); 
 //  } while (until_break!=broke);

 //  std::cout << "Is the vehicle you would like to add a car? [y/n]: " <<std::endl;
 //  do {
 //    std::cin >> answer;
 //    if(isDeciderValid(answer)){
 //      vehicleType = (answer == "y") ? "Car" : "Motorcycle"; break;
 //    }else std::cout << "Invalid input" << std::endl; 
 //  } while (until_break!=broke);   

 //  if (vehicleType == "Car") {
 //    std::cout << "How many doors does the car have ?" <<std::endl;
 //    do {
 //      std::cin >> numOfDoors;
 //      if(numOfDoors == 3 || numOfDoors == 5) break;
 //      else complain();
 //    } while (until_break!=broke);  
 //  }

 //  if (vehicleType == "Motorcycle") {
 //    std::cout << "How many wheels does the motorcycle have?" <<std::endl;
 //    do {
 //      std::cin >> numOfWheels;
 //      if(numOfWheels == 2 || numOfWheels == 3) break;
 //      else complain();
 //    } while (until_break!=broke);  
 //  }

 //  if (vehicleType == "Motorcycle") {
 //    std::cout << "Engine Size?" <<std::endl;
 //    do {
 //      std::cin >> engineCC;
 //      if(engineCC == 50 || 
 //        engineCC == 125 || 
 //        engineCC == 250 ||
 //        engineCC == 400 ||
 //        engineCC == 600 ||
 //        engineCC == 650 ||
 //        engineCC == 1000) 
 //        break;
 //      else complain();
 //    } while (until_break!=broke);  
 //  }

 //  std::cout << "Make of the Vehicle? [DD/MM/YYYY]" << std::endl;
 //  do {
 //    std::cin >> make;
 //    if (checkMakeInDatabase(make)) break;
 //    else complain(); 
 //  } while (until_break!=broke);

 //  std::cout << "Model of the Vehicle? [DD/MM/YYYY]" << std::endl;
 //  do {
 //    std::cin >> model;
 //    if (checkMakeInDatabase(model)) break;
 //    else complain(); 
 //  } while (until_break!=broke);

 //  if (vehicleType == "Car")
 //    do {
 //      std::cout << "How many seats?: ";
 //      std::cin >> seats;
 //      if (seats == 2 || seats == 4 || seats == 5){
 //        break;
 //      } else complain();
 //    } while (until_break!=broke); 



 // if (vehicleType == "Car") {
 //    // inventory->add(make_unique<Car>(numOfDoors, seats, registration, make, model, dateOfManufacture));
 //    inventory->add(make_unique<Car>(registration, make, model, dateOfManufacture, numOfDoors, seats));
 //   }
 //  // vehicleType = "Motorcycle";
 //  // registration = "BB00 BBB";

 //  if (vehicleType == "Motorcycle"){
 //    inventory->add(make_unique<Bike>(registration, make, model, dateOfManufacture, numOfWheels, engineCC));
 //    }

  return;
  }
