#include "Serializer.h"
#include "Bike.h"
#include "Car.h"
#include "Inventory.h"
#include <bits/chrono.h>
#include <dirent.h>
#include <iostream>
#include <list>
#include <memory>
#include <sstream>
#include <string>
#include <fstream>
#include "HistoryInstance.h"
#include "dateHelpers.h"
#include <chrono>
#define MAX_LINES 1000


HistoryInstance** Serializer::read(std::string reg, int &nullHistArrSizeToReturn, std::shared_ptr<Inventory> inv){
      // HistoryInstance test;
      // std::list<std::shared_ptr<HistoryInstance>> historyList;
      
      HistoryInstance** fileFailReturn = new HistoryInstance*[0];
      std::string fName, lName, address, contact, na, temp;
      std::string leaseStart, leaseEnd;
      int houseNum=0;
      // std::chrono::sys_days totalRentalDays;
      int totalRentDays=0;
      int totalRentalIncome=0;
      bool failed;
      
      
      std::string array[MAX_LINES];

  
        std::ifstream infile;
        infile.open("data/history/"+reg+".his");
        if (infile.fail()){
          std::cout << "This vehicle has no history/file failed to open" << std::endl;
          bool failed = true;
          return fileFailReturn;
       } else {
          if (failed==true){return fileFailReturn;}
          int lines(0);
          while(!infile.eof()){
            std::getline(infile, array[lines]);
            lines++;
            
            if (lines==MAX_LINES){
              std::cout << "Storage maxed" << std::endl; break;
      }
      } 
      nullHistArrSizeToReturn = lines-1;   // -1?
      infile.close();

      HistoryInstance** dynamicHistoryStore = new HistoryInstance*[lines-1];

      for(int i = 0; i<lines-1; i++){


        std::istringstream iss(array[i]);
        std::string temp;
        iss >> fName >> lName >> houseNum 
        >> temp >> address 
        >> contact >> leaseStart >> leaseEnd;
        address = temp + " " + address;  

        std::cout << leaseStart << "      ";
        std::cout << leaseEnd << "       ";

      //get date difference for each entry & accumulate
      if(leaseEnd == "NA"){leaseEnd=dateHelpers::getCurrentDate();}
      int startY, startM, startD;
      int endY, endM, endD;
      dateHelpers::strToYYYYMMDD(leaseStart, startY, startM, startD);
      dateHelpers::strToYYYYMMDD(leaseEnd, endY, endM, endD);


      std::cout << "start y: " << startY << "\n";
      std::cout << "start m: " << startM << "\n";
      std::cout << "start d: " << startD << "\n";
      std::cout << "end y: " << endY << "\n";
      std::cout << "end m: " << endM << "\n";
      std::cout << "end d: " << endD << "\n";

      auto start = std::chrono::year{startY}/startM/startD;
      auto end = std::chrono::year{endY}/endM/endD;
      int rentalDays = (std::chrono::sys_days{end} - std::chrono::sys_days{start}).count();
      totalRentDays += rentalDays;
    
    auto histInstance = HistoryInstance(reg, fName, lName, houseNum, address, contact, leaseStart, leaseEnd);
    histInstance.setTotalRentalDays(totalRentDays);
    histInstance.setTotalRentalCost(totalRentDays*(inv->getCostPerDay(reg)));
    dynamicHistoryStore[i] = &histInstance;
    }
    return dynamicHistoryStore;
   }
   return 0;    
  }


