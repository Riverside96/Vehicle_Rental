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
    return bool (decider == 'y' || decider == 'n') ? true : false; 
}

  int InputValidators::levenshteinDistance(std::string word1, std::string word2){
    std::vector<std::vector<int>> matrix(word2.size() +1 , std::vector<int>(word1.size() +1, 0));

    for (int i = 0; i < matrix.size(); ++i) {
      matrix[i][0] = i;
    }
    for (int i = 0; i < matrix[0].size(); ++i) {
      matrix[0][i] = i;
    }
    for (int row = 1; row < matrix.size(); ++row){
      for (int col = 1; col < matrix[0].size(); ++col){
        if (word1[col-1] == word2[row-1]){                //account for extra " " elementb
          matrix[row][col] = matrix[row-1][col-1];
        } else {
          matrix[row][col] = std::min({matrix[row][col-1], matrix[row-1][col], matrix[row-1][col-1]})+1;
        }
      }
    }
    return matrix[matrix.size()-1][matrix[0].size()-1];
  }





