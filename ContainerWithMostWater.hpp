//
// Created by SnirN on 1/29/2025.
//

#ifndef LEETCODE_150_C___CONTAINERWITHMOSTWATER_HPP
#define LEETCODE_150_C___CONTAINERWITHMOSTWATER_HPP
#include <vector>
#include <cstdint>

class Solution {
public:
  int maxArea(std::vector<int>& height) {
    int max = 0, currentMax = 0;
    uint32_t left = 0, right = 0;
    while(right < height.size()){
      while(right < height.size() - 1 && height.at(left) >= height.at(right))
      {
        ++right;
      }
      int minHeight = std::min(height.at(left) , height.at(right));
      currentMax = minHeight * (right - left);
      if(currentMax > max ){
        max = currentMax;
      }
      left = right;
      right += 1;
    }
    return max;
  }
};
#endif // LEETCODE_150_C___CONTAINERWITHMOSTWATER_HPP
