class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0

        l = 0
        r = 0
        last_seen = {}
        longest_sub = 1
        
        while r < len(s):
            if last_seen.get(s[r], -1) >= l:
                l += 1
            else:
                last_seen[s[r]] = r
                longest_sub = max(longest_sub, r - l + 1)
                r += 1
        
        return longest_sub