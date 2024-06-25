#include <string>
#include <vector>

using std::vector;
using std::string;

class GenerateParentheses {
public:
    void generateHelper(int left, int right, string str, vector<string> &solution) {
        if (left == 0 && right == 0) {
            solution.push_back(str);
            return;
        }
        if (right == 0 && left != 0) {
            return;
        }

        if (left > 0) {
            generateHelper(left-1, right, str + "(", solution);
        }
        if (right > left) {
            generateHelper(left, right-1, str + ")", solution);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> solution;
        generateHelper(n, n, "", solution);
        return solution;
    }

};