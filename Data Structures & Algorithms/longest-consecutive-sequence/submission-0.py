class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums_set = set(nums)
        maximum = 0
        for num in nums:
            if num - 1 not in nums_set:
                i = 1
                while True:
                    if num + i not in nums_set:
                        break
                    i += 1
                maximum = max(maximum, i)
        
        return maximum
        