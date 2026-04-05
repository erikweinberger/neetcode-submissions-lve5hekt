class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        auto res = vector(n, 0);

        vector<std::pair<int, int>> stk;

        for (int i{n - 1}; i >= 0; --i) {

            while (!stk.empty() && stk.back().first <= temperatures[i]) {
                stk.pop_back();
            }

            if (stk.empty()) {
                res[i] = 0;
            }
            else if (stk.back().first > temperatures[i]) {
                res[i] = stk.back().second - i;
            }

            stk.push_back({temperatures[i], i});
        }

        return res;
    }
};
