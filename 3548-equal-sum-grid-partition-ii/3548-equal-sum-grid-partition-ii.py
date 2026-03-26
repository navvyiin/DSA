from collections import Counter
from typing import List

class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        total = sum(sum(row) for row in grid)

        # Horizontal cuts
        top_counts = Counter()
        bottom_counts = Counter()

        for row in grid:
            for v in row:
                bottom_counts[v] += 1

        top_sum = 0
        bottom_sum = total

        for i in range(m - 1):
            row_sum = sum(grid[i])
            for v in grid[i]:
                top_counts[v] += 1
                bottom_counts[v] -= 1

            top_sum += row_sum
            bottom_sum -= row_sum

            if top_sum == bottom_sum:
                return True

            diff = abs(top_sum - bottom_sum)

            # Decide which section is larger
            if top_sum > bottom_sum:
                rows, cols = i + 1, n
                counts = top_counts

                # 2D → always safe
                if rows > 1 and cols > 1:
                    if counts[diff] > 0:
                        return True
                else:
                    # 1D → must remove endpoint
                    if rows == 1:
                        if grid[0][0] == diff or grid[0][n-1] == diff:
                            return True
                    else:
                        if grid[0][0] == diff or grid[i][0] == diff:
                            return True
            else:
                rows, cols = m - (i + 1), n
                counts = bottom_counts

                if rows > 1 and cols > 1:
                    if counts[diff] > 0:
                        return True
                else:
                    if rows == 1:
                        if grid[i+1][0] == diff or grid[i+1][n-1] == diff:
                            return True
                    else:
                        if grid[i+1][0] == diff or grid[m-1][0] == diff:
                            return True

        # Vertical cuts
        left_counts = Counter()
        right_counts = Counter()

        for j in range(n):
            for i in range(m):
                right_counts[grid[i][j]] += 1

        left_sum = 0
        right_sum = total

        for j in range(n - 1):
            col_sum = 0
            for i in range(m):
                v = grid[i][j]
                left_counts[v] += 1
                right_counts[v] -= 1
                col_sum += v

            left_sum += col_sum
            right_sum -= col_sum

            if left_sum == right_sum:
                return True

            diff = abs(left_sum - right_sum)

            if left_sum > right_sum:
                rows, cols = m, j + 1
                counts = left_counts

                if rows > 1 and cols > 1:
                    if counts[diff] > 0:
                        return True
                else:
                    if cols == 1:
                        if grid[0][0] == diff or grid[m-1][0] == diff:
                            return True
                    else:
                        if grid[0][0] == diff or grid[0][j] == diff:
                            return True
            else:
                rows, cols = m, n - (j + 1)
                counts = right_counts

                if rows > 1 and cols > 1:
                    if counts[diff] > 0:
                        return True
                else:
                    if cols == 1:
                        if grid[0][j+1] == diff or grid[m-1][j+1] == diff:
                            return True
                    else:
                        if grid[0][j+1] == diff or grid[0][n-1] == diff:
                            return True

        return False