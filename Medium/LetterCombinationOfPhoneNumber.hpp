//
// Created by SnirN on 2/16/2024.
//

#include <string>
#include <vector>

using std::vector;
using std::string;

class LCOPN {
public:

    void recursive(string &digits, string &currentString, vector<string> &sol) {
        if(digits.empty()){
            sol.push_back(currentString);
            return;
        }
        vector<vector<char>> digistToChar = {{},
                                             {'a', 'b', 'c'},
                                             {'d', 'e', 'f'},
                                             {'g', 'h', 'i'},
                                             {'j', 'k', 'l'},
                                             {'m', 'n', 'o'},
                                             {'p','q', 'r', 's'},
                                             {'t', 'u', 'v'},
                                             {'w','x', 'y', 'z'}};
        char c = digits[0];
        int currentDigit = std::stoi(&c) - 1;
        vector<char> currentDigitsLetter = digistToChar.at(currentDigit);
        while(!currentDigitsLetter.empty()){
            currentString += currentDigitsLetter.back();
            string newDigits = digits.substr(1);
            recursive(newDigits , currentString, sol);
            currentString.pop_back();
            currentDigitsLetter.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> sol;
        string s = "";
        recursive(digits, s, sol);
        return sol;
    }
};

class Solution {
public:

  void helper(string &digits, vector<string> &sol, size_t currentIdx, string& currCombi){
    if(currentIdx >= digits.size()){
      if(!currCombi.empty()){
        sol.push_back(currCombi);
      }
      return;
    }
    char c = digits[currentIdx];
    int currDigit = std::stoi(&c);
    for(char digitIdx : digits2letters.at(currDigit - 2))
    {
      currCombi.push_back(digitIdx);
      helper(digits, sol, currentIdx + 1, currCombi);
      currCombi.pop_back();
    }
  }

  vector<string> letterCombinations(string digits) {
    vector<string> sol;
    string currStr;
    helper(digits, sol, 0, currStr);
    return sol;
  }

private:
  std::vector<std::vector<char>> digits2letters = {
      {'a', 'b', 'c'},
      {'d', 'e', 'f'},
      {'g', 'h', 'i'},
      {'j', 'k', 'l'},
      {'m', 'n', 'o'},
      {'p', 'q', 'r', 's'},
      {'t', 'u', 'v'},
      {'w', 'x', 'y', 'z'}};
};
