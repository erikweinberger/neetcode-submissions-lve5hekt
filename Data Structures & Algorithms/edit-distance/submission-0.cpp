class Solution {
    std::vector<std::vector<int>> dp;

public:

    int minDistance(string word1, string word2) {
        dp.assign(word1.length(), std::vector<int>(word2.length(), -1));

        return dfs(0, 0, word1, word2);
    }

    int dfs(int i, int j, std::string& word1, std::string& word2) {
        if (i == word1.size()) return word2.size() - j;
        if (j == word2.size()) return word1.size() - i;
        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j]) {
            dp[i][j] = dfs(i + 1, j + 1, word1, word2);
        } else {
            int del = dfs(i + 1, j, word1, word2);
            int ins = dfs(i, j + 1, word1, word2);
            int rep = dfs(i + 1, j + 1, word1, word2);

            dp[i][j] = std::min(std::min(del, ins), rep) + 1;
        }

        return dp[i][j];

    }
};
