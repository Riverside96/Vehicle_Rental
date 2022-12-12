#include "Serializer.h"
#include "Bike.h"
#include "Car.h"
#include "Inventory.h"
#include <bits/chrono.h>
#include <dirent.h>
#include <ios>
#include <iostream>
#include <list>
#include <memory>
#include <sstream>
#include <string>
#include <fstream>
#include "HistoryInstance.h"
#include "dateHelpers.h"
#include <chrono>
#include <filesystem>
#define MAX_LINES 1000

HistoryInstance** Serializer::read(std::string reg, int &nullHistArrSizeToReturn, std::shared_ptr<Inventory> inv){
      HistoryInstance** fileFailReturn = new HistoryInstance*[0];
      std::string fName, lName, address, contact, na, temp;
      std::string leaseStart, leaseEnd;
      int houseNum=0;
      int totalRentDays=0;
      bool failed(0);
      
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

      
      if(leaseEnd == "NA"){leaseEnd=dateHelpers::getCurrentDate();}   
      totalRentDays += dateHelpers::dateDifference(leaseStart, leaseEnd);
    
    auto histInstance = new HistoryInstance(reg, fName, lName, houseNum, address, contact, leaseStart, leaseEnd);
    histInstance->setTotalRentalDays(totalRentDays);
    histInstance->setTotalRentalCost(totalRentDays*(inv->getCostPerDay(reg)));
    dynamicHistoryStore[i] = histInstance;
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
  


  std::string vehicleType, registration, make, model, manufactured, na, temp, fileName;
  int seats, doors, numOfWheels, engineCC;

 // open directory
  DIR *dir; 
  struct dirent *entry;
  if((dir = opendir("./data")) != NULL){
    //loop through each file
    while((entry = readdir(dir)) != NULL) {
      //make sure file ! dir
      if (entry->d_type == DT_REG) {
        //open file
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
    closedir(dir);
  } else {
    std::cout << "Failed to open database, please contact system admin";
  }
}

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

void Serializer::setLeaseEndDate(std::string reg){
    std::string toReplace("NA");
    std::string replaceWith = dateHelpers::getCurrentDate();

    std::ifstream fileIn("data/history/"+reg+".his");
    std::ofstream fileOut("data/history/temp.txt");
    std::string strTemp;
    while (fileIn >> strTemp){
      if (strTemp == toReplace){
        strTemp = replaceWith;
    } strTemp += " ";
      fileOut << strTemp; 
  }
  fileIn.close();
  fileOut.close();

  std::string toDelete ("data/history/"+reg+".his");
  std::remove((toDelete).c_str());
  std::filesystem::rename("data/history/temp.txt", "data/history/"+reg+".his");
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

void Serializer::serialize(std::shared_ptr<HistoryInstance> historyinstance){
  std::string lastLine;
  std::ofstream file;
    file.open("data/history/"+historyinstance->getReg()+".his");
    file << *historyinstance; 
    file.close();
  }

void Serializer::deleteFile(std::string file){
  std::string dir = "data/";
  std::string ext = ".dat";
  std::string toDelete = dir+file+ext;
  std::remove((toDelete).c_str());

}
