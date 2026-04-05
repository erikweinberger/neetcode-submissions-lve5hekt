class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l = 0
        r = 0
        max_diff = 0

        while r < len(prices):
            max_diff = max(max_diff, prices[r] - prices[l])
            if prices[r] < prices[l]:
                l = r
            else:
                r += 1

        return max_diff
