class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        auto usableSet = filterTriplets(triplets, target);

        array<bool, 3> found;
        found[0] = false;
        found[1] = false;
        found[2] = false;

        for (int i{}; i < usableSet.size(); ++i) {
            found[0] = usableSet[i][0] == target[0] || found[0];
            found[1] = usableSet[i][1] == target[1] || found[1];
            found[2] = usableSet[i][2] == target[2] || found[2];

            if (found[0] && found[1] && found[2]) return true;
        }

        return false;
    }

    vector<vector<int>> filterTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>> usable;
        for (int i{}; i < triplets.size(); ++i) {
            for (int j{}; j < 3; ++j) {
                if (target[j] < triplets[i][j]) {
                    break;
                }
                if (j == 2) {
                    usable.push_back({triplets[i][0], triplets[i][1], triplets[i][2]});
                }
            }
        }
        return usable;
    }
};
