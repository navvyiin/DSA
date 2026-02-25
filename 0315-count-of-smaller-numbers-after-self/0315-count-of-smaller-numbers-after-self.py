class Solution:
    def countSmaller(self, nums):
        # Coordinate compression
        sorted_vals = sorted(set(nums))
        index = {v: i + 1 for i, v in enumerate(sorted_vals)}

        size = len(sorted_vals)
        bit = [0] * (size + 1)

        def update(i):
            while i <= size:
                bit[i] += 1
                i += i & -i

        def query(i):
            s = 0
            while i > 0:
                s += bit[i]
                i -= i & -i
            return s

        result = [0] * len(nums)

        # Traverse from right to left
        for i in range(len(nums) - 1, -1, -1):
            idx = index[nums[i]]
            result[i] = query(idx - 1)
            update(idx)

        return result