#include <array>

inline int uli(unsigned char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    if (c >= 'a' && c <= 'z') return (c - 'a') + 26;
    return -1; // unsupported char
}

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int k = t.length();
        int r = 0, l = 0;
        std::pair<int, int> minSubStringSpan {-1, s.size()};

        if (n < k) {
            return "";
        }

        std::array<int, 52> tFreq {0};
        for (unsigned char c : t) {
            tFreq[uli(c)] += 1;
        }

        std::array<int, 52> subFreq {0};
        while (r < n) {
            subFreq[uli(s[r])] += 1;
            while (stringContained(tFreq, subFreq)) {
                if (r - l < minSubStringSpan.second - minSubStringSpan.first) {
                    minSubStringSpan = std::make_pair(l, r);
                }
                subFreq[uli(s[l])] -= 1;
                ++l;
            }
            ++r;
        }
        if (minSubStringSpan.first == -1 || minSubStringSpan.second == s.size()) {
            return "";
        }
        return s.substr(minSubStringSpan.first, minSubStringSpan.second - minSubStringSpan.first + 1);
        
    }

    bool stringContained(const std::array<int, 52> &tFreq, const std::array<int, 52>& subFreq) {
        
        for (int i = 0; i < 52; ++i) {
            if (subFreq[i] < tFreq[i]) {
                return false;
            }
        }
        return true;
    }
};
