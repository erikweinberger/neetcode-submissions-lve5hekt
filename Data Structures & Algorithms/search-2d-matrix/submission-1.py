class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n = len(matrix)
        m = len(matrix[0])

        low = 0
        up = n * m - 1

        while low <= up:
            mid = (up - low) // 2 + low
            mid_val = matrix[mid // m][mid % m]
            if mid_val == target:
                return True
            elif mid_val > target:
                up = mid - 1
            else:
                low = mid + 1

        return False
        