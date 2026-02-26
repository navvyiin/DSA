class Solution:
    def minPatches(self, nums, n):
        patches = 0
        reach = 1
        i = 0

        while reach <= n:
            if i < len(nums) and nums[i] <= reach:
                reach += nums[i]
                i += 1
            else:
                reach += reach
                patches += 1

        return patches