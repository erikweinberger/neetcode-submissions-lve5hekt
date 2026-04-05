class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> set;
        set.reserve(nums.size());

        for (int num : nums) {
            if (set.find(num) != set.end()) {
                return true;
            }
            set.insert(num);
        }
        return false;
    }
};