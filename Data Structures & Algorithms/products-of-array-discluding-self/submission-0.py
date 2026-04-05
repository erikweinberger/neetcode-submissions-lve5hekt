class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        l_prod = [0] * len(nums)
        r_prod = [0] * len(nums)

        for i in range(len(nums)):
            if i == 0:
                l_prod[i] = 1
                r_prod[len(nums) - 1] = 1
            else:
                l_prod[i] = l_prod[i - 1] * nums[i - 1]
                r_prod[len(nums) - 1 - i] = r_prod[len(nums) - i] * nums[len(nums) - i]
        
        res = [0] * len(nums)
        for i in range(len(nums)):
            res[i] = l_prod[i] * r_prod[i]
        return res