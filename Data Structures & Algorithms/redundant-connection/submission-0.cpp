class Solution {
    std::vector<bool> visited;
    std::vector<std::vector<int>> adjEdge;
    std::unordered_set<int> cycle;
    int startCycle;


public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        adjEdge.resize(n + 1);

        std::vector<std::vector<int>> edgeConnections(n);

        for (const auto& e : edges) {
            adjEdge[e[0]].push_back(e[1]);
            adjEdge[e[1]].push_back(e[0]);
        }
        
        visited.assign(n + 1, false);
        startCycle = -1;
        dfs(1, -1);

        for (int i = edges.size() - 1; i >= 0; i--) {
            if (cycle.count(edges[i][0]) && cycle.count(edges[i][1])) {
                return {edges[i][0], edges[i][1]};
            }
        }
        

        return {0, 0};
    }


    bool dfs(int node, int par) {
        if (visited[node]) {
            startCycle = node;
            return true;
        }
        visited[node] = true;

        for (int n : adjEdge[node]) {
            if (n == par) continue;
            if (dfs(n, node)) {
                if (startCycle != -1) cycle.insert(node);
                if (node == startCycle) {
                    startCycle = -1;
                }
                return true;
            }
        }
        return false;
    }
};
