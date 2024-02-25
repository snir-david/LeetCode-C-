//
// Created by SnirN on 2/18/2024.
//
#include <vector>
#include <queue>
#include <iostream>

class CSIII {

    void recursive(std::queue<int> q, std::vector<std::vector<int>> &sol, std::vector<int> currentSol, int k, int n) {
        if (k == 0 && n != 0) {
            return;
        } else if (n == 0 && k == 0) {
            sol.push_back(currentSol);
            return;
        }
        while (!q.empty()) {
            int currentNum = q.front();
            q.pop();
            if (currentNum <= n) {
                currentSol.push_back(currentNum);
                recursive(q, sol, currentSol, k - 1, n - currentNum);
                currentSol.pop_back();
            } else {
                break;
            }
        }
    }


public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        std::queue<int> queue;
        for (int i = 1; i < 10; i++) {
            queue.push(i);
        }

        std::vector<int> currentSol;
        std::vector<std::vector<int>> v;
        recursive(queue, v, currentSol, k, n);
        return v;
    }
};