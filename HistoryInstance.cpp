#include "HistoryInstance.h"
#include "dateHelpers.h"
#include <chrono>
#include <ctime>
#include <iomanip>
HistoryInstance::HistoryInstance(std::string reg, std::string &fName, std::string &lName, int houseNum, std::string &address, std::string &contact){
 this->reg = reg, this->fName=fName, this->lName=lName, this->houseNum=houseNum, this->address=address, this->contact=contact;
 this->leaseStart = dateHelpers::getCurrentDate();
 
  this->leaseEnd = "NA";
};

HistoryInstance::HistoryInstance(std::string reg, std::string &fName, std::string &lName, int houseNum, std::string &address, std::string &contact, std::string &leaseStart, std::string &leaseEnd)
:fName(fName), lName(lName), houseNum(houseNum), address(address), contact(contact), leaseStart(leaseStart), leaseEnd(leaseEnd){
}; 

  void HistoryInstance::setTotalRentalDays(int totalDays){totalRentalDays=totalDays;}
  void HistoryInstance::setTotalRentalCost(double totalCost){totalRentalCost=totalCost;}
  int HistoryInstance::getTotalRentalDays(){return totalRentalDays;}
  double HistoryInstance::getTotalRentalCost(){return totalRentalCost;}



std::string HistoryInstance::getReg(){return reg;};

std::ostream& operator<<(std::ostream& os, const HistoryInstance& hi){
  os 
     << hi.fName << " "
     << hi.lName << " "
     << hi.houseNum << " "
     << hi.address << " "
     << hi.contact << " "
     << hi.leaseStart << " "
     << hi.leaseEnd << "\n";
     return os;
}


