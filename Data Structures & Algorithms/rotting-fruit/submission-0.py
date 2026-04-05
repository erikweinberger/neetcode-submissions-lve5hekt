class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        q = collections.deque()
        visited = set()

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    q.append((i, j))

        minutes = 0
        while q:
            minutes += 1
            temp_q = collections.deque()
            while q:
                directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
                i, j = q.popleft()
                for im, jm in directions:
                    new_i, new_j = i + im, j + jm
                    if (new_i in range(n)
                        and new_j in range(m)
                        and grid[new_i][new_j] == 1
                        and (new_i, new_j) not in visited
                    ): 
                        visited.add((new_i, new_j))
                        temp_q.append((new_i, new_j))
                        grid[new_i][new_j] = 2
            print(temp_q)
            q = temp_q
        
        minutes = minutes - 1 if minutes > 0 else minutes
        
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    minutes = -1

        return minutes




        