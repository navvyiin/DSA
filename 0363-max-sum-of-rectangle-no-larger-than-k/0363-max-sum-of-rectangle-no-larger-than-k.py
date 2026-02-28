from bisect import bisect_left, insort

class Solution:
    def maxSumSubmatrix(self, matrix, k):
        m, n = len(matrix), len(matrix[0])
        ans = float('-inf')

        # Fix left column
        for left in range(n):
            row_sum = [0] * m

            # Expand right column
            for right in range(left, n):
                for i in range(m):
                    row_sum[i] += matrix[i][right]

                # Now find max subarray sum <= k in row_sum
                prefix_sums = [0]
                curr_sum = 0

                for r in row_sum:
                    curr_sum += r
                    # We want smallest prefix >= curr_sum - k
                    idx = bisect_left(prefix_sums, curr_sum - k)
                    if idx < len(prefix_sums):
                        ans = max(ans, curr_sum - prefix_sums[idx])
                    insort(prefix_sums, curr_sum)

        return ans