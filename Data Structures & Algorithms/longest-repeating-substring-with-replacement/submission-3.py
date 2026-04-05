class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        max_count = ''
        count = {}
        l = 0
        r = 0
        max_length = 0

        while r < len(s):
            count[s[r]] = count.get(s[r], 0) + 1
            if count.get(max_count, 0) < count[s[r]]:
                max_count = s[r]
            
            while r - l - count[max_count] >= k:
                count[s[l]] -= 1
                prev = s[l]
                l += 1
                if count[max_count] == count[prev]:
                    max_count = s[l]
            r += 1
            max_length = max(max_length, r - l)
        
        return max_length