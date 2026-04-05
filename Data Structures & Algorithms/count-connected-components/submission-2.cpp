class DSU {
public:
    std::vector<int> parent;
    std::vector<int> rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        int cur = node;
        while(cur != parent[cur]) {
            parent[cur] = parent[parent[cur]];
            cur = parent[cur];
        }

        return cur;
    }

    bool unionSets(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) {
            return false;
        }

        if (rank[pv] > rank[pu]) {
            std::swap(pu, pv);
        }

        parent[pv] = pu;
        rank[pu] += rank[pv];

        return true;
    }
};


class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int num_connected_comps = n;

        DSU dsu(n);
        for (auto& edge : edges) {
            if (dsu.unionSets(edge[0], edge[1])) {
                num_connected_comps--;
            }
        }

        return num_connected_comps;
    }
};
