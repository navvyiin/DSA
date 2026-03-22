class Solution:
    def rotate(self, matrix):
        n = len(matrix)
        return [[matrix[n - j - 1][i] for j in range(n)] for i in range(n)]

    def findRotation(self, mat, target):
        for _ in range(4):
            if mat == target:
                return True
            mat = self.rotate(mat)
        return False