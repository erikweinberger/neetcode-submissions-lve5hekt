class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() > text2.size()) {
            std::swap(text1, text2);
        }
        int n = text1.size(), m = text2.size();

        std::vector<int> prev(n + 1, 0);
        std::vector<int> curr(n + 1, 0);

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (text1[j] == text2[i]) {
                    curr[j] = 1 + prev[j + 1];
                } else {
                    curr[j] = max(curr[j + 1], prev[j]);
                }
            }
            std::swap(curr, prev);
        }

        return prev[0];
    }
};
