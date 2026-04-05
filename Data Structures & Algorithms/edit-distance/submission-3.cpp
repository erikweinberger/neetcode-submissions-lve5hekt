class Solution {

public:

    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        if (n > m) {
            std::swap(word1, word2);
            std::swap(n, m);
        }
        std::vector<int> prevDp(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            prevDp[i] = i; // Convert word1[:i] -> ""
        }
        std::vector<int> currDp(n + 1, 0);

        for (int i = 1; i <= m; ++i) {
            currDp[0] = i;
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    currDp[j] = prevDp[j - 1];
                } else {
                    currDp[j] = 1 + std::min(std::min(currDp[j - 1], prevDp[j]), prevDp[j - 1]);
                }
            }
            std::swap(currDp, prevDp);
        }

        return prevDp[n];
    }
};
