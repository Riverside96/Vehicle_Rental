#include "InputValidators.h"
#include <regex>

  bool InputValidators::validateReg(std::string input){
  std::regex carRegRegex ("^[A-Z]{2}[0-9]{2}\\s[A-Z]{3}$");
  //return bool (regex_match(input, carRegRegex)) ? false : true;
  std::smatch match; // dont think this is necassaRY
  bool found = regex_match(input, carRegRegex);
  return found;
};

  
  bool InputValidators::isDeciderValid(char decider){
    return bool (decider == 'y' || decider == 'n') ? true : false; }




