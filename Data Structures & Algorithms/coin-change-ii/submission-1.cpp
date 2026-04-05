class Solution {
    std::unordered_map<std::string, int> dp;

public:
    int change(int amount, vector<int>& coins) {
        dp.reserve(coins.size() * amount);

        return dfs(coins, 0, amount, 0);
    }

    int dfs(std::vector<int>& coins, int i, int target, int currSum) {
        std::string key = std::to_string(i) + "-" + std::to_string(currSum);
        if (currSum > target) {
            dp[key] = 0;
            return 0; 
        }

        if (currSum == target) {
            dp[key] = 1;
            return dp[key];
        }

        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        int num_ways = 0;
        for (int j = i; j < coins.size(); ++j) {
            num_ways += dfs(coins, j, target, currSum + coins[j]);
        }

        dp[key] = num_ways;
        return dp[key];
    }
};
