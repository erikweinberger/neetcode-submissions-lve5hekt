class Solution:
    def maxArea(self, heights: List[int]) -> int:
        max_area = 0
        l = 0
        r = len(heights) - 1

        while (l < r):
            max_area = max(max_area, (r - l) * min(heights[l], heights[r]))
            if heights[l] > heights[r]:
                r -= 1
            elif heights[l] < heights[r]:
                l += 1
            else:
                l += 1
        
        return max_area
        