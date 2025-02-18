//
// Created by SnirN on 01/02/2024.
//
#include <vector>
#include <algorithm>
class ThreeSum {


public:

  // 1 Naive approach - 3 nested loops - O(n^3).
  // 2. choose one number from the vector, reduction to 2Sum O(n) * O(n) = O
  // (n^2)
  // 3. same approach as 2sum - creat hash table in n^2 time and space - O
  // (n^2) + O(n) searching
  // 4. sort the array


    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

    }

};