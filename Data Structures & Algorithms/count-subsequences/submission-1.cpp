class Solution {

std::vector<std::vector<int>> dp;

public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        if (m < n) return 0;
        std::vector<int> dpPrev(n + 1, 0);
        std::vector<int> dpCurr(n + 1, 0);

        dpPrev[n] = 1;
        dpCurr[n] = 1;

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dpCurr[j] = dpPrev[j];
                if (s[i] == t[j]) {
                    dpCurr[j] += dpPrev[j + 1];
                }
            }
            dpPrev = dpCurr;
        }

        return dpPrev[0];
    }
};
