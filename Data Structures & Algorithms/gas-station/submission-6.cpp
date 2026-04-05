class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank{0};
        int start{0};
        int diff{0};
        int n = gas.size();

        for (int i{0}; i < n; ++i) {
            tank += gas[i] - cost[i];
            diff += gas[i] - cost[i];
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        return diff < 0 ? -1 : start;
    }
};
