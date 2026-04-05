class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []

        start = 0
        max_area = 0

        for i, h in enumerate(heights):
            index = i
            while stack and stack[-1][1] > h:
                index, h2 = stack.pop()
                max_area = max(max_area, (i - index) * h2)
            stack.append((index, h))

        for i, h in stack:
            max_area = max(max_area, h * (len(heights) - i))

        return max_area

            

