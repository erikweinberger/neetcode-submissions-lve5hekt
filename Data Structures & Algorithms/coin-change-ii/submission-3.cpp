class Solution {

std::vector<std::vector<int>> dp;

public:
    int change(int amount, vector<int>& coins) {
        dp.assign(amount + 1, std::vector<int>(coins.size(), -1));

        return dfs(0, 0, amount, coins);

    }

    int dfs(int currSum, int i, int amount, std::vector<int>& coins) {
        if (currSum == amount) {
            return 1;
        }

        if (currSum > amount) {
            return 0;
        }

        if (dp[currSum][i] != -1) {
            return dp[currSum][i];
        }

        dp[currSum][i] = 0;
        for (int j = i; j < coins.size(); ++j) {
            dp[currSum][i] += dfs(currSum + coins[j], j, amount, coins);
        }

        return dp[currSum][i];
    }
};
