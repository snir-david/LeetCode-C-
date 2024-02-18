//
// Created by SnirN on 2/12/2024.
//
#include <vector>
using std::vector;

class S2DM {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = (matrix.at(0)).size();
        int rowIdx = m - 1, colIdx = n - 1;
        for(int i = 0; i < m; ++i ){
            if(matrix[i][0] > target){
                rowIdx = i -1;
                if(rowIdx == -1){
                    return false;
                }
                break;
            }
        }
        for(int j = n/2; j < n || j > 0;){
            int currentVal = matrix[rowIdx][j];
            if(currentVal == target){
                colIdx = j;
                break;
            }
            else if (currentVal > target){
                j = j/2;
            } else {
                if( j == 0 || j == n - 1){
                    return false;
                }
                j = (n-j)/2 + j;
            }
        }
        return matrix[rowIdx][colIdx] == target;
    }
};