class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int currTarget = n - 1;
        int tmpTarget = n - 1;
        int result = 0;


        while (currTarget != 0) {
            for (int i = currTarget; i >=0; --i) {
                if (nums[i] + i >= currTarget) {
                    tmpTarget = i;
                }
            }
            currTarget = tmpTarget;
            ++result;
        }

        return result;
    }
};
