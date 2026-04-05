class Solution:
    def trap(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1
        max_l = height[l]
        max_r = height[r]

        res = 0

        while (l < r):
            if height[l] <= height[r]:
                l += 1
                max_l = max(height[l], max_l)
                if max_l > 0:
                    res += max_l - height[l]
            if height[l] > height[r]:
                r -= 1
                max_r = max(height[r], max_r)
                if max_r > 0:
                    res += max_r - height[r]
        return res
        