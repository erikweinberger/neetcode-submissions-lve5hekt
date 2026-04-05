class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        std::vector<int> mst(n, -1); // index is the node and the value is the parent
        std::vector<int> cost(n, INT_MAX);
        std::vector<bool> visited(n, false);
        int res = 0;

        std::priority_queue<std::pair<int, int>, vector<std::pair<int,int>>, std::greater<std::pair<int, int>>> dist_node_q;

        dist_node_q.emplace(0, 0);
        cost[0] = 0;

        while (!dist_node_q.empty()) {
            auto [c, node] = dist_node_q.top();
            dist_node_q.pop();

            if (visited[node]) continue;

            visited[node] = true;
            res += c;

            for (int i{0}; i < n; ++i) {
                if (!visited[i]) {
                    int dist = std::abs(points[node][0] - points[i][0]) + std::abs(points[node][1] - points[i][1]);
                    if (dist < cost[i]) {
                        cost[i] = dist;
                        mst[i] = node;
                        dist_node_q.emplace(dist, i);
                    }
                }
            }
        }

        return res;
    }
};
