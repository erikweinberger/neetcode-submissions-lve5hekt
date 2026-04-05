class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = 0;

        int currSectionArea = 0;
        int totalArea = 0;
        while (r < height.size()) {
            if (height[r] >= height[l]) {
                l = r;
                totalArea += currSectionArea;
                currSectionArea = 0;
            }
            currSectionArea += height[l] - height[r];
            r++;
        }
        if (l == r - 1) {
            return totalArea;
        }

        // Backtracking for over shoot at the end
        int prevMaxHeight = 0;
        currSectionArea = 0;
        for (int r = height.size() - 1; r > l; r--) {
            prevMaxHeight = std::max(prevMaxHeight, height[r]);
            currSectionArea += (prevMaxHeight - height[r]);
        }
        return totalArea + currSectionArea;
    }
};
