class Solution:
    def search(self, nums: List[int], target: int) -> int:
        up = len(nums) - 1
        low = 0

        while low <= up:
            mid = low + (up - low) // 2

            if nums[mid] == target: return mid
            if nums[up] == target: return up
            if nums[low] == target: return low


            if nums[mid] > target and nums[mid] > nums[up]:
                low = mid + 1
            elif nums[mid] > target:
                up = mid - 1
            elif nums[mid] < target and target > nums[up]:
                low = mid + 1
            elif nums[mid] < target:
                up = mid - 1
        return -1

        