class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0, r = n - 1;

        int maxArea = 0;

        while (l < r) {
            int currArea = 0;
            if (heights[l] > heights[r]) {
                currArea = heights[r] * (r - l);
                --r;
            } 
            else {
                currArea = heights[l] * (r - l);
                ++l;
            }
            maxArea = max(maxArea, currArea);

        }

        return maxArea;

    }
};
