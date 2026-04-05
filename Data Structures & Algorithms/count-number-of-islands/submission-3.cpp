class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        std::vector<bool> row(m, false);
        std::vector<std::vector<bool>> visited(n, row);
        int num_islands = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    visited[i][j] = true;
                    num_islands++;
                    dfsIslands(i, j, grid, visited);
                }
            }
        }

        return num_islands;
        
    }

private:

    void dfsIslands(int row, int col, vector<vector<char>>& grid, std::vector<std::vector<bool>>& visited) {

        std::vector<std::pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto &dir : directions) {
            int i = row + dir.first, j = col + dir.second;
            if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) continue;
            if (!visited[i][j] && grid[i][j] == '1') {
                visited[i][j] = true;
                dfsIslands(i, j, grid, visited);
            }
        }
    }
};
