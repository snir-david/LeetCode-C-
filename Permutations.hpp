//
// Created by SnirN on 1/28/2025.
//

#ifndef LEETCODE_150_C___PERMUTATIONS_HPP
#define LEETCODE_150_C___PERMUTATIONS_HPP
#include <vector>
class Permutations {
public:

  void helper(std::vector<int>& nums, std::vector<int>& currentSol,
              std::vector<std::vector<int>> sol)
  {
    if(nums.empty()){
      sol.push_back(currentSol);
      return;
    }
    int currentNum = nums.back();
    nums.pop_back();
    currentSol.push_back(currentNum);
    helper(nums, currentSol, sol);
    currentSol.pop_back();
    nums.push_back(currentNum);
  }

  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> sol;
    std::vector<int> currentSol;
    helper(nums, currentSol, sol);
    return sol;
  }
};
#endif // LEETCODE_150_C___PERMUTATIONS_HPP
