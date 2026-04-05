class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int currTarget = n - 1;
        int prevTarget = currTarget;

        while (currTarget != 0) {
            for (int i = currTarget - 1; i >= 0; --i) {
                if (nums[i] + i >= currTarget) {
                    currTarget = i;
                    break;
                }
            }
            if (prevTarget == currTarget) return false;
            prevTarget = currTarget;
        }
        return true;
    }
};
