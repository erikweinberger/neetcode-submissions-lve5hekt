class Solution:
    def isValid(self, s: str) -> bool:
        parentheses_pairs = {'(': ')', '{': '}', '[': ']'}

        stack = []

        for c in s:
            if c in parentheses_pairs.keys():
                stack.append(c)
            else:
                if len(stack) == 0 or parentheses_pairs[stack.pop()] != c:
                    return False
        
        return len(stack) == 0
