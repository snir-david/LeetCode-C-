#include <vector>
#include <cstddef>
#include <valarray>

using std::vector;

class JGII {
public:

    void helper(vector<vector<int>> &sol, vector<int> currentSol,vector<int>& nums, int currentIdx){
        if(currentIdx >= nums.size() - 1){
            sol.push_back(currentSol);
            return;
        }
        int maxCurrentJump = nums.at(currentIdx);
        for(int i = 1; i <= maxCurrentJump; i++){
            currentSol.push_back(i);
            helper(sol, currentSol, nums, currentIdx +i);
            currentSol.pop_back();
        }

    }

    int jump(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> currSol;
        helper(sol, currSol, nums, 0);
        int minSize = pow(10,4), currentSize = 0;
        for(auto & i : sol){
            currentSize = i.size();
            if(minSize > currentSize){
                minSize = currentSize;
            }
        }
        return minSize;
    }
};