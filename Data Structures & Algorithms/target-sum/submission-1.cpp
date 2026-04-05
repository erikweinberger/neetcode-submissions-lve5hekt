class Solution {
    std::vector<std::vector<int>> dp;
    int totalSum;

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        dp.assign(nums.size(), std::vector<int>(totalSum * 2 + 1, INT_MIN));

        return dfs(0, 0, target, nums);
    }

    int dfs(int index, int currSum, int target, std::vector<int>& nums) {
        if (index >= nums.size()) {
            return currSum == target ? 1 : 0;
        }

        if (dp[index][currSum + totalSum] != INT_MIN) {
            return dp[index][currSum + totalSum];
        }

        dp[index][currSum + totalSum] = dfs(index + 1, currSum + nums[index], target, nums) + dfs(index + 1, currSum - nums[index], target, nums);

        return dp[index][currSum + totalSum];
    }



};
