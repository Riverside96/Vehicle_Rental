#include "Menu.h"
#include "Bike.h"
#include "Car.h"
#include <iostream>
#include <regex>
  void Menu::displayOptions(){
    std::cout << "1) Add Vehicle\n" 
         << "2) Remove Vehicle\n"
         << "3) Search For Car\n"
         << "4) Search For Bike\n"
         << "5) Sort Vehicles By Registration\n"
         << "6) Sort By Cost Per Day\n"
         << "9) Exit\n";
};
  void Menu::removeVehicle(std::shared_ptr<Inventory> inventory){std::cout << "not implemented\n\n"; return;};
  void Menu::searchForCar(std::shared_ptr<Inventory> inventory){std::cout << "not implemented\n\n"; return;};
  void Menu::searchForBike(std::shared_ptr<Inventory> inventory){std::cout << "not implemented\n\n"; return ;}; 
  void Menu::sortByRegistration(std::shared_ptr<Inventory> inventory){std::cout << "not implemented\n\n";};
  void Menu::sortByCostPerDay(std::shared_ptr<Inventory> inventory){ std::cout << "not implemented\n\n";};  
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

  int numOfWheels, numOfDoors, seats, engineCC;
  std::string vehicleType, registration, dateOfManufacture, make, model; 

  numOfWheels = 4;
  numOfDoors = 3;
  seats = 4;
  vehicleType = "Car";
  engineCC = 125;
  registration = "CC00 CCC";
  dateOfManufacture = "01/07/1996";
  make = "make";
  model = "make";

 if (vehicleType == "Car") {
    // inventory->add(make_unique<Car>(numOfDoors, seats, registration, make, model, dateOfManufacture));
    inventory->add(make_unique<Car>(registration, make, model, dateOfManufacture, numOfDoors, seats));
   }

  
  vehicleType = "Motorcycle";
  registration = "BB00 BBB";


  if (vehicleType == "Motorcycle"){
    inventory->add(make_unique<Bike>(registration, make, model, dateOfManufacture, numOfWheels, engineCC));
    }

  // ofstream file;
  // file.open("test.txt", ios_base::out | ios_base::trunc);
  // if(file.is_open()){
  //   inventory->serialize(file);
  //  }
  //   file.close();


  


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
  // const int until_break (-1);
  // const int broke(1);
  // string answer;


  // // change to this if we are allowed to add boost reflection
  // // struct attributes{
  // // string vehicleType;
  // // int wheels;
  // // string registration;
  // // string dateOfManufacture;
  // // string make;
  // // string model;
  // // int numberOfDoors;
  // // int seats;
  // // int engineCC;
  // // };
  // // attributes temp;

  // 
  // int numOfWheels, numOfDoors, seats, engineCC;
  // string vehicleType, registration, dateOfManufacture, make, model; 

  // 
  // // could add a if b is entered, jump back to last question method later 
  // cout << "You may now enter the vehicle details" << endl;
  // cout << "you may quit at any point during registration " << 
  //         "by entering q at any of the following prompts" << endl;


  //   // add a generic function that prompts user if answer is correct ( allows for all data types output)
  // 
  // // try checking each index is wihtin a range to speed up later // or maybe a faster way to use regex
  // cout << "What is the registration of the vehicle?, Ensure caps & space, eg [AA00 AAA]" << endl;
  // do {
  //   //cin >> answer; no blank spaces allowed, find out how to limit chars (at a later date if we have time )
  //   getline(cin, answer);
  //   if(validateReg(answer)) {
  //     registration = answer;
  //     break;
  //   } else complain();
  // } while (until_break!=broke);

  // cout << "What is the date of manufacture? [DD/MM/YYYY]" << endl;
  // int day, month, year; 
  // do{
  // cout << "Day: "; cin >> day;
  // cout << "Month: "; cin >> month;
  // cout << "Year: "; cin >> year;
  // if(dateHelpers::checkdate(day, month, year, OLDEST_VALID_VEHICLE_YYYY)) {
  //   dateOfManufacture = dateIntsToString(day, month, year); break;
  //   } else complain(); 
  // } while (until_break!=broke);
  // 
  // cout << "Is the vehicle you would like to add a car? [y/n]: " <<endl;
  // do {
  //   cin >> answer;
  //   if(isDeciderValid(answer)){
  //     vehicleType = (answer == "y") ? "Car" : "Motorcycle"; break;
  //   }else cout << "Invalid input" << endl; 
  // } while (until_break!=broke);   

  // if (vehicleType == "Car") {
  //   cout << "How many doors does the car have ?" <<endl;
  //   do {
  //     cin >> numOfDoors;
  //     if(numOfDoors == 3 || numOfDoors == 5) break;
  //     else complain();
  //   } while (until_break!=broke);  
  // }

  // if (vehicleType == "Motorcycle") {
  //   cout << "How many wheels does the motorcycle have?" <<endl;
  //   do {
  //     cin >> numOfWheels;
  //     if(numOfWheels == 2 || numOfWheels == 4) break;
  //     else complain();
  //   } while (until_break!=broke);  
  // }

  // if (vehicleType == "Motorcycle") {
  //   cout << "Engine Size?" <<endl;
  //   do {
  //     cin >> engineCC;
  //     if(engineCC == 50 || 
  //       engineCC == 125 || 
  //       engineCC == 250 ||
  //       engineCC == 400 ||
  //       engineCC == 600 ||
  //       engineCC == 650 ||
  //       engineCC == 1000) 
  //       break;
  //     else complain();
  //   } while (until_break!=broke);  
  // }

  // cout << "Make of the Vehicle? [DD/MM/YYYY]" << endl;
  // do {
  //   cin >> make;
  //   if (checkMakeInDatabase(make)) break;
  //   else complain(); 
  // } while (until_break!=broke);

  // cout << "Model of the Vehicle? [DD/MM/YYYY]" << endl;
  // do {
  //   cin >> model;
  //   if (checkMakeInDatabase(model)) break;
  //   else complain(); 
  // } while (until_break!=broke);

  // if (vehicleType == "Car")
  //   do {
  //     cout << "How many seats?: ";
  //     cin >> seats;
  //     if (seats == 2 || seats == 4 || seats == 5){
  //       break;
  //     } else complain();
  //   } while (until_break!=broke); 



  // if (vehicleType == "Car") {
  //   // unique_ptr<Car> temp = make_unique<Car>(numOfDoors, seats, registration, make, model, dateOfManufacture);
  //   // unique_ptr<Vehicle> toBase (std::move(temp));
  //   inventory->add(make_unique<Car>(numOfDoors, seats, registration, make, model, dateOfManufacture));
  //  }


  // if (vehicleType == "Motorcycle"){
  //   inventory->add(make_unique<Bike>(registration, make, model, dateOfManufacture, numOfWheels, engineCC));
  //   // bikeMap.insert(make_pair(registration, new Bike(registration, make, model, dateOfManufacture, numOfWheels, engineCC)));
  //   }


  // ofstream file;
  // file.open("test.txt", ios_base::out | ios_base::trunc);
  // if(file.is_open()){
  //   inventory->serialize(file);
  //  }
  //   file.close();

  return;
  }
