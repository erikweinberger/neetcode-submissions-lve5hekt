class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        count_s1 = {}
        count_s2 = {}

        for i in range(len(s1)):
            count_s1[s1[i]] = count_s1.get(s1[i], 0) + 1
            count_s2[s2[i]] = count_s2.get(s2[i], 0) + 1

        if count_s1 == count_s2:
            return True

        for i in range(len(s2) - len(s1)):
            left_char = s2[i]
            count_s2[left_char] -= 1
            if count_s2[left_char] == 0:
                del count_s2[left_char]

            right_char = s2[i + len(s1)]
            count_s2[right_char] = count_s2.get(right_char, 0) + 1

            if count_s1 == count_s2:
                return True

        return False
