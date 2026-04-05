class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0


        visited = set()
        n, m = len(grid), len(grid[0])
        max_area = 0

        def dfs_area(i, j):
            q = collections.deque()
            q.append((i, j))
            visited.add((i, j))

            directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
            curr_area = 0
            while q:
                curr_i, curr_j = q.popleft()
                curr_area += 1
                for im, jm in directions:
                    r, c = curr_i + im, curr_j + jm
                    if (r in range(n)
                        and c in range(m)
                        and (r, c) not in visited
                        and grid[r][c] == 1
                    ):
                        visited.add((r, c))
                        q.append((r, c))
                
            return curr_area


        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1 and (i, j) not in visited:
                    max_area = max(dfs_area(i, j), max_area)

        return max_area
        