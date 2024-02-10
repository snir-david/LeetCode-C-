//
// Created by SnirN on 2/9/2024.
//

#include <vector>
using std::vector;

class MS {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int size = nums.size(), maxSum = nums.at(0);
        int matrix[size][size];
        for(int i =0; i < size; i++){
            matrix[i][i] = nums.at(i);
            if(matrix[i][i] > maxSum) {
                maxSum = matrix[i][i];
            }
            for(int j =i+1; j < size; j++){
                matrix[i][j] = matrix[i][j-1] + nums.at(j);
                if(matrix[i][j] > maxSum){
                    maxSum = matrix[i][j];
                }
            }
        }
        return maxSum;
    }
};