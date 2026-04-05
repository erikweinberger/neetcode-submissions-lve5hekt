class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0
        dp_change = [100000] * (amount + 1)
        dp_change[0] = 0

        for i in range(amount + 1):
            for coin in coins:
                if i - coin >= 0:
                    dp_change[i] = min(dp_change[i - coin] + 1, dp_change[i])
        
        print(dp_change)
        return dp_change[-1] if dp_change[-1] != 100000 else -1


        