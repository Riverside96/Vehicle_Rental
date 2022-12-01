#include "Serializer.h"
#include "Bike.h"
#include "Car.h"
#include "Inventory.h"
#include <dirent.h>
#include <iostream>
#include <memory>
#include <string>
#include <fstream>
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
} ;

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

// void Serializer::deleteFile(std::string dir, std::string file, std::string ext){
void Serializer::deleteFile(std::string file){
  std::string dir = "data/";
  std::string ext = ".dat";
  std::string toDelete = dir+file+ext;
  std::remove((toDelete).c_str());

}
