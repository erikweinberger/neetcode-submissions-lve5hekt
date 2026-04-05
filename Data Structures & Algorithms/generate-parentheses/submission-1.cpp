#include <string>
#include <vector>

class Solution {
private:
    std::vector<std::string> parenthesesResult;
    int n = 0;

    void generateParenthesisHelper(int open, int close, std::string &curr) {
        if (open == n && close == n) {
            parenthesesResult.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');
            generateParenthesisHelper(open + 1, close, curr);
            curr.pop_back();
        }

        if (open > close) {
            curr.push_back(')');
            generateParenthesisHelper(open, close + 1, curr);
            curr.pop_back();
        }
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        this->n = n;
        parenthesesResult.clear();
        std::string curr;
        curr.reserve(2 * n);
        generateParenthesisHelper(0, 0, curr);
        return parenthesesResult;
    }
};
