class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, 0, target, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& candidates, int start, int target, 
                   vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        if (target < 0) return;
        
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i-1]) continue;
            if (candidates[i] > target) break;
            current.push_back(candidates[i]);
            backtrack(candidates, i + 1, target - candidates[i], current, result);
            current.pop_back();
        }
    }
};