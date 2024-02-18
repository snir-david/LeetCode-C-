//
// Created by SnirN on 2/16/2024.
//

#include <string>
using std::string;

class MS {
public:
    string mergeAlternately(string word1, string word2) {
        size_t size1= word1.size(), size2= word2.size();
        size_t common = (size1>size2) ? size2 : size1;
        string mergedString;
        for(int i = 0; i < common; i++){
            mergedString += word1[i];
            mergedString += word2[i];
        }
        string restString = (size1>size2)? word1.substr(common) : word2.substr(common);
        mergedString += restString;
        return mergedString;
    }
};