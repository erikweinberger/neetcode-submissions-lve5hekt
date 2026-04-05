class Solution:
    def findMin(self, nums: List[int]) -> int:
        low = 0
        up = len(nums) - 1

        while low < up:
            mid = low + (up - low) // 2

            if nums[mid] > nums[up]:
                low = mid + 1
            elif nums[mid] < nums[low]:
                up = mid
            elif nums[mid] < nums[up]:
                print('here')
                up = mid
        print(low, up)
        return nums[low + (up - low) // 2]
        