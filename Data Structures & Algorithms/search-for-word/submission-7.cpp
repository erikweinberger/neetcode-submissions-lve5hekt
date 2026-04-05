class Solution {
public:
    bool result = false;

    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                backtracker(0, {i, j}, {}, board, word);
                if (result) break;
            }
            if (result) break;
        }

        return result;
        
    }

private:
    void backtracker(int currWordPos, std::pair<int, int> boardPos, std::vector<std::pair<int, int>> visited, std::vector<std::vector<char>> &board, std::string word) {
        if (word[currWordPos] != board[boardPos.first][boardPos.second]) return;

        if (currWordPos == word.size() - 1 || result == true) {
            result = true;
            return;
        }

        std::vector<std::vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        visited.push_back(boardPos);

        for (auto & dir : directions) {
            int newI = boardPos.first + dir[0];
            int newJ = boardPos.second + dir[1];
            bool visFlag = false;
            for (auto & vis : visited) {
                if (vis.first == newI && vis.second == newJ) {
                    visFlag = true;
                    continue;
                }
            }
            if (visFlag) continue;

            if (newI >= 0 && newI < board.size() && newJ >= 0 && board[newI].size()) {
                backtracker(currWordPos + 1, {newI, newJ}, visited, board, word);
            }
        }

        visited.pop_back();
    }
};
