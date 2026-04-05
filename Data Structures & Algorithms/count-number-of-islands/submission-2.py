class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        n = len(grid)
        m = len(grid[0])

        visit = set()
        islands = 0

        def bfs(i, j):
            q = collections.deque()
            visit.add((i, j))
            q.append((i, j))

            while q:
                i, j = q.popleft()
                directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

                for im, jm in directions:
                    r, c = i + im, j + jm
                    if ((r, c) not in visit 
                        and r in range(n)
                        and c in range(m)
                        and grid[r][c] == "1"):

                        q.append((r, c))
                        visit.add((r, c))
                        


        for i in range(n):
            for j in range(m):
                if grid[i][j] == "1" and (i, j) not in visit:
                    bfs(i, j)
                    islands += 1
                visit.add((i, j))
        
        
        return islands



        