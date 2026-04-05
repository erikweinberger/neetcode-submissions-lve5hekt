class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        std::vector<vector<int>> result;

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                break;
            }
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                if (nums[j] + nums[k] + nums[i] > 0) {
                    k--;
                }
                else if (nums[j] + nums[k] + nums[i] < 0) {
                    j++;
                }
                else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    k--;
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }
            }
        }

        return result;
    }
};
