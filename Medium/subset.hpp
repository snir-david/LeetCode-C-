//
// Created by SnirN on 2/9/2025.
//

#ifndef LEETCODE_150_C___SUBSET_HPP
#define LEETCODE_150_C___SUBSET_HPP
#include <algorithm>
#include <vector>
using std::vector;
class Solution {
public:

  void helper(vector<int>& nums, vector<int>& subset, vector<vector<int>>
                                                          &sol, int idx)
  {
    sol.push_back(subset);
    if(idx >= nums.size()){
      return;
    }
    for(; idx< nums.size(); ++idx)
    {
      subset.push_back(nums.at(idx));
      helper(nums, subset, sol, idx + 1);
      subset.pop_back();
    }
  }

  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> sol;
    vector<int> subset;
    helper(nums, subset, sol, 0);
    return sol;
  }
};

#endif // LEETCODE_150_C___SUBSET_HPP
