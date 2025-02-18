#include "./Medium/3SumClosest.hpp"
#include <cstring>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

using std::vector;

std::string encode(std::string &str){
  std::string newStr;
  char currChar;
  int tempIdx, counter = 0;
  for (int i = 0; i < str.size();){
    counter = 1;
    currChar = str[i];

    while (tempIdx < str.size() && currChar == str[tempIdx]){
      counter++;
      tempIdx++;
    }

    i = tempIdx;
    tempIdx = i + 1;

    if(counter > 1){
      newStr += std::to_string(counter);
    }
    newStr += currChar;
  }
  return  newStr;
}

int main() {
  auto solve = Solution();
  std::vector<int> vec = {0,1,2};
  std::string word = "a";
  std::string n = encode(word);
  solve.threeSumClosest(vec , 1);
}
