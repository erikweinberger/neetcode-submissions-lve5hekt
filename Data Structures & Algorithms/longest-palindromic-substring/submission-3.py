class Solution:
    def longestPalindrome(self, s: str) -> str:
        resLen = 0
        index_tup = (0, 0)
        for i in range(len(s)):
            l, r = i, i
            while l >= 0 and r < len(s):
                if s[l] != s[r]:
                    break
                if r - l + 1 > resLen:
                    resLen = r - l + 1
                    index_tup = (l, r)
                l -= 1
                r += 1
        
        for i in range(len(s) - 1):
            l , r = i, i + 1
            while l >= 0 and r < len(s):
                if s[l] != s[r]:
                    break
                if r - l + 1 > resLen:
                    resLen = r - l + 1
                    index_tup = (l, r)
                l -= 1
                r += 1
        
        return s[index_tup[0]:index_tup[1] + 1]



        