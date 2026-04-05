

class Solution {
struct QueueItem {
    std::pair<int, int> pos;
    int t;
};

struct CompareQueueItem {
    bool operator()(const QueueItem& a, const QueueItem& b) const {
        return a.t > b.t;
    }
};

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        auto timeMatrix{std::vector(n, std::vector<int>(n, INT_MAX))};
        std::vector<std::pair<int, int>> dirs{{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};

        std::priority_queue<QueueItem, std::vector<QueueItem>, CompareQueueItem> pq;

        pq.push({{0,0}, grid[0][0]});

        while (!pq.empty()) {
            const QueueItem item = pq.top();
            pq.pop();
            auto [i, j] = item.pos;
            int t = item.t;
            if (i == n-1 && j == n-1) return t;

            if (t >= timeMatrix[i][j]) continue;
            timeMatrix[i][j] = t;
            for (const auto [x, y] : dirs) {
                if (i + x >= 0 && i + x < n && j + y >= 0 && j + y < n) {
                    int newTime = std::max(std::abs(grid[i + x][j + y]), t);
                    pq.push({{i + x, j + y}, newTime});
                }
            }
        }

   

        return timeMatrix[n - 1][n - 1];
    }
};
