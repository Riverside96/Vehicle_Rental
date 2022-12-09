#include "dateHelpers.h"
#include <ctime>
#include <string>

//try to include timeNow at end of regex


std::string dateHelpers::getCurrentDate(){
  time_t test = time(0);
  tm *gotTime = localtime(&test);
  std::string year = std::to_string(gotTime->tm_year + 1900);
  std::string month = std::to_string(gotTime->tm_mon + 1);
  std::string day = std::to_string(gotTime->tm_mday);

  return year+"/"+month+"/"+day;
}


   int dateHelpers::getYear(){
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    // int year = ((timePtr->tm_year) +1900) % 100 ;
    int year = ((timePtr->tm_year) +1900);
    return year;
}
   int dateHelpers::getYearFromDateString(std::string ddmmyyyy){

  int extractYearAsInt = stoi(ddmmyyyy.substr(4, 7));
  return extractYearAsInt;

}


  bool dateHelpers::checkdate(int d, int m, int y, int OLDEST_VALID_VEHICLE_YYYY) {
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

  void dateHelpers::strToYYYYMMDD(std::string dateString, int &y, int &m, int &d){
   

   y = stoi(dateString.substr(0, 4));
   m = stoi(dateString.substr(6, 7));
   d = stoi(dateString.substr(8, 9));
}




