//
// Created by SnirN on 01/02/2024.
//
#include <string>
#include <vector>
#include <utility>

class ITR {
public:
    std::string intToRoman(int num) {
        std::vector<std::pair<int, std::string>> list = {
                {1,    "I"},
                {4,    "IV"},
                {5,    "V"},
                {9,    "IX"},
                {10,   "X"},
                {40,   "XL"},
                {50,   "L"},
                {90,   "XC"},
                {100,  "C"},
                {400,  "CD"},
                {500,  "D"},
                {900,  "CM"},
                {1000, "M"}
        };
        auto it = list.rbegin();
        int div = 0;
        std::string s;
        while (it != list.rend()) {
            div = num / it->first;
            if (div > 0) {
                s += it->second;
                num = num - it->first;
            } else {
                it++;
            }
        }
        return s;
    }
};


