class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        sum_nums = sum(nums)
        if sum_nums % 2 != 0:
            return False

        target = sum(nums) // 2
        dp = [False] * (target + 1)

        dp[0] = True
        for i, n in enumerate(nums):
            for j in range(target, n - 1, -1):
                dp[j] = dp[j] or dp[j - n] 
        
        return dp[target]
        
        