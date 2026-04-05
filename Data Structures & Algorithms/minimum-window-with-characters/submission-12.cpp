#include <array>
#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    std::string minWindow(const std::string &s, const std::string &t) {
        int n = (int)s.size();
        int k = (int)t.size();
        if (n < k) return "";

        // Use ASCII indexing to avoid worrying about case or custom maps.
        std::array<int, 128> tFreq{};
        for (unsigned char c : t) tFreq[c]++;

        std::array<int, 128> subFreq{};
        int l = 0, r = 0;
        std::pair<int,int> best{-1, n}; // [first, second] inclusive indices

        auto contains = [&](const std::array<int,128>& need, const std::array<int,128>& have) -> bool {
            for (int i = 0; i < 128; ++i) {
                if (have[i] < need[i]) return false;
            }
            return true;
        };

        // Optional debug: print tFreq
        std::cerr << "tFreq: ";
        for (int i = 0; i < 128; ++i) if (tFreq[i]) std::cerr << "'" << char(i) << "':" << tFreq[i] << " ";
        std::cerr << "\n";

        while (r < n) {
            unsigned char rc = s[r];
            subFreq[rc]++;
            std::cerr << r << ", subFreq['" << s[r] << "'] -> " << subFreq[rc] << '\n';

            // Try to contract while window contains t
            while (contains(tFreq, subFreq)) {
                if (best.first == -1 || (r - l) < (best.second - best.first)) {
                    best = {l, r};
                }
                unsigned char lc = s[l];
                subFreq[lc]--;
                ++l;
            }
            ++r;
        }

        if (best.first == -1) return "";
        return s.substr(best.first, best.second - best.first + 1);
    }
};

