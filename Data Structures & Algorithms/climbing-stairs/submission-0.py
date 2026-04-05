class Solution:
    def climbStairs(self, n: int) -> int:

        dp = [0] * n

        for step in range(n):
            if step < 1:
                dp[step] = 1
            elif step < 2:
                dp[step] = 1 + dp[step - 1]
            else:
                dp[step] = dp[step - 1] + dp[step - 2]
            print(dp, step)

        return dp[-1]
            
        