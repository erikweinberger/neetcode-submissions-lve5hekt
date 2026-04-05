class Solution {

std::vector<std::vector<int>> dp;

public:
    int numDistinct(string s, string t) {
        dp.assign(s.length(), std::vector<int>(t.length(), -1));
        
        if (s.length() < t.length()) return 0;
        return dfs(0, 0, s, t);
    }

    int dfs(int i, int j, std::string& s, std::string& t) {
        if (j == t.length()) return 1;
        if (i == s.size()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int res = dfs(i + 1, j, s, t);
        if (s[i] == t[j]) {
            res += dfs(i + 1, j + 1, s, t);
        }

        dp[i][j] = res;
        return dp[i][j];
    }
};
