class Solution {
std::vector<std::vector<int>> dp;

public:
    bool isMatch(string s, string p) {
        dp.assign(s.length() + 1, std::vector(p.length() + 1, -1));

        return dfs(0, 0, s, p);
    }

    bool dfs(int i, int j, std::string& s, std::string& p) {
        if (j == p.length()) return i == s.length();

        if (dp[i][j] != -1) return dp[i][j];

        dp[i][j] = false;
        bool match = i < s.length() && (s[i] == p[j] || p[j] == '.');
        if (j + 1 < p.length() && p[j + 1] == '*') {
            dp[i][j] = (match && dfs(i + 1, j, s, p)) || dfs(i, j + 2, s, p);
        }
        else if (match) {
            dp[i][j] = dfs(i + 1, j + 1, s, p);
        }

        return dp[i][j];

    }
};
