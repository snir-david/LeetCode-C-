//
// Created by SnirN on 01/02/2024.
//
#include <vector>
#include <iostream>
class SRSA {
public:
    int findPivotIdx(std::vector<int>& nums){
        if(nums.front()< nums.back()){
            return -1;
        }
        int mid;
        int startIdx = 0 , endIdx = nums.size() - 1, midValue;
        int startValue = nums.front(), endValue = nums.back();
        int idx = -1;
        bool found = false;
        while(!found){
            mid = ((endIdx - startIdx) / 2) + ((endIdx - startIdx) % 2) + startIdx;
            midValue = nums.at(mid);
            if(midValue < nums.at(mid -1)){
                idx = mid;
                found = true;
            }
            if(midValue > startValue){
                startIdx = mid;
                startValue = midValue;
            } else {
                endIdx = mid;
                endValue = midValue;
            }

        }
        return idx;

    }

    int BSTSearch(std::vector<int>& nums, int target, int startIdx, int endIdx){
        if(nums.at(startIdx) == target){
            return startIdx;
        }
        int mid = ((endIdx - startIdx) / 2) + ((endIdx - startIdx) % 2) + startIdx;
        int midValue = nums.at(mid);
        if(midValue == target){
            return mid;
        }
        if(mid == endIdx){
            return -1;
        }
        if(target > midValue){
            return BSTSearch( nums, target, mid + 1, endIdx);
        } else {
            return BSTSearch( nums, target, startIdx, mid);
        }
    }

    int search(std::vector<int>& nums, int target) {
        if(nums.size() == 0){
            return -1;
        }
        if(nums.size() == 1){
            return (nums.at(0) == target)? 0 : -1;
        }
        int pivotIdx = findPivotIdx(nums);
        if(pivotIdx != -1){
            int pivotVal = nums.at(pivotIdx);
            if(target == pivotVal)
                return pivotIdx;
            if ( nums.back() >= target && target> pivotVal){
                return BSTSearch(nums, target, pivotIdx + 1, nums.size()-1);
            } else {
                return BSTSearch(nums, target, 0, pivotIdx);
            }
        } else {
            return BSTSearch(nums, target, 0, nums.size()-1);
        }

    }
};