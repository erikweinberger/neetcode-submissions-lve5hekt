class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int midPoint = (l + r) / 2;
            if (target == nums[midPoint]) return midPoint;
            if (target == nums[l]) return l;
            if (target == nums[r]) return r;

            if (nums[l] <= nums[midPoint]) {
                if (target > nums[l] && target < nums[midPoint]) {
                    r = midPoint - 1;
                }
                else {
                    l = midPoint + 1;
                }
            }
            else {
                if (target < nums[r] && target > nums[midPoint]) {
                    l = midPoint + 1;
                }
                else {
                    r = midPoint - 1;
                }
            }
        }
        return -1;
        
    }
};
