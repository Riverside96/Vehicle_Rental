#pragma once

#include <string>
class dateHelpers{

public:


  static std::string getCurrentDate();
  static int getYear();
  static int getYearFromDateString(std::string ddmmyyy);
  static bool checkdate(int d, int m, int y, int OLDEST_VALID_VEHICLE);
  static void strToYYYYMMDD(std::string dateString, int &y, int &m, int &d);
private:





};




