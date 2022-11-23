#include "Serializer.h"
#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <memory>
#include <string.h>
#include <string>
#include "Inventory.h"
#include <iterator>
#include <map>
using namespace std;


  // carMap.insert(make_pair("BB00 BBB", unique_ptr<Car>(new Car(5, 4, "BB00 BBB ", "Vauxhall", "Astra", "01/07/1994"))));
  // carMap.insert(make_pair("CC00 CCC", unique_ptr<Car>(new Car(5, 4, "CC00 CCC", "BMW", "320D", "01/07/2005"))));


  //fprintf_s(file, )


  ifstream readFromFile;
  string txtToWrite = "";
  string txtFromFile = "";
  



  void Serializer::save(){

  ofstream writeToFile;

  // carMap.insert(make_pair("AA00 AAA", unique_ptr<Car>(new Car(5, 4, "AA00 AAA", "Skoda", "Fabia", "01/07/1997"))));

  writeToFile.open("test.txt", ios_base::out | ios_base::trunc);
  if(writeToFile.is_open()){

   for (const auto& t : carMap){
     writeToFile << *(t.second);
   }
    writeToFile.close();
  }
};



  void Serializer::read(){
    ifstream readFromFile;
    readFromFile.open("test.txt", ios_base::in);
    if(readFromFile.is_open()){
      while(readFromFile.good()){
        getline(readFromFile, txtFromFile);
        cout << txtFromFile << "\n";
      }
      readFromFile.close();
    }

  }




