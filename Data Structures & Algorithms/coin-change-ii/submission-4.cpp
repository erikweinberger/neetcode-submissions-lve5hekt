class Solution {

public:
    int change(int amount, vector<int>& coins) {
       std::vector<int> dpPrev(amount + 1, 0);

        dpPrev[0] = 1; // Making 0 always 1 way (Pick no coins)
        std::vector<int>  dpCurr(amount + 1, 0);

        for (int i = 0; i < coins.size(); ++i) {
            std::fill(dpCurr.begin(), dpCurr.end(), 0);
            dpCurr[0] = 1;
            for (int j = 0; j <= amount; ++j) {
                int prev = j - coins[i] < 0 ? 0 : dpCurr[j - coins[i]];
                dpCurr[j] = dpPrev[j] + prev;
            }

            std::swap(dpPrev, dpCurr);
        }

        return dpPrev[amount];
    }
};
