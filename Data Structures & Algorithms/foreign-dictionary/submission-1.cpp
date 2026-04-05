class Solution {
public:
    std::unordered_map<char, std::unordered_set<char>> adjL;
    std::unordered_map<char, bool> visited;
    std::string result;

    string foreignDictionary(vector<string>& words) {


        for (const auto& w : words) {
            for (const auto& c : w) {
                adjL[c];
            }
        }

        for (int i{0}; i < words.size() - 1; ++i) {
            std::string& w1 = words[i];
            std::string& w2 = words[i + 1];

            int minLen = std::min(w1.length(), w2.length());
            if (w1.length() > w2.length() && w1.substr(0, minLen) == w2.substr(0, minLen)) {
                std::cerr << "Impossible\n";
                return "";
            }

            for (int j{0}; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    adjL[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }

        for (const auto& [key, val] : adjL) {
            std::cerr << key << ": ";
            for (const auto& c : val) {
                std::cerr << c << ", ";
            }
            std::cerr << '\n';
        }

        for (const auto& pair : adjL) {
            if (dfsCycle(pair.first)) {
                return "";
            }
        }

        std::reverse(result.begin(), result.end());
        return result;
    }


    bool dfsCycle(char ch) {
        if (visited.find(ch) != visited.end()) {
            return visited[ch];
        }

        visited[ch] = true;
        for (char next : adjL[ch]) {
            if (dfsCycle(next)) {
                return true;
            }
        }
        visited[ch] = false;
        result.push_back(ch);
        return false;
    }
};
