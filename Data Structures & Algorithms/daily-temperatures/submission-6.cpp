class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        auto res = vector(n, 0);

        vector<std::pair<int, int>> stk;
        stk.reserve(n);

        for (int i{n - 1}; i >= 0; --i) {

            while (!stk.empty() && stk.back().first <= temperatures[i]) {
                stk.pop_back();
            }

            res[i] = stk.empty() ? 0 : stk.back().second - i;

            stk.push_back({temperatures[i], i});
        }

        return res;
    }
};
