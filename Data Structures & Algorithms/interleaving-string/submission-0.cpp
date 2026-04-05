class Solution {

std::vector<std::vector<int>> dp;

public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        dp.assign(s1.size() + 1, std::vector<int>(s2.size() + 1, -1));

        return dfs(0, 0, 0, s1, s2, s3) == 1;
    }

    int dfs(int i, int j, int k, std::string& s1, std::string& s2, std::string& s3) {
        if (i == s1.size() && j == s2.size()) {
            return 1;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (i < s1.size() && s1[i] == s3[k]) {
            dp[i][j] = dfs(i + 1, j, k + 1, s1, s2, s3) ;
        }

        if (j < s2.size() && s2[j] == s3[k]) {
            int res = dfs(i, j + 1, k + 1, s1, s2, s3);
            dp[i][j] = res == 1 ? res : dp[i][j];
        }

        if (dp[i][j] == -1) dp[i][j] = 0;


        return dp[i][j];
    }

};
