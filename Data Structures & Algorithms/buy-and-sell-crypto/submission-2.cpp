class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 0;
        int maxSell = 0;
        while (r < prices.size()) {
            if (r == l) {
                ++r;
            }
            else if (prices[r] < prices[l]) {
                l = r;
            }
            else {
                maxSell = std::max(maxSell, prices[r] - prices[l]);
                r++;
            }
        }
        return maxSell;
    }
};
