class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = [0] * len(cost)

        for i, c in enumerate(cost):
            if i == 0:
                dp[i] = cost[0]
            elif i == 1:
                dp[1] = cost[1]
            else:
                dp[i] = min(cost[i] + dp[i - 1], cost[i] + dp[i - 2])
        print(dp)
        return min(dp[-1], dp[-2])
            
        