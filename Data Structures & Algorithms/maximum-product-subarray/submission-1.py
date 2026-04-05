class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        curr_max_pos = 0
        curr_max_neg = 0
        max_ret = 0

        if len(nums) == 1:
            return nums[0]

        for i, n in enumerate(nums):
            if n >= 0:
                curr_max_pos = curr_max_pos * n if curr_max_pos > 0 else n
                curr_max_neg *= n
            else:
                temp = curr_max_neg
                curr_max_neg = curr_max_pos * n if curr_max_pos > 0 else n
                curr_max_pos = temp * n
            
            max_ret = max(max_ret, curr_max_pos)

        return max_ret

            

        