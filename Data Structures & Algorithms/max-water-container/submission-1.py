class Solution:
    def maxArea(self, heights: List[int]) -> int:
        max_area = 0
        l = 0
        r = len(heights) - 1

        while l < r:
            max_area = max(min(heights[l], heights[r]) * (r - l), max_area)

            if heights[l] < heights[r]:
                l += 1
            else:
                r -= 1
        
        return max_area
        