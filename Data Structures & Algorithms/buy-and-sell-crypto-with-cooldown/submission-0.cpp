class Solution {
public:
    std::vector<std::vector<int>> memo;

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        std::vector<std::vector<int>> dp2(n + 2, std::vector<int>(2, 0));

        for (int i = n - 1; i >= 0; --i) {
            int buy = dp2[i + 1][1] - prices[i];
            int cooldown = dp2[i + 1][0];
            dp2[i][0] = std::max(buy, cooldown);

            int sell = dp2[i + 2][0] + prices[i];
            cooldown = dp2[i + 1][1];
            dp2[i][1] = std::max(sell, cooldown);
        }

        return dp2[0][0];
    }

};
