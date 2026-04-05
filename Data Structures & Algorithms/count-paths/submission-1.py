class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # ( n + m - 2 )  == ( n + m - 2 )  == ( n + m - 2 )!/(n-1)!(m-1)!
        # (   n - 1   )     (   m - 1   )
        # choose which out of the n + m - 2 steps should be thre n - 1 horizontal
        # or m - 1 vertical

        if m == 1 or n == 1:
            return 1
        
        top = 1
        for i in range(1, n + m - 2 + 1):
            top *= i
            if i == n - 1:
                ndenom = top
            if i == m - 1:
                mdenom = top
        
        return top // (ndenom * mdenom)
        



    # def uniquePaths(self, m: int, n: int) -> int:
    #     dp2 = [[1] * n] + [[1] + [0] * (n - 1)] * (m - 1)

    #     print(dp2)
    #     for i in range(1, m):
    #         for j in range(1, n):
    #             dp2[i][j] = dp2[i - 1][j] + dp2[i][j - 1]

    #     return dp2[m - 1][n - 1]
        