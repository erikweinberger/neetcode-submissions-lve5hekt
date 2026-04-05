class Solution {
std::vector<std::vector<int>> dp;
std::vector<std::vector<int>> dirs {{1, 0}, {-1, 0}, {0, 1}, {0 , -1}};
int globalMax;

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        dp.assign(n, std::vector<int>(m, -1));
        globalMax = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dfs(i, j, -1, matrix);
            }
        }

        return globalMax;
    }

    int dfs(int i, int j, int prevVal, std::vector<std::vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        if (i == n || i < 0 || j == m || j < 0 || matrix[i][j] <= prevVal) {
            return 0;
        }

        if (dp[i][j] != -1) return dp[i][j];

        int max = 0;
        for (auto d : dirs) {
            max = std::max(max, dfs(i + d[0], j + d[1], matrix[i][j], matrix));
        }
        dp[i][j] = max + 1;
        globalMax = std::max(globalMax, dp[i][j]);
        return dp[i][j];
    }
};
