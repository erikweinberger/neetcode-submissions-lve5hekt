class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [0] * len(nums)

        for i, num in enumerate(nums):
            if i == 0:
                dp[i] = num
            elif i == 1:
                dp[i] = max(dp[i - 1], num)
            else:
                dp[i] = max(dp[i - 2] + num, dp[i - 1])
        
        return dp[-1]
