//
// Created by SnirN on 2/18/2024.
//

#include <string>

using std::string;


class LCS {
public:
    int longestCommonSubsequence(string text1, string text2) {
        size_t size1 = text1.size(), size2 = text2.size();
        int dp[size1][size2];
        dp[0][0] = (text1[0] == text2[0]);
        for(int j =1; j < size2; j++){
            dp[0][j] = dp[0][j-1] + (text1[0] == text2[j]);
        }
        for (int i = 0; i < size1; i++) {
            for (int j = 1; j < size2; j++) {
                dp[i][j] = dp[i][j - 1] + (text1[i] == text2[j]);
            }
        }
        return dp[size1][size2];
    }

};