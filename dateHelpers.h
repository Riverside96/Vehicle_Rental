#pragma once

#include <string>
class dateHelpers{

public:

  static int getYear();
  static int getYearFromDateString(std::string ddmmyyy);
  static bool checkdate(int d, int m, int y, int OLDEST_VALID_VEHICLE);

private:





};




