//
// Created by SnirN on 2/18/2025.
//

#ifndef LEETCODE_150_C___3SUMCLOSEST_HPP
#define LEETCODE_150_C___3SUMCLOSEST_HPP

#include <algorithm>
#include <cstdint>
#include <vector>

class Solution {
public:
  int twoPointersMethods(std::vector<int> &nums, int target, int excludeIdx) {
    int closestSum = (target > 0) ?-100001 : 100001;
    size_t left = 0, right = nums.size() - 1;
    while (left < right) {
      if (left == excludeIdx) {
        left++;
        continue;
      } else if (right == excludeIdx) {
        right--;
        continue;
      }

      int newSum = nums[left] + nums[right];
      bool isNewSumCloser = (target > 0) ? (closestSum - newSum) < 0 : (closestSum - newSum)
                                                                    > 0;
      if (isNewSumCloser) {
        closestSum = newSum;
      }

      if (newSum < target) {
        left++;
      } else if (newSum > target) {
        right--;
      }
    }
    return closestSum;
  }

  int threeSumClosest(std::vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    int closestSum = (target > 0) ?-100001 : 100001;


    for (size_t idx = 0; idx < nums.size(); idx++) {
      int newRes = twoPointersMethods(nums, target - nums.at(idx), idx) + nums.at(idx);
      bool isNewSumCloser = (target > 0) ? (closestSum - newRes) < 0 : (closestSum - newRes)
                                                                    > 0;
      if (isNewSumCloser) {
        closestSum = newRes;
      }
    }
    return closestSum;
  }
};
#endif // LEETCODE_150_C___3SUMCLOSEST_HPP
