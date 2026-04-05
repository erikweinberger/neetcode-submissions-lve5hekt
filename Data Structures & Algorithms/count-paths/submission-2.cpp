class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp2(m, std::vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    dp2[i][j] = 1;
                }
                else if (i == 0) {
                    dp2[i][j] = dp2[i][j - 1];
                }
                else if (j == 0) {
                    dp2[i][j] = dp2[i - 1][j];
                }
                else {
                    dp2[i][j] = dp2[i - 1][j] + dp2[i][j - 1];
                }
            }
        }

        return dp2[m - 1][n - 1];
    }
};
