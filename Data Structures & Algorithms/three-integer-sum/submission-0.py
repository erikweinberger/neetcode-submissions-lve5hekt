class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        pivot = 0
        r = len(nums) - 1
        l = pivot + 1

        while (pivot < len(nums) - 2):
            if pivot > 0 and nums[pivot] == nums[pivot - 1]:
                pivot += 1
                l = pivot + 1
                r = len(nums) - 1
                continue
            while (l < r):
                if nums[pivot] + nums[l] + nums[r] > 0:
                    r -= 1
                elif nums[pivot] + nums[l] + nums[r] < 0:
                    l += 1
                else:
                    res.append([nums[pivot], nums[l], nums[r]])
                    l += 1
                    r -= 1
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1 
            pivot += 1
            l = pivot + 1
            r = len(nums) - 1

        return res