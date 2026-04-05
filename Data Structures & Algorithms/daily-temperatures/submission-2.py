class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:

        res = [0] * len(temperatures)
        stack = []

        for i, t in enumerate(temperatures):
            while len(stack) > 0 and temperatures[stack[-1]] < t:
                index = stack.pop()
                res[index] = (i - index)

            stack.append(i)

        return res
        