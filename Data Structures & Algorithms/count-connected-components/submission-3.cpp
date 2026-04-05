class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int res = 0;

        std::vector<std::vector<int>> edgeConnections(n);

        for (const auto & e : edges) {
            edgeConnections[e[0]].push_back(e[1]);
            edgeConnections[e[1]].push_back(e[0]);
        }

        std::vector<bool> visited(n, false);

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++res;
                dfs(i, edgeConnections, visited);
            }
        }

        return res;
    }

    void dfs(int node, const std::vector<std::vector<int>>& edgeConnections, std::vector<bool>& visited) {
        visited[node] = true;
        for (const int c : edgeConnections[node]) {
            if (!visited[c]) {
               dfs(c, edgeConnections, visited);
            } 
        }
    }
};
