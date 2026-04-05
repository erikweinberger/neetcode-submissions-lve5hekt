class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() > text2.size()) {
            std::swap(text1, text2);
        }
        int n = text1.size(), m = text2.size();

        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (text1[j] == text2[i]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }

        return dp[0][0];
    }
};
