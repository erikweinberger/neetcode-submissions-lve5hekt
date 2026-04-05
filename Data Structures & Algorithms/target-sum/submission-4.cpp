class Solution {

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        int m = 2 * totalSum + 1;
        std::vector<int> dpPrev(m, 0);
        dpPrev[totalSum] = 1;

        std::vector<int> dpCurr(m, 0);

        for (int i = 0; i < nums.size(); ++i) {
            std::fill(dpCurr.begin(), dpCurr.end(), 0);

            for (int j = 0; j < m; ++j) {
                dpCurr[j] += j - nums[i] >= 0 ? dpPrev[j - nums[i]] : 0;
                dpCurr[j] += j + nums[i] < m ? dpPrev[j + nums[i]] : 0;
            }
            std::swap(dpCurr, dpPrev);
        }

        return dpPrev[totalSum + target];
    }

};
