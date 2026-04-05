class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if (n == 1 && gas[0] < cost[0]) return -1;

        int total{0};
        int start{0};
        int i{start};

        int tries = 0;
        while (true) {
            total += gas[i] - cost[i];
            if (total < 0) {
                start = (i + 1) % n;
                i++;
                total = 0;
            }
            else {
                i = (i + 1) % n;
                if (start == i) {
                    return start;
                }
            }

            if (tries == 2 * n) break;
            tries++;
        }
        return -1;
    }
};
