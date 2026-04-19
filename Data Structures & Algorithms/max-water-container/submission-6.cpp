class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0, r = n - 1;

        int maxArea = 0;

        while (l < r) {
            int currArea = min(heights[l], heights[r]) * (r - l);
            maxArea = max(maxArea, currArea);

            if (heights[l] > heights[r]) {
                --r;
            } 
            else {
                ++l;
            }
        }

        return maxArea;

    }
};
