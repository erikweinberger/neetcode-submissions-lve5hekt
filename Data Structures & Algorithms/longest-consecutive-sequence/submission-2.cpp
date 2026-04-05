class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    
        std::sort(nums.begin(), nums.end());

        int longest_consecutive_seq = 0;
        int current_seq = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] > nums[i - 1] + 1) {
                current_seq = 1;
            } else if (nums[i] == nums[i - 1]) {
                
            }
            else {
                current_seq += 1;
            }
            longest_consecutive_seq = std::max(longest_consecutive_seq, current_seq);
        }
        return longest_consecutive_seq;

    }
};
