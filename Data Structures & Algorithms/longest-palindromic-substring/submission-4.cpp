class Solution {


public:
    string longestPalindrome(string s) {
        int n = s.size();

        int longestPalinStartIndex = -1;
        int longestPalinLen = 0;
        for (int i = 0; i < n; ++i) {

            int l = i , r = i;
            while (l >= 0 && r < n) {
                if (s[l] != s[r]) break;

                int currLen = r - l + 1;
                if (currLen > longestPalinLen) {
                    longestPalinLen = currLen;
                    longestPalinStartIndex = l;
                }
                --l;
                ++r;
            }

            l = i , r = i + 1;
            while (l >= 0 && r < n) {
                if (s[l] != s[r]) break;

                int currLen = r - l + 1;
                if (currLen > longestPalinLen) {
                    longestPalinLen = currLen;
                    longestPalinStartIndex = l;
                }
                --l;
                ++r;
            }

        }

        return s.substr(longestPalinStartIndex, longestPalinLen);
    }
};
