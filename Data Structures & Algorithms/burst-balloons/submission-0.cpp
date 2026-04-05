class Solution {

private:
    std::vector<std::vector<int>> dp;

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> newNums(n + 2, 1);
        for (int i = 0; i < n; i++) {
            newNums[i + 1] = nums[i];
        }

        dp.assign(n + 2, std::vector<int>(n + 2, -1));

        return dfs(1, n, newNums);

    }

    int dfs(int l, int r, std::vector<int>& nums) {
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        for (int i = l; i <= r; ++i) {
            int coins = nums[l - 1] * nums[i] * nums[r + 1];
            coins += dfs(i + 1, r, nums) + dfs(l, i - 1, nums);
            dp[l][r] = std::max(dp[l][r], coins);
        }

        return dp[l][r];
    }
};
