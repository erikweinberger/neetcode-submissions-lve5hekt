class Solution {


public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if (m + n != s3.size()) {
            return false;
        }

        if (n > m) {
            std::swap(s1, s2);
            std::swap(m, n);
        }


        std::vector<bool> dpPrev(n + 1, false);
        std::vector<bool> dpCurr(n + 1, false);
        dpCurr[n] = true;

        for (int i = m; i >= 0; --i) {
            for (int j = n; j >= 0; --j) {
                if (i < m && s3[i + j] == s1[i] && dpPrev[j]) {
                    dpCurr[j] = true;
                }

                if (j < n && s3[i + j] == s2[j] && dpCurr[j + 1]) {
                    dpCurr[j] = true;
                }
            }
            std::swap(dpPrev, dpCurr);
            std::fill(dpCurr.begin(), dpCurr.end(), false);
        }

        return dpPrev[0];
    }


};
