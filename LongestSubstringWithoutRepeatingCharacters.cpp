//
// Created by SnirN on 31/01/2024.
//
#include <string>
#include <unordered_map>

class LSWRC {
public:
  int lengthOfLongestSubstring(std::string s) {
    int maxLen = 0, currentLen = 0;
    std::unordered_map<char, int> charsMap;
    for (size_t idx = 0; idx< s.size();) {
      auto charInMap = charsMap.find( s.at(idx));
      if (charInMap != charsMap.end()) {
        if (currentLen > maxLen) {
          maxLen = currentLen;
        }
        idx = charInMap->second + 1;
        currentLen = 0;
        charsMap.clear();
      }
      charsMap.insert({ s.at(idx), idx});
      ++currentLen;
      ++idx;
    }
    return std::max(maxLen, currentLen);
  }
};