class Solution {
public:
bool isValid(const std::string &s) {
    std::unordered_map<char,char> closeToOpenMap {
        {')','('},
        {'}','{'},
        {']','['}
    };

    std::vector<char> stack;
    stack.reserve(s.size());

    for (char c : s) {
        if (closeToOpenMap.find(c) != closeToOpenMap.end()) {
            if (stack.empty() || closeToOpenMap.find(c)->second != stack.back()) return false;
            stack.pop_back();
        } 
        else {
            stack.push_back(c);
        }
    }

    return stack.empty();
}

};
