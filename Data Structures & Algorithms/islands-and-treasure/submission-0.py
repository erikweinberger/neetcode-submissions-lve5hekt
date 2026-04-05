class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        q = collections.deque()
        n, m =len(grid), len(grid[0])

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 0:
                    q.append((i, j))
        
        while q:
            directions = [[1,0], [-1, 0], [0, 1], [0, -1]]
            i, j = q.popleft()
            distance = grid[i][j] + 1
            
            for im, jm in directions:
                new_i, new_j = i + im, j + jm
                if (new_i in range(n)
                    and new_j in range(m)
                    and distance < grid[new_i][new_j]
                    and grid[new_i][new_j] != -1
                ):
                    grid[new_i][new_j] = distance
                    q.append((new_i, new_j))

        return None

        