class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        return self.check_rows(board) and self.check_cols(board) and self.check_squares(board)


    def check_rows(self, board: List[List[str]]) -> bool:
        for row in board:
            check_set = set()
            for num in row:
                if num in check_set:
                    print(f"in check rows: for num:{num}")
                    return False
                if num != ".":
                    check_set.add(num)
        
        return True

    def check_cols(self, board: List[List[str]]) -> bool:
        for i in range(len(board[0])):
            check_set = set()
            for j in range(len(board)):
                if board[j][i] in check_set:
                    print(f"in check cols: for i:{i} j:{j} num:{board[j][i]}")
                    return False
                if board[j][i] != ".":
                    check_set.add(board[j][i])
        return True

    def check_squares(self, board: List[List[str]]) -> bool:
        for row in range(0, len(board[0]), 3):
            for col in range(0, len(board[0]), 3):
                check_set = set()
                for i in range(3):
                    for j in range(3):
                        if board[row + i][col + j] in check_set:
                            print(f"in check square: for row:{row} col:{col} i:{i} j:{j} num:{board[row + i][col + j]}")
                            return False
                        if board[row + i][col + j] != ".":
                            check_set.add(board[row + i][col + j])
        
        return True
                        




