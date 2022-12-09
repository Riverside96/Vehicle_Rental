#pragma once 
#include <cstdlib>
#include <string>
#include <iostream>
class HistoryInstance{
    public:
    HistoryInstance();
    HistoryInstance(std::string reg, std::string &fName, std::string &lName, int houseNum, std::string &address, std::string &contact); 
    HistoryInstance(std::string reg, std::string &fName, std::string &lName, int houseNum, std::string &address, std::string &contact, std::string &leaseStart, std::string &leaseEnd); 
  friend std::ostream& operator<<(std::ostream& os, const HistoryInstance& hi);
    std::string getReg();

    void setTotalRentalDays(int totalDays);
    void setTotalRentalCost(double totalCost);
    int getTotalRentalDays();
    double getTotalRentalCost();
    


    private:
      int houseNum;
      std::string reg, fName, lName, address, contact, leaseStart, leaseEnd;
      int totalRentalDays;
      double totalRentalCost;
      // std::time_t leaseStart, leaseEnd;
  };



