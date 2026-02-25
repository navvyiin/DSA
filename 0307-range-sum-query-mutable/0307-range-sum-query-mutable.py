class NumArray:
    def __init__(self, nums):
        self.n = len(nums)
        self.bit = [0] * (self.n + 1)
        self.arr = nums[:]

        for i, v in enumerate(nums):
            self._add(i + 1, v)

    def _add(self, i, delta):
        while i <= self.n:
            self.bit[i] += delta
            i += i & -i

    def _prefix_sum(self, i):
        s = 0
        while i > 0:
            s += self.bit[i]
            i -= i & -i
        return s

    def update(self, index, val):
        delta = val - self.arr[index]
        self.arr[index] = val
        self._add(index + 1, delta)

    def sumRange(self, left, right):
        return self._prefix_sum(right + 1) - self._prefix_sum(left)