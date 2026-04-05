class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;

        int maxWater = 0;

        while (l < r) {
            maxWater = std::max(maxWater, std::min(heights[l], heights[r]) * (r - l));
            if (heights[l] < heights[r]) l++;
            else r--;
        }

        return maxWater;
    }
};
