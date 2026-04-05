class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];
        if (n == 2) return std::max(nums[0], nums[1]);

        std::vector<int> dp0(n, 0); //includes 0 index
        std::vector<int> dp1(n, 0); //includes 1 index

        dp0[0] = nums[0];
        dp0[1] = nums[0];

        dp1[0] = 0;
        dp1[1] = nums[1];

        for (int i = 2; i < n; ++i) {
            if (i == n - 1) {
                dp1[i] = std::max(nums[i] + dp1[i - 2], dp1[i - 1]);
                continue;
            }

            dp0[i] = std::max(nums[i] + dp0[i - 2], dp0[i - 1]);
            dp1[i] = std::max(nums[i] + dp1[i - 2], dp1[i - 1]);
        }

        std::cerr << dp0[n - 2] << " , " << dp0[n - 1] << " , " << dp1[n - 1] << " , " << dp1[n - 2] << '\n';
        int maxdp0 = std::max(dp0[n - 1], dp0[n - 2]), maxdp1 = std::max(dp1[n - 1], dp1[n - 2]);

        return std::max(maxdp0, maxdp1);
        
    }
};
