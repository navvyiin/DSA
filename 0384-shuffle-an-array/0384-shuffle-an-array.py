import random

class Solution:

    def __init__(self, nums):
        self.original = nums[:]
        self.array = nums[:]

    def reset(self):
        self.array = self.original[:]
        return self.array

    def shuffle(self):
        # Fisher–Yates shuffle
        for i in range(len(self.array) - 1, 0, -1):
            j = random.randint(0, i)
            self.array[i], self.array[j] = self.array[j], self.array[i]
        return self.array