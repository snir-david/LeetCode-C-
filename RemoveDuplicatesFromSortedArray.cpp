//
// Created by SnirN on 1/27/2025.
//
#include <vector>
#include <cstdint>

class RemoveDuplicateFromSortedArray {
public:
  int removeDuplicates(std::vector<int>& nums) {
    int firstDupIdx = 0, twoDupIdx = firstDupIdx + 1;
    while(twoDupIdx < nums.size())
    {
      if(nums.at(firstDupIdx) == nums.at(twoDupIdx))
      {
        ++twoDupIdx;
      } else
      {
        if(firstDupIdx + 1 != twoDupIdx)
        {
          nums.at(firstDupIdx + 1) = nums.at(twoDupIdx);
        }
        ++firstDupIdx;
        ++twoDupIdx;
      }

    }
    return firstDupIdx + 1;
  }

  int removeDuplicates2(std::vector<int>& nums) {
    bool stillOk = true;
    int firstDupIdx = 0, twoDupIdx = firstDupIdx + 1;
    while(twoDupIdx < nums.size())
    {
      if(nums.at(firstDupIdx) == nums.at(twoDupIdx))
      {
        if(stillOk){
          nums.at(firstDupIdx + 1) = nums.at(twoDupIdx);
          ++firstDupIdx;
          stillOk = false;
        }
        ++twoDupIdx;
      }
      else
      {
        stillOk = true;
        if(firstDupIdx + 1 != twoDupIdx)
        {
          nums.at(firstDupIdx + 1) = nums.at(twoDupIdx);
        }
        ++firstDupIdx;
        ++twoDupIdx;
      }

    }
    return firstDupIdx + 1;
  }
};