class Solution:
    def rob(self, nums: List[int]) -> int:
        dp1 = [0] * len(nums)
        dp2 = [0] * len(nums)

        for i, val in enumerate(nums):
            if i == 0:
                dp1[0] = 0
            elif i == 1:
                dp1[i] = val
            else:
                dp1[i] = max(val + dp1[i - 2], dp1[i - 1])

        for i, val in enumerate(nums):
            if i == 0:
                dp2[0] = val
            elif i == 1 or i == len(nums) - 1:
                dp2[i] = dp2[i - 1]
            else:
                dp2[i] = max(val + dp2[i - 2], dp2[i - 1])

        return max(dp1[-1], dp2[-1])
        
        