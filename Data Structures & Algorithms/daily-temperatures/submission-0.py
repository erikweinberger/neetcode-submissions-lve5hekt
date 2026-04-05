class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:

        res = [0] * len(temperatures)
        stack = []

        for i, t in enumerate(temperatures):
            if len(stack) > 0:
                while len(stack) > 0 and stack[-1][0] < t:
                    temp, index = stack.pop()
                    res[index] = (i - index)

            stack.append((t, i))

        return res

        