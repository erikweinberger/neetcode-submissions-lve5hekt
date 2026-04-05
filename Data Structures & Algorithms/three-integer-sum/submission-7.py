class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = []

        main_index = 0

        for i in range(len(nums)):
            if nums[i] > 0:
                break
            
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            l = i + 1
            r = len(nums) - 1
            while l < r:
                l = l + 1 if l == i else l
                r = r - 1 if r == i else r
                if l >= r:
                    break

                if -nums[i] == nums[l] + nums[r]:
                    result.append([nums[i], nums[l], nums[r]])
                    l += 1
                    r -= 1
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
                
                if nums[i] + nums[l] + nums[r] < 0:
                    l += 1
                
                if nums[i] + nums[l] + nums[r] > 0:
                    r -= 1
            
        
        return result
                
