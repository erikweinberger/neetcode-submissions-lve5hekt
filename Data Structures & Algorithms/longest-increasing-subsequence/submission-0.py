class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0] * n

        dp[0] = 1
        for i in range(1, n):
            curr_max_lss = 0
            for j in range(0, i):
                if nums[j] < nums[i]:
                    curr_max_lss = max(curr_max_lss, dp[j])
            dp[i] = curr_max_lss + 1

        return max(dp)
