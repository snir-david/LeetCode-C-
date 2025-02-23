//
// Created by SnirN on 03/02/2024.
//
#include <string>
using std::string;

class FIFO {
public:
    int strStr(string haystack, string needle) {
        int idx = -1;
        int j = 0;
        for(int i =0 ; i < haystack.size(); i++){
            if(haystack[i] == needle[j]){
                if (j == 0){
                    idx = i;
                }
                if (j == needle.size() -1){
                    break;
                }
                j++;
                continue;
            }
            j = 0;
            idx = -1;
        }
        return idx;
    }

      int strStr2(string haystack, string needle) {
        size_t stringIdx = 0, needleLen = needle.size(), stringLen = haystack.size();
        int found = -1;
        while(stringIdx + needleLen <= stringLen){
          std::string currentStr = haystack.substr(stringIdx, needleLen);
          if(currentStr == needle)
          {
            found = stringIdx;
            break;
          }
          stringIdx++;
        }

        return found;
      }
};