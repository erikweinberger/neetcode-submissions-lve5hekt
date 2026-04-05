class Solution {
private:
    bool currSurounded = true;

public:
    void solve(vector<vector<char>>& board) {
        std::vector<std::vector<bool>> visisted(board.size(), std::vector(board[0].size(), false));
        std::vector<std::pair<int, int>> currIteration;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (!visisted[i][j] && board[i][j] == 'O') {
                    visisted[i][j] = true;
                    currIteration.push_back({i, j});
                    if (i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1) currSurounded = false;
                    dfs(board, i, j, visisted, currIteration);
                    std::cerr << "i , j " << i << " , " << j << "currSurounded = " << currSurounded << '\n';
                    if (currSurounded) {
                        for (auto& cord : currIteration) {
                            board[cord.first][cord.second] = 'X';
                        }
                    }
                    currIteration.clear();
                    currSurounded = true;
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j, std::vector<std::vector<bool>>& visisted, std::vector<std::pair<int, int>>& currIteration) {
        std::vector<std::pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto& dir : directions) {
            int ni = i + dir.first, nj = j + dir.second;

            if (ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size() && board[ni][nj] == 'O' && !visisted[ni][nj]) {
                if (ni == 0 || ni == board.size() - 1 || nj == 0 || nj == board[0].size() - 1) currSurounded = false;
                visisted[ni][nj] = true;
                currIteration.push_back({ni, nj});
                dfs(board, ni, nj, visisted, currIteration);
            }
        }
    }
};
