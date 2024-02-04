#include <iostream>

using std::string;

class InterleavingStringSol {
public:
    bool isInterleave(string s1, string s2, string s3) {
        bool res = false;
        if((s1.size() + s2.size()) != s3.size()){
            return false;
        }
        if (s3.empty() && s2.empty() && s1.empty()){
            return true;
        }
        if (s1[0] == s3[0]) {
            res |= isInterleave(s1.substr(1), s2, s3.substr(1));
        }
        if (s2[0] == s3[0]) {
            res |= isInterleave(s1, s2.substr(1), s3.substr(1));
        }
        return res;
    }
};


