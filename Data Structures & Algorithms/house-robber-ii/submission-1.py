class Solution:
    def rob(self, nums: List[int]) -> int:
        max_val = nums[0]

        rob1, rob2 = 0, 0
        for val in nums[1:]:
            newRob = max(rob1 + val, rob2)
            rob1 = rob2
            rob2 = newRob
        max_val = max(max_val, rob2)

        rob1, rob2 = 0, 0
        for val in nums[:-1]:
            newRob = max(rob1 + val, rob2)
            rob1 = rob2
            rob2 = newRob
        max_val = max(max_val, rob2)

        return max_val
        
        