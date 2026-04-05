class Solution {
public:
    std::vector<std::vector<int>> result;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        backtrackSubset(nums, 0, {});

        return result;
        
    
    }

private:

    void backtrackSubset(std::vector<int>& nums, int index, std::vector<int> backtrack) {
        result.push_back(backtrack);
        for (int i = index; i < nums.size(); ++i) {
            if (i > index && nums[i] == nums[i - 1]) continue;
            backtrack.push_back(nums[i]);
            backtrackSubset(nums, i + 1, backtrack);
            backtrack.pop_back();
        }
    }
};
