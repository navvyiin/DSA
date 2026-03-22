from typing import List

class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        
        if m * n != r * c:
            return mat
        
        result = [[0] * c for _ in range(r)]
        idx = 0
        
        for i in range(m):
            for j in range(n):
                result[idx // c][idx % c] = mat[i][j]
                idx += 1
        
        return result