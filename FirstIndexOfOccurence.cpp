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
};