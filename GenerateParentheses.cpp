//
// Created by SnirN on 2/15/2024.
//
#include <string>
#include <vector>
using std::vector;
using std::string;

 class GenerateParentheses {
 public:
     void generateParentheses(int n, int left, int right, string current, vector<string>& result) {
         if (left == n && right == n) {
             result.push_back(current);
             return;
         }

         if (left < n) {
             generateParentheses(n, left + 1, right, current + "(", result);
         }

         if (right < left) {
             generateParentheses(n, left, right + 1, current + ")", result);
         }
     }
     vector<string> generateParenthesis(int n) {
         vector<string> result;
         generateParentheses(n, 0, 0, "", result);
         return result;
     }
};