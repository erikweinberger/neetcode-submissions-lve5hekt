class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> charInCurrSubstring {};
        int maxSubstringLength = 0;

        int j = 0; // Back part of the sliding window
        for (int i = 0; i < s.size(); ++i) {
            while (charInCurrSubstring.find(s[i]) != charInCurrSubstring.end()) {
                charInCurrSubstring.erase(s[j]);
                j++;
            }
            maxSubstringLength = std::max(maxSubstringLength, i - j + 1);
            charInCurrSubstring.insert(s[i]);
        }

        return maxSubstringLength;
    }
};
