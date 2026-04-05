class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> set {};
        for (auto &num : nums) {
            set.insert(num);
        }

        int max_seq = 0;
        int curr_seq = 0;
        for (auto &num : nums) {
            if (!set.count(num - 1)) {
                int curr_num = num;
                while(true) {
                    curr_seq += 1;
                    curr_num += 1;
                    if (!set.count(curr_num)) {
                        break;
                    }
                }
            }
            max_seq = std::max(max_seq, curr_seq);
            curr_seq = 0;
        } 

        return max_seq;

    }
};
