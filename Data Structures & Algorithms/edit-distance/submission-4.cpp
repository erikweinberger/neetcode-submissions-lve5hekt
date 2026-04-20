class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

        for (int i{}; i < m; ++i) {
            dp[n][i] = m - i;
        }

        for (int i{}; i < n; ++i) {
            dp[i][m] = n - i;
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    int deleteVal = 1 + dp[i + 1][j + 1];
                    int replaceVal = 1 + dp[i][j + 1];
                    int insertVal = 1 + dp[i + 1][j];
                    dp[i][j] = min(deleteVal, min(replaceVal, insertVal));
                }
            }
        }

        return dp[0][0];
    }
};
