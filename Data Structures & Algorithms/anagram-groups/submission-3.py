class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        resDict = {}

        for s in strs:
            freqList = [0] * 26
            for i in range(len(s)):
                freqList[ord('a') - ord(s[i])] += 1
            resDict.setdefault(tuple(freqList), []).append(s)  
        
        return [v for k, v in resDict.items()]