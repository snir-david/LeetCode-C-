//
// Created by SnirN on 2/18/2024.
//
#include <vector>
#include <set>
#include <algorithm>
using std::vector;
class PII {
public:
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums.at(i);
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    void recursive(vector<int>& nums, std::set<vector<int>> &sol, int start, int end){
        if(start == end){
            sol.insert(nums);
            return;
        }
        for(int i = start; start <= end; start++){
            swap(nums, start, i);
            recursive(nums, sol,  i + 1, end);
            swap(nums, start, i);
        }

    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::set<vector<int>> sol;
        sort(nums.begin(), nums.end());
        recursive(nums, sol, 0, nums.size() -1);
        vector<vector<int>> v(sol.begin(), sol.end());
        return v;
    }
};