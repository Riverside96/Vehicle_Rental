#include "Inventory.h"
#include "dateHelpers.h"
#include <iostream>
#include <regex>
#include <string>
using namespace std;
//const int OLDEST_VALID_VEHICLE_YYYY = 1940;


  // we could maybe just private class member here instead  of passing in a reference 
  void Inventory::deciderReset(string &decider){decider = "";}

  bool Inventory::isDeciderValid(string decider){
    return bool (decider == "y" || decider == "n") ? true : false; }

  void Inventory::complain(){
    cout << "Invalid Input" << endl;;
  };


  bool Inventory::validateReg(string input){
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


bool Inventory::checkdate(int d, int m, int y) {
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

string Inventory::dateIntsToString(int day, int month, int year){
  ostringstream date;
  date <<day<<"/"<<month<<"/"<<year;
  string dateString = date.str();
  return dateString;
}

// to implement when we have hooked up a database to a lookup table
// also implement did you mean 
 bool Inventory::checkMakeInDatabase(string make){
  return  make == "make" ? 1 : 0;
}
 bool Inventory::checkModelInDatabase(string model){
  return model == "model" ? 1 : 0;

}


  


  void Inventory::addVehicle(){


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


  string vehicleType;
  int wheels;
  string registration;
  string dateOfManufacture;
  string make;
  string model;
  int numberOfDoors;
  
  cout << "You may now enter the vehicle details" << endl;
  cout << "you may quit at any point during registration " << 
          "by entering q at any of the following prompts" << endl;


    // add a generic function that prompts user if answer is correct ( allows for all data types output)

  cout << "Is the vehicle you would like to add a car? [y/n]: " <<endl;
  do {
    cin >> answer;
    if(isDeciderValid(answer)){
      if(answer=="n") break;
      vehicleType = "Car";
      wheels = 4; break;
    }else cout << "Invalid input" << endl; 
  } while (until_break!=broke);   

  cout << "Is the vehicle a motorcycle? [y/n]: " <<endl;
  do {
    cin >> answer;
    if(isDeciderValid(answer)){
      vehicleType = (answer=="y") ? "Motorcycle" : "Tricycle"; break;
    } else complain();
  } while (until_break!=broke);  

   string r = "AR02 AMC";

//dateProduced  reg make 
  // try checking each index is wihtin a range to speed up later // or maybe a faster way to use regex
  cout << "What is the registration of the vehicle?, Ensure caps & space, eg [AA00 AAA]" << endl;
  do {
    //cin >> answer;
    // no blank spaces allowed, find out how to limit chars (at a later date if we have time )
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
  if(!checkdate(day, month, year)) 
      complain();
  else {
      dateOfManufacture = dateIntsToString(day, month, year);
      break;
      }
  } while (until_break!=broke);


  
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





cout << dateOfManufacture;



  };
