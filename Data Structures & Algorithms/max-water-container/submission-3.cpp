class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;

        int maxWater = 0;

        while (l < r) {
            maxWater = std::max(maxWater, std::min(heights[l], heights[r]) * (r - l));
            if (heights[l] == 500) {
                std::cout << "l is 500 (l , r): " << r << " , " << l << std::endl;
            }
            if (heights[r] == 500) {
                std::cout << "r is 500 (l , r): " << r << " , " << l << std::endl;
            }


            if (heights[l] < heights[r]) l++;
            else r--;
        }

        return maxWater;
    }
};
