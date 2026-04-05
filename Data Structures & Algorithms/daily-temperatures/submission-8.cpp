class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        auto res = vector(n, 0);
        vector<int> stk;

        for (int i = n - 1; i >= 0; --i) {

            while (!stk.empty() && temperatures[stk.back()] <= temperatures[i]) {
                stk.pop_back();
            }

            res[i] = stk.empty() ? 0 : stk.back() - i;

            stk.push_back({i});
        }

        return res;
    }
};
