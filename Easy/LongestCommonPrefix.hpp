//
// Created by SnirN on 2/25/2025.
//

#ifndef LEETCODE_150_C___LONGESTCOMMONPREFIX_HPP
#define LEETCODE_150_C___LONGESTCOMMONPREFIX_HPP

#include <string>
#include <vector>
class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string>& strs) {
    std::string returnStr;
    bool stop = strs.empty();
    char currChar;
    uint8_t currIdx = 0;

    while(!stop && currIdx < (strs.at(0)).size()){
      currChar = (strs.at(0))[currIdx];
      for(auto &str: strs){
        if(currIdx > str.size() || currChar != str[currIdx]){
          stop = true;
        }
      }
      currIdx++;
      if(!stop){
        returnStr += currChar;
      }
    }
    return returnStr;
  }

  std::string longestCommonPrefix2(std::vector<std::string>& strs) {
    std::string returnStr;
    char currChar;
    uint8_t firstStrLen = strs.empty() ? 0 : (strs.at(0)).size();

    for(uint8_t currIdx = 0; currIdx < firstStrLen; ++currIdx){
      currChar = (strs.at(0))[currIdx];
      for(auto &str: strs){
        if(currIdx > str.size() || currChar != str[currIdx]){
          return returnStr;
        }
      }
      returnStr += currChar;
    }
    return returnStr;
  }
};
#endif // LEETCODE_150_C___LONGESTCOMMONPREFIX_HPP
