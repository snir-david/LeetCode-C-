//
// Created by SnirN on 31/01/2024.
//
#include <string>
#include <vector>
class LPS {
public:

    void helper(int *startIdx, int *size, std::string s){
        if(s.empty() || s.size() == 1)
            return;
        if(s[0] == s[s.size()-1]){
            *size += 1;
            return helper(startIdx, size, s.substr(1, s.size() - 2));
        }
        helper(startIdx, size, s.substr(1));
        helper(startIdx, size, s.substr(1));
    }

    std::string longestPalindrome(std::string s) {
        int startIdx = 0, size = 0;
        helper(&startIdx, &size, s);
        return s.substr(startIdx, size);
    }
};