class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        std::vector<int> curr(m + 1, 0);
        curr[m] = 1;
        std::vector<int> prev(m + 1, 0);
        for (int i{}; i <= m; ++i) {
            prev[i] = m - i;
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (word1[i] == word2[j]) {
                    curr[j] = prev[j + 1];
                } else {
                    int deleteVal = 1 + prev[j + 1];
                    int replaceVal = 1 + curr[j + 1];
                    int insertVal = 1 + prev[j];
                    curr[j] = min(deleteVal, min(replaceVal, insertVal));
                }
            }
            swap(curr, prev);
            prev[m] = n - i;
            curr[m] = n - i + 1;
        }

        return prev[0];
    }
};
