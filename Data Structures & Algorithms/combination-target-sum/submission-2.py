class Solution:
    def __init__(self):
        self.result = []

    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        self.combinationSumRec(nums, target, 0, 0, [])
        return self.result

    def combinationSumRec(self, nums, target, i, curr_sum, curr_list):
        if nums[i] + curr_sum == target:
            self.result.append(curr_list + [nums[i]])

        if nums[i] + curr_sum < target:
            self.combinationSumRec(nums, target, i, nums[i] + curr_sum, curr_list + [nums[i]])
        

        if i < len(nums) - 1:
            self.combinationSumRec(nums, target, i + 1, curr_sum, curr_list.copy())
        
            
            