class Solution:
    def search(self, nums: List[int], target: int) -> int:
        up = len(nums) - 1
        low = 0

        while low <= up:
            mid = low + (up - low) // 2

            if nums[mid] == target: return mid
            if nums[up] == target: return up
            if nums[low] == target: return low

            if nums[low] <= nums[mid]:
                if target > nums[mid] or target < nums[low]:
                    low = mid + 1
                else:
                    up = mid - 1
            else:
                if target < nums[mid] or target > nums[up]:
                    up = mid - 1
                else:
                    low = mid + 1

        return -1

        