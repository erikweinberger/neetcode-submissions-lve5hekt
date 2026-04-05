class Solution {
public:
    std::vector<std::vector<std::string>> result;

    vector<vector<string>> solveNQueens(int n) {
        std::string row(n, '.');
        std::vector<std::string> currBoard(n, row);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                addQueen(i, j, 0, currBoard);
                backtrackingNQueens(1, currBoard, n, i);
                deleteQueen(i, j, 0, currBoard);
            }
        }

        return result;
    }

    void backtrackingNQueens(int currQueen, std::vector<std::string> currBoard, int n, int rowDone) {
        if (currQueen == n) {
            result.push_back(nicePrint(currBoard, n));
            return;
        } 

        for (int i = rowDone + 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (currBoard[i][j] == '.') {
                    addQueen(i, j, currQueen, currBoard);
                    backtrackingNQueens(currQueen + 1, currBoard, n, i);
                    deleteQueen(i, j, currQueen, currBoard);
                }
            }
        }
    }

    vector<string> nicePrint(std::vector<std::string> currBoard, int n) {
        std::string row(n, '.');
        std::vector<std::string> res(n, row);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (currBoard[i][j] == 'Q') {
                    res[i][j] = 'Q';
                }
            }
        }
        return res;
    }

    void addQueen(int row, int col, int currQueen, std::vector<std::string>& currBoard) {
        currBoard[row][col] = 'Q';
        int n = currBoard.size();
        for (int i = 0; i < n; ++i) {
            if (currBoard[row][i] == '.') currBoard[row][i] = currQueen + '0';
            if (currBoard[i][col] == '.') currBoard[i][col] = currQueen + '0';

            if (row - i >= 0 && col - i >= 0 && currBoard[row - i][col - i] == '.') currBoard[row - i][col - i] = currQueen + '0';
            if (row - i >= 0 && col + i < n && currBoard[row - i][col + i] == '.') currBoard[row - i][col + i] = currQueen + '0';
            if (row + i < n && col + i < n && currBoard[row + i][col + i] == '.') currBoard[row + i][col + i] = currQueen + '0';
            if (row + i < n && col - i >= 0 && currBoard[row + i][col - i] == '.') currBoard[row + i][col - i] = currQueen + '0';
        }
    }

    void deleteQueen(int row, int col, int currQueen, std::vector<std::string>& currBoard) {
        currBoard[row][col] = '.';
        int n = currBoard.size();
        for (int i = 0; i < n; ++i) {
            if (currBoard[row][i] == currQueen + '0') currBoard[row][i] = '.';
            if (currBoard[i][col] == currQueen + '0') currBoard[i][col] = '.';

            if (row - i >= 0 && col - i >= 0 && currBoard[row - i][col - i] == currQueen + '0') currBoard[row - i][col - i] = '.';
            if (row - i >= 0 && col + i < n && currBoard[row - i][col + i] == currQueen + '0') currBoard[row - i][col + i] = '.';
            if (row + i < n && col + i < n && currBoard[row + i][col + i] == currQueen + '0') currBoard[row + i][col + i] = '.';
            if (row + i < n && col - i >= 0 && currBoard[row + i][col - i] == currQueen + '0') currBoard[row + i][col - i] = '.';
        }
    }
};
