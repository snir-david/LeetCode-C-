#include <cstddef>
#include <vector>

using std::vector;

class MZ {

public:

    void swap(vector<int>& nums, int from, int to){
        while(from != to){
            int tmp = nums.at(from);
            nums[from] = nums.at(from +1);
            nums[from +1 ] = tmp;
            from += 1;
        }
    }

    void moveZeroes(vector<int>& nums) {
        size_t size = nums.size() - 1;
        int to = size;
        for(int i= size; i > 0 ; i--){
            if(!nums.at(i)){
                to = i - 1;
            }
            break;
        }
        int i = 0;
        while(i != to){
            if(!nums.at(i)){
                swap(nums, i, to);
                to -=1;
            } else {
                i++;
            }
        }
    }
};