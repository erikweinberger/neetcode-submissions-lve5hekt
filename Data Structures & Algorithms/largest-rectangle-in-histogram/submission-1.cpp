class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            for (int j = i; j < heights.size(); ++j) {
                int minHeight = 1000;
                for (int k = i; k <= j; ++k) {
                    minHeight = std::min(minHeight, heights[k]);
                }
                maxArea = std::max((j - i + 1) * minHeight, maxArea);
            }
        }
        return maxArea;
    }
};
