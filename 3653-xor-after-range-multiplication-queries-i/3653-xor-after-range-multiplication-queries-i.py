class Solution:
    def xorAfterQueries(self, nums, queries):
        MOD = 10**9 + 7
        
        for l, r, k, v in queries:
            for i in range(l, r + 1, k):
                nums[i] = (nums[i] * v) % MOD
        
        res = 0
        for x in nums:
            res ^= x
        
        return res