#pragma once

#include <string>
using namespace std;
class dateHelpers{

public:

  static int getYear();
  static int getYearFromDateString(string ddmmyyy);
  static bool checkdate(int d, int m, int y, int OLDEST_VALID_VEHICLE);

private:





};




