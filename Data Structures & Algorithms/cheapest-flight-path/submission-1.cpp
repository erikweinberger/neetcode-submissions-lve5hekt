class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build adjacency list
        std::unordered_map<int, std::vector<std::pair<int, int>>> adj;
        for (const auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }
        
        // Track minimum cost to reach each city
        std::vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;
        
        // BFS queue: (city, cost, stops)
        std::queue<std::tuple<int, int, int>> q;
        q.push({src, 0, 0});
        
        int result = INT_MAX;
        
        while (!q.empty()) {
            auto [city, cost, stops] = q.front();
            q.pop();
            
            // Exceeded stop limit
            if (stops > k) continue;
            
            // Explore neighbors
            for (const auto& [nextCity, price] : adj[city]) {
                int newCost = cost + price;
                
                // Only explore if this gives us a better cost
                // OR if we haven't fully explored this city yet
                if (newCost < minCost[nextCity]) {
                    minCost[nextCity] = newCost;
                    
                    if (nextCity == dst) {
                        result = std::min(result, newCost);
                    } else {
                        q.push({nextCity, newCost, stops + 1});
                    }
                }
            }
        }
        
        return result == INT_MAX ? -1 : result;
    }
};