void Serializer::read(std::shared_ptr<Inventory> inventory){
  std::list<std::string> t;
    t.emplace_back("Vectra");
    t.emplace_back("Astra");
    t.emplace_back("Insignia");
    inventory->addValidModel("Vauxhall",t);

    std::list<std::string> temp2;
    temp2.emplace_back("Outback");
    temp2.emplace_back("Forester");
    temp2.emplace_back("Impreza");
    inventory->addValidModel("Subaru",temp2);

    std::list<std::string> temp3;
    temp3.emplace_back("Polo");
    temp3.emplace_back("Passat");
    temp3.emplace_back("Scirocco");
    inventory->addValidModel("VW",temp3);
  

  std::string vehicleType, registration, make, model, manufactured, na, temp;
  int seats, doors, numOfWheels, engineCC;

   std::string fileName;
    std::ifstream infile;
    DIR* directory;
    struct dirent *entry;
    directory = opendir("./data");
    if (directory == NULL){
      std::cout << "Error opening database, please contact administrator";
  }
    while ((entry = readdir(directory)) != NULL){
      // if file not parent dir
      if (entry->d_type == DT_REG){
        fileName = entry->d_name;

        std::ifstream infile;
        infile.open("data/"+fileName);
        if (infile.is_open()){
          infile >> vehicleType; infile >> na;
          infile >> registration; infile >> temp; registration = registration + " " + temp; infile >> na; 
          infile >> make; infile >>na;
          infile >> model; infile >> na;
          infile >> manufactured; infile >> na;

          if(vehicleType == "Car"){
            infile >> seats; infile >> na;
            infile >> doors;
            inventory->add(std::make_unique<Car>(registration, make, model, manufactured, doors, seats));
        } else {
            infile >> numOfWheels; infile >> na;
            infile >> engineCC;
            inventory->add(std::make_unique<Bike>(registration, make, model, manufactured, numOfWheels, engineCC));
        }
      }
    }
  }
  closedir(directory);
};

void Serializer::readHistorySet(std::shared_ptr<Inventory> inventory){
  std::string reg, space, reg2, na, complete;
  std::ifstream infile;
  infile.open("data/hasHistory/set.txt");
  if(!infile.is_open()){
    std::cout << "Database error, contact admin.";
    return;
  } else {
    do {
      std::getline(infile, reg);
      inventory->addHasHistory(reg);
    }while(!infile.eof());
  }
}


void Serializer::writeHistorySet(std::set<std::string> hasHistorySet){
  std::ofstream file;
  file.open("data/hasHistory/set.txt");
  for (const auto& reg : hasHistorySet){
    file << reg << "\n";
  }
}

void Serializer::writeCurrentlyLeasedSet(std::set<std::string> currentlyLeasedSet){
  std::ofstream file;
  file.open("data/currentlyLeased/leased.txt");
  for (const auto& reg : currentlyLeasedSet){
    file << reg << "\n";
  }
}


void Serializer::readCurrentlyLeasedSet(std::shared_ptr<Inventory> inventory){
  std::string reg, space, reg2, na, complete;
  std::ifstream infile;
  infile.open("data/currentlyLeased/leased.txt");
  if(!infile.is_open()){
    std::cout << "Database error, contact admin.";
    return;
  } else {
    do {
      std::getline(infile, reg);
      inventory->addCurrentlyLeased(reg);
    }while(!infile.eof());
  }
}






void Serializer::serialize(std::unordered_map<std::string, std::shared_ptr<Vehicle>> mapVehiclesByReg){
  std::ofstream file;
  for (const auto& [reg, vehicle] : mapVehiclesByReg) {
    file.open("data/"+reg+".dat");
    file << vehicle->getTypeName(); 
    file << " "<<*vehicle;
    file << "\n";
    file.close();
  }
}

//first deserialize last line. Check if LeaseEnd = ""
//if so output this car is currently on loan
//otherwise go to last line & serialize AFTER the last line

void Serializer::serialize(std::unique_ptr<HistoryInstance> historyinstance){
  
  std::string lastLine;
  std::ofstream file;
    file.open("data/history/"+historyinstance->getReg()+".his");
    file << *historyinstance; 
    file.close();
  }


// void Serializer::deleteFile(std::string dir, std::string file, std::string ext){
void Serializer::deleteFile(std::string file){
  std::string dir = "data/";
  std::string ext = ".dat";
  std::string toDelete = dir+file+ext;
  std::remove((toDelete).c_str());

}
