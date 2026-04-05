class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stack {};
        
        int maxArea = 0;

        for (int i = 0; i <= n; ++i) {
            while (!stack.empty() && (heights[stack.top()] > heights[i] || i == n)) {
                int height = heights[stack.top()];
                stack.pop();
                int width = stack.empty() ? i : i - stack.top() - 1;
                maxArea = std::max(maxArea, height * width);
            }
            stack.push(i);
        }

        return maxArea;
    }
};
