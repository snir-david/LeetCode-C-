#include <string>
#include <stack>
#include <algorithm>

using std::string;

class RS {


    string getNextWord(const string& start, std::stack<string> &sol, char delimiter){
        if(start.empty())
            return "";
        if(start[0] == delimiter)
            return start.substr(1);
        size_t found = start.find(delimiter);
        if(found != std::string::npos){
            string subStr =  start.substr( 0, found );
            if(subStr[0] != delimiter)
                sol.push(start.substr( 0, found ));
            return start.substr( found + 1);
        }

        sol.push(start);
        return "";
    }


public:
    string reverseWords(string s) {
        std::stack<string> stack;
        string sTemp = s, solS = "";
        while(!sTemp.empty()){
            sTemp = getNextWord(sTemp, stack, ' ');
        }

        while(!stack.empty()){
            solS += stack.top() + " ";
            stack.pop();
        }
        return solS.substr(0, solS.size()-1);
    }
};