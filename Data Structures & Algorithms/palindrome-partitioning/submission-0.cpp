class Solution {
public:
    std::vector<std::vector<std::string>> result;

    vector<vector<string>> partition(string s) {
        std::vector<std::string> currentPartion;
        for (int i = 0; i < s.size(); ++i) {
            std::string subPar = s.substr(0, i + 1);
            if (!checkPalindrome(subPar)) continue;
            currentPartion.push_back(subPar);
            if (backtrackPartion(i + 1, currentPartion, s)) result.push_back(currentPartion);
            currentPartion.pop_back();
        }

        return result;
    }

private:

    bool backtrackPartion(int index, std::vector<std::string> &currentPartion, std::string s) {
        if (index == s.size()) {
            for (auto & str : currentPartion) {
                std::cout << str << " , ";
            }
            std::cout << '\n';
            return true;
        }

        for (int i = index; i < s.size(); ++i) {
            std::string subPar = s.substr(index, i + 1 - index);
            if (!checkPalindrome(subPar)) continue;
            currentPartion.push_back(subPar);
            if (backtrackPartion(i + 1, currentPartion, s)) (result.push_back(currentPartion));
            currentPartion.pop_back();
        }

        return false;
    }

    bool checkPalindrome(std::string s) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }

        return true;
    }
};
