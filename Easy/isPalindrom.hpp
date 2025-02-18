//
// Created by SnirN on 2/9/2025.
//

#ifndef LEETCODE_150_C___ISPALINDROM_HPP
#define LEETCODE_150_C___ISPALINDROM_HPP
#include <string>
#include <algorithm>
class Solution {
public:

  bool isValidChar(char c)
  {
    return 'a' <= c && c <= 'z';
  }

  bool isPalindrome(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),::tolower);
    auto start = s.begin() , end = --s.end();
        while(start != end && start > end)
        {
          if(!isValidChar(*start)){
            start++;
            continue;
          }
          if(!isValidChar(*end)){
            end--;
            continue;
          }
          if(*start != *end)
          {
            return false;
          }
          start++;
          end--;
        }
        return true;
  }
};
#endif // LEETCODE_150_C___ISPALINDROM_HPP
