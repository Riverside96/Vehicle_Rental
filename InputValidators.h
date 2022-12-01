#pragma once
#include <string>
class InputValidators {
public:
  static bool validateReg(std::string input);
  static bool isDeciderValid(char decider);
  static int levenshteinDistance(std::string word1, std::string word2);
};



