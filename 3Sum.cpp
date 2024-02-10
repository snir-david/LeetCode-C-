//
// Created by SnirN on 01/02/2024.
//
#include <vector>
#include <set>
#include <cstddef>

class ThreeSum {


public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::set<std::vector<int>> set;
        size_t numsSize = nums.size();
        int matrix[numsSize][numsSize];
        for(int i=0; i < numsSize; i++){
            for(int j=i+1; j < numsSize; j++){
                for(int k=j+1; k < numsSize; k++){
                    if(nums.at(i) + nums.at(j) +nums.at(k) == 0){
                        std::vector<int> currentSum = {nums.at(i) , nums.at(j) ,nums.at(k)};
                        set.insert({nums.at(i) , nums.at(j) ,nums.at(k)});
                    }
                }
            }
        }
        std::vector<std::vector<int>> sol(set.begin(), set.end());
        return sol;
    }

};