class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [0] * len(nums)

        for i, val in enumerate(nums):
            if i == 0:
                dp[i] = val
            elif i == 1:
                dp[i] = max(val, dp[i - 1])
            else:
                dp[i] = max(val + dp[i - 2], dp[i - 1])
            
        return dp[-1]