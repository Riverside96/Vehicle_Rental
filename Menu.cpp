#include "Menu.h"
#include "Car.h"
#include "Inventory.h"
#include "dateHelpers.h"
#include <bits/ranges_algo.h>
#include <iostream>
#include <iterator>
#include <memory>
#include <regex>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
//const int OLDEST_VALID_VEHICLE_YYYY = 1940;



  // we could maybe just private class member here instead  of passing in a reference 
  void Menu::deciderReset(string &decider){decider = "";}

  bool Menu::isDeciderValid(string decider){
    return bool (decider == "y" || decider == "n") ? true : false; }

  void Menu::complain(){
    cout << "Invalid Input" << endl;;
  };


  bool Menu::validateReg(string input){
  regex carRegRegex ("^[A-Z]{2}[0-9]{2}\\s[A-Z]{3}$");
  //return bool (regex_match(input, carRegRegex)) ? false : true;
  smatch match; // dont think this is necassaRY
  bool found = regex_match(input, carRegRegex);
  return found;
};

// int Inventory::getYear(){
//   time_t t = time(NULL);
// 	tm* timePtr = localtime(&t);
//   // int year = ((timePtr->tm_year) +1900) % 100 ;
//   int year = ((timePtr->tm_year) +1900);
//   return year;
// }


bool Menu::checkdate(int d, int m, int y) {
  // if (y<  OLDEST_VALID_VEHICLE_YYYY || y>getYear()) return 0; 
  if (y<  OLDEST_VALID_VEHICLE_YYYY || y> dateHelpers::getYear()) return 0; 
  if (!(1<= m && m<=12)) return 0;
  if (!(1<= d && d<=31)) return 0;
  if ((d==31) && (m==2 || m==4 || m==6 || m==9 || m==11)) return 0;
  if ((d==30) && (m==2)) return 0;
  if ((m==2) && (d==29) && (y%4!=0)) return 0;
  if ((m==2) && (d==29) && (y%400==0)) return 0;
  if ((m==2) && (d==29) && (y%100==0)) return 0;
  if ((m==2) && (d==29) && (y%4==0)) return 0;
  return true;
}

string Menu::dateIntsToString(int day, int month, int year){
  ostringstream date;
  date <<day<<"/"<<month<<"/"<<year;
  string dateString = date.str();
  return dateString;
}

// to implement when we have hooked up a database to a lookup table
// also implement did you mean 
 bool Menu::checkMakeInDatabase(string make){
  return  make == "make" ? 1 : 0;
}
 bool Menu::checkModelInDatabase(string model){
  return model == "model" ? 1 : 0;

}


  

  
  void Menu::addVehicle(){


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

  //decide vehicle type ==================================
  const int until_break (-1);
  const int broke(1);
  string answer;


  // change to this if we are allowed to add boost reflection
  // struct attributes{
  // string vehicleType;
  // int wheels;
  // string registration;
  // string dateOfManufacture;
  // string make;
  // string model;
  // int numberOfDoors;
  // int seats;
  // int engineCC;
  // };
  // attributes temp;

  
  int numOfWheels, numOfDoors, seats, engineCC;
  string vehicleType, registration, dateOfManufacture, make, model; 

  
  // could add a if b is entered, jump back to last question method later 
  cout << "You may now enter the vehicle details" << endl;
  cout << "you may quit at any point during registration " << 
          "by entering q at any of the following prompts" << endl;


    // add a generic function that prompts user if answer is correct ( allows for all data types output)
  
  // try checking each index is wihtin a range to speed up later // or maybe a faster way to use regex
  cout << "What is the registration of the vehicle?, Ensure caps & space, eg [AA00 AAA]" << endl;
  do {
    //cin >> answer; no blank spaces allowed, find out how to limit chars (at a later date if we have time )
    getline(cin, answer);
    if(validateReg(answer)) {
      registration = answer;
      break;
    } else complain();
  } while (until_break!=broke);

  cout << "What is the date of manufacture? [DD/MM/YYYY]" << endl;
  int day, month, year; 
  do{
  cout << "Day: "; cin >> day;
  cout << "Month: "; cin >> month;
  cout << "Year: "; cin >> year;
  if(checkdate(day, month, year)) {
    dateOfManufacture = dateIntsToString(day, month, year); break;
    } else complain(); 
  } while (until_break!=broke);
  
  cout << "Is the vehicle you would like to add a car? [y/n]: " <<endl;
  do {
    cin >> answer;
    if(isDeciderValid(answer)){
      vehicleType = (answer == "y") ? "Car" : "Motorcycle"; break;
    }else cout << "Invalid input" << endl; 
  } while (until_break!=broke);   

  if (vehicleType == "Car") {
    cout << "How many doors does the car have ?" <<endl;
    do {
      cin >> numOfDoors;
      if(numOfDoors == 3 || numOfDoors == 5) break;
      else complain();
    } while (until_break!=broke);  
  }

  if (vehicleType == "Motorcycle") {
    cout << "How many wheels does the motorcycle have?" <<endl;
    do {
      cin >> numOfWheels;
      if(numOfWheels == 2 || numOfWheels == 4) break;
      else complain();
    } while (until_break!=broke);  
  }

  if (vehicleType == "Motorcycle") {
    cout << "Engine Size?" <<endl;
    do {
      cin >> engineCC;
      if(engineCC == 50 || 
        engineCC == 125 || 
        engineCC == 250 ||
        engineCC == 400 ||
        engineCC == 600 ||
        engineCC == 650 ||
        engineCC == 1000) 
        break;
      else complain();
    } while (until_break!=broke);  
  }

  cout << "Make of the Vehicle? [DD/MM/YYYY]" << endl;
  do {
    cin >> make;
    if (checkMakeInDatabase(make)) break;
    else complain(); 
  } while (until_break!=broke);

  cout << "Model of the Vehicle? [DD/MM/YYYY]" << endl;
  do {
    cin >> model;
    if (checkMakeInDatabase(model)) break;
    else complain(); 
  } while (until_break!=broke);

  if (vehicleType == "Car")
    do {
      cout << "How many seats?: ";
      cin >> seats;
      if (seats == 2 || seats == 4 || seats == 5){
        break;
      } else complain();
    } while (until_break!=broke); 





  // Inventory::add(std::unique_ptr<Vehicle> v)


  // new Car(2, 4, "TT00 TTT", "make", "model", "01/07/1996");


  // if (vehicleType == "Car") {
  //  make_unique<Car>(numOfDoors, seats, registration, make, model, dateOfManufacture);
  // }

  // if (vehicleType == "Motorcycle"){
  //   bikeMap.insert(make_pair(registration, new Bike(registration, make, model, dateOfManufacture, numOfWheels, engineCC)));
  // }


  }






