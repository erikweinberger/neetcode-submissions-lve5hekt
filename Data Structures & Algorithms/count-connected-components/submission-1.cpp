class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int num_connected_comps = n;

        std::vector<int> disjoint_sets_num(n, -1);
        for (auto& edge : edges) {
            if (disjoint_sets_num[edge[0]] != -1 || disjoint_sets_num[edge[1]] != -1) {
                int joining_set = std::min(disjoint_sets_num[edge[0]], disjoint_sets_num[edge[1]]);
                if (joining_set == -1) joining_set = disjoint_sets_num[edge[0]] == -1 ? disjoint_sets_num[edge[1]] : disjoint_sets_num[edge[0]];

                int merging_set0 = disjoint_sets_num[edge[0]];
                int merging_set1 = disjoint_sets_num[edge[1]];

                disjoint_sets_num[edge[0]] = joining_set;
                disjoint_sets_num[edge[1]] = joining_set;

                for (int i = 0; i < disjoint_sets_num.size(); ++i) {
                    if (merging_set0 != -1 && disjoint_sets_num[i] == merging_set0) {
                        disjoint_sets_num[i] = joining_set;
                    }
                    if (merging_set1 != -1 && disjoint_sets_num[i] == merging_set1) {
                        disjoint_sets_num[i] = joining_set;
                    }
                }
            }
            else {
                int setNum = std::min(edge[0], edge[1]);
                disjoint_sets_num[edge[0]] = setNum;
                disjoint_sets_num[edge[1]] = setNum;
            }
        }

        std::unordered_set<int> res;
        int disjoint = 0;
        for (int i = 0; i < disjoint_sets_num.size(); ++i) {
            if (disjoint_sets_num[i] == -1) disjoint++;
            else res.insert(disjoint_sets_num[i]);
        }
        return res.size() + disjoint;
    }
};
