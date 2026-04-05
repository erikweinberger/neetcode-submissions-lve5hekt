class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int maxLength = 0;
        std::unordered_map<char, int> currentCharsFreq;
        int maxf = 0;

        int j = 0; //Back of the sliding window
        for (int i = 0; i < n; ++i) {
            currentCharsFreq[s[i]]++;
            maxf = std::max(maxf, currentCharsFreq[s[i]]);


            while ((i - j + 1) - maxf > k) {
                currentCharsFreq[s[j++]]--;
            }
            maxLength = std::max(maxLength, i - j + 1);
        }
        return maxLength;
    }
};
