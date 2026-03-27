from typing import List

class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        m, n = len(mat), len(mat[0])
        k %= n  # effective shifts
        
        for i in range(m):
            for j in range(n):
                if i % 2 == 0:
                    # even row → left shift
                    if mat[i][j] != mat[i][(j + k) % n]:
                        return False
                else:
                    # odd row → right shift
                    if mat[i][j] != mat[i][(j - k) % n]:
                        return False
        return True