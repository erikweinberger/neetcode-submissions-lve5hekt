class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_dict = {}
        
        for s in strs:
            temp_key = [0] * 26
            for c in s:
                temp_key[ord(c) - ord('a')] += 1
            
            temp_key = tuple(temp_key)
            if not anagram_dict.get(temp_key):
                anagram_dict[temp_key] = [s]
            else:
                anagram_dict[temp_key].append(s)
        
        result = []
        for key, st in anagram_dict.items():
            result.append(st)
        
        return result


