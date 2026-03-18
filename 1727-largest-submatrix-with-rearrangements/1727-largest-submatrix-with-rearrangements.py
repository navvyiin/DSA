class Solution:
    def largestSubmatrix(self, matrix):
        m, n = len(matrix), len(matrix[0])
        
        # Step 1: Build heights (histogram)
        for i in range(1, m):
            for j in range(n):
                if matrix[i][j] == 1:
                    matrix[i][j] += matrix[i - 1][j]
        
        max_area = 0
        
        # Step 2: For each row, sort heights in descending order
        for i in range(m):
            row = sorted(matrix[i], reverse=True)
            for j in range(n):
                max_area = max(max_area, row[j] * (j + 1))
        
        return max_area