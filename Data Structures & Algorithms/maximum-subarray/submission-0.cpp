class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, currSum = INT_MIN;

        for (const auto n : nums) {
            if (currSum < 0) {
                currSum = n;
            } else {
                currSum += n;
            }

            maxSum = std::max(maxSum, currSum);
        }

        return maxSum;
    }
};
