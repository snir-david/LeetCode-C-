//
// Created by SnirN on 02/02/2024.
//
#include <vector>
#include <set>
class CS {
public:
    void helper(std::vector<int>& candidates, int target, std::set<std::vector<int>> &sol, int currentCandidate, std::vector<int> currentSol){

        if(currentCandidate > candidates.size() - 1)
            return;
        int current = candidates.at(currentCandidate);
        if(current <= target){
            currentSol.push_back(current);
            if(current - target == 0){
                sol.insert(currentSol);
            } else {
                helper(candidates , target - current, sol, currentCandidate, currentSol);
                helper(candidates , target - current, sol, currentCandidate + 1 , currentSol);
            }
            currentSol.pop_back();
        }
        helper(candidates , target, sol, currentCandidate + 1 , currentSol);
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::set<std::vector<int>> sol;
        std::vector<int> c;
        // edge case -empty candidates, target smaller than all candidates, target equal to 0
        helper(candidates, target, sol, 0, c);
        return {sol.begin(), sol.end()};
    }
};