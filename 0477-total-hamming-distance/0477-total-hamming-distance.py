class Solution:
    def totalHammingDistance(self, nums):
        total = 0
        n = len(nums)

        for bit in range(32):
            ones = 0
            for num in nums:
                if (num >> bit) & 1:
                    ones += 1
            zeros = n - ones
            total += ones * zeros

        return total