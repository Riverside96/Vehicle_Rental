#include "dateHelpers.h"
#include <string>

//try to include timeNow at end of regex


   int dateHelpers::getYear(){
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    // int year = ((timePtr->tm_year) +1900) % 100 ;
    int year = ((timePtr->tm_year) +1900);
    return year;
}
   int dateHelpers::getYearFromDateString(string ddmmyyyy){

//std::regex dateValidator ("^[1-31]{1}[/]{1}[1-12]{1}[/]{1}[1-9]{2}$");
//bool found = regex_match(testing, dateValidator);
//return (found) ? 2 : 3;
  //string testing = ("1/7/1996");
  //
  // string extractDate = ddmmyyyy.substr(4,  7);
  // int output = stoi(extractDate);
  // return output;

  int extractYearAsInt = stoi(ddmmyyyy.substr(4, 7));
  return extractYearAsInt;

}


