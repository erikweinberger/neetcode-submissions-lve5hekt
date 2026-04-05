class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        b = 0
        s = 1
        max_prof = 0

        while s < len(prices):
            if prices[s] > prices[b]: #prices[s] - prices[b] > 0
                profit = prices[s] - prices[b]
                max_prof = max(max_prof, profit)
            else:
                b = s
            s += 1
        
        return max_prof


        
