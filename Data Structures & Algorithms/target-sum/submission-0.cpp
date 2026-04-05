class Solution {
    vector<vector<int>> dp;
    int totalSum;

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = std::accumulate(nums.begin(), nums.end(), 0);

        dp = std::vector<std::vector<int>>(nums.size(), std::vector<int>(2 * totalSum + 1, INT_MIN));
        return dfs(nums, target, 0, 0);
    }

    int dfs(std::vector<int>& nums, int target, int i, int currSum) {
        if (i == nums.size()) {
            if (currSum == target) return 1;
            else return 0;
        }

        if (dp[i][currSum + totalSum] != INT_MIN) return dp[i][currSum + totalSum];

        dp[i][currSum + totalSum] = dfs(nums, target, i + 1, currSum + nums[i]) 
                                    + dfs(nums, target, i + 1, currSum - nums[i]);
        
        return dp[i][currSum + totalSum];
    }
};
