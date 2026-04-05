class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        std::unordered_map<int, std::vector<std::pair<int, int>>> adj; // key: src: val = (dest, cost)
        for (auto f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        int res = INT_MAX;
        std::deque<std::vector<int>> bfsQ; // (currCity, cost, numf)
        bfsQ.push_back({src, 0, 0});
        while(!bfsQ.empty()) {
            auto cP = bfsQ.back();
            bfsQ.pop_back();
            int currCity = cP[0], cost = cP[1], numS = cP[2];
            if (currCity == dst) {
                res = std::min(res, cost);
            }
            if (numS > k) continue;

            for (auto a : adj[currCity]) {
                bfsQ.push_back({a.first, cost + a.second, numS + 1});
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};
