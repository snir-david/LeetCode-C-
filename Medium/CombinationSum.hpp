//
// Created by SnirN on 2/18/2025.
//

#ifndef LEETCODE_150_C___COMBINATIONSUM_HPP
#define LEETCODE_150_C___COMBINATIONSUM_HPP

//You are given an array of distinct integers nums and a target integer target.
// Your task is to return a list of all unique combinations of nums where the chosen numbers sum to target.
//The same number may be chosen from nums an unlimited number of times.
// Two combinations are the same if the frequency of each of the chosen numbers is the same, otherwise they are different.
//You may return the combinations in any order and the order of the numbers in each combination can be in any order.

#include <vector>
using std::vector;

class Solution {
public:

  void helper(vector<int>& nums, int target, vector<vector<int>> &sol, vector<int>& currSol, int idx)
  {
    if(target == 0)
    {
      sol.push_back(currSol);
      return;
    } else if (target < 0)
    {
      return;
    }

    for(; idx < nums.size();++idx)
    {
      currSol.push_back(nums.at(idx));
      helper(nums, target - nums.at(idx), sol, currSol, idx);
      currSol.pop_back();
    }
  }

  vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> sol;
    vector<int> currSol;
    helper(nums, target, sol, currSol, 0);
    return sol;
  }
};

#endif // LEETCODE_150_C___COMBINATIONSUM_HPP
