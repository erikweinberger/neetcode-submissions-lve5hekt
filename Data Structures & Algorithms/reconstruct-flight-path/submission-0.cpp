class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        std::unordered_map<std::string, std::deque<std::string>> adj;
        for (auto t : tickets) {
            adj[t[0]].push_back(t[1]);
        }
        for (auto& [src, dests] : adj) {
            std::sort(dests.rbegin(), dests.rend());
        }

        std::vector<std::string> res;
        res.reserve(tickets.size() + 1);

        dfs("JFK", adj, res);
        std::reverse(res.begin(), res.end());

        return res;


    }

    void dfs(const std::string& city, std::unordered_map<std::string, std::deque<std::string>>& adj, std::vector<std::string>& res) {

        while(!adj[city].empty()) {
            std::string dest = adj[city].back();
            adj[city].pop_back();
            dfs(dest, adj, res);
        }

        res.push_back(city);
    }

    
};
