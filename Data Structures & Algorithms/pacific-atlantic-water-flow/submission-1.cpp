class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        int n = heights.size(), m = heights[0].size();

        std::vector<int> row(m, 0);
        std::vector<std::vector<int>> visited(n, row);

        std::queue<std::pair<int, int>> q;

        for (int col = 0; col < m; ++col) {
            if (!(visited[0][col] == 1 || visited[0][col] == 3)) {
                if (visited[0][col] == 0) visited[0][col] = 1;
                else visited[0][col] = 3;
                q.push({0, col});
            }
        }

        for (int rowi = 0; rowi < n; ++rowi) {
            if (!(visited[rowi][0] == 1 || visited[rowi][0] == 3)) {
                if (visited[rowi][0] == 0) visited[rowi][0] = 1;
                else visited[rowi][0] = 3;
                q.push({rowi, 0});
            }
        }
        bfs(heights, visited, q, 1);

        for (int col = 0; col < m; ++col) {
            if (!(visited[n-1][col] == 2 || visited[n-1][col] == 3)) {
                if (visited[n-1][col] == 0) visited[n-1][col] = 2;
                else visited[n-1][col] = 3;
                q.push({n-1, col});
            }
        }
        for (int rowi = 0; rowi < n; ++rowi) {
            if (!(visited[rowi][m-1] == 2 || visited[rowi][m-1] == 3)) {
                if (visited[rowi][m-1] == 0) visited[rowi][m-1] = 2;
                else visited[rowi][m-1] = 3;
                q.push({rowi, m-1});
            }
        }
        bfs(heights, visited, q, 2);

        vector<vector<int>> result;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (visited[i][j] == 3) result.push_back({i, j});
            }
        }
        return result;
    }

    void bfs(vector<vector<int>>& heights, std::vector<std::vector<int>>& visited, std::queue<std::pair<int, int>>& q, int sea) {
        int n = heights.size(), m = heights[0].size();
        std::vector<std::pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto cell = q.front(); q.pop();
            int i = cell.first, j = cell.second;

            for (auto dir : directions) {
                int ni = i + dir.first;
                int nj = j + dir.second;
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if (heights[ni][nj] < heights[i][j]) continue;

                bool hasSea = false;
                if (sea == 1) {
                    if (visited[ni][nj] == 1 || visited[ni][nj] == 3) hasSea = true;
                } else {
                    if (visited[ni][nj] == 2 || visited[ni][nj] == 3) hasSea = true;
                }

                if (!hasSea) {
                    if (visited[ni][nj] == 0) visited[ni][nj] = sea;
                    else visited[ni][nj] = 3;
                    q.push({ni, nj});
                }
            }
        }
    }
};

