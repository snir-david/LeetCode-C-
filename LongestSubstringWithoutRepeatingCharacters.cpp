//
// Created by SnirN on 31/01/2024.
//
#include <string>
#include <unordered_map>

class LSWRC {
public:
    int lengthOfLongestSubstring(std::string s) {
        int maxLen = 0;
        int startIdx = 0;
        std::unordered_map<char, int> hashMap;
        for (int endIdx = 0; endIdx < s.size(); endIdx++) {
            if (hashMap.find(s[endIdx]) != hashMap.end()) {
                startIdx = std::max(hashMap[s[endIdx]] + 1 , startIdx);
            }
            hashMap[s[endIdx]] = endIdx;
            maxLen = std::max(maxLen, endIdx - startIdx + 1);
        }
        return maxLen;
    }
};