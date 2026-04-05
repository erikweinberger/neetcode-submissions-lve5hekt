class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        std::queue<std::vector<int>> q;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) q.push({i, j, 0});
            }
        }

        std::vector<std::pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto nextNode = q.front();
            q.pop();
            int i = nextNode[0], j = nextNode[1], currDist = nextNode[2];

            for (auto dir : directions) {
                int newI = dir.first + i, newJ = dir.second + j;
                if (newI >= 0 && newI < n && newJ >= 0 && newJ < m && grid[newI][newJ] > currDist + 1) {
                    grid[newI][newJ] = currDist + 1;
                    q.push({newI, newJ, currDist + 1});
                }
            }
        }
    }
};
