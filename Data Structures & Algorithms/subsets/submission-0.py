class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = [[]]

        for num in nums:
            if [num] not in nums:
                result.append([num])

                for s in result:
                    new_set = list(set([num] + s))
                    contains = False
                    for s in result:
                        if set(s) == set(new_set):
                            contains = True
                    
                    if not contains:
                        result.append(new_set)

        return result
            
        