class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:

        up = max(piles)
        low = 1
        while low <= up:
            curr_k = (up - low) // 2 + low
            if self.checkEatSpeed(piles, curr_k, h):
                up = curr_k - 1
                k = curr_k
            else:
                low = curr_k + 1

        return k
            

    def checkEatSpeed(self, piles, k, h):
        time = 0
        i = 0
        while i < len(piles):
            time += math.ceil(piles[i] / k)
            if time > h:
                return False
            i += 1
        return True


