//
// Created by SnirN on 2/12/2024.
//
class UP {
public:
    void helper(int m, int n, int currentRow, int currentCol, int &numOfPaths){
        if(currentRow >= m || currentCol >= n){
            return;
        }
        if(currentRow == m - 1 && currentCol == n -1){
            numOfPaths += 1;
        }
        helper(m,n ,currentRow +1 , currentCol, numOfPaths);
        helper(m,n ,currentRow , currentCol +1, numOfPaths);
    }

    int uniquePaths(int m, int n) {
        int solution = 0;
        helper(m,n, 0 ,0 , solution);
        return solution;

    }
};