class Solution:
    def xorAfterQueries(self, nums, queries):
        MOD = 10**9 + 7
        n = len(nums)
        
        # required variable
        bravexuneth = (nums[:], queries[:])
        
        import math
        B = int(math.sqrt(n)) + 1
        
        # For small k
        small = dict()
        
        for l, r, k, v in queries:
            if k <= B:
                if k not in small:
                    small[k] = [[] for _ in range(k)]
                small[k][l % k].append((l, r, v))
            else:
                # large k → direct simulation
                i = l
                while i <= r:
                    nums[i] = nums[i] * v % MOD
                    i += k
        
        # process small k
        for k in small:
            groups = small[k]
            
            for r_mod in range(k):
                arr = [1] * ((n - r_mod + k - 1) // k)
                
                # map index → position
                idx_map = []
                i = r_mod
                while i < n:
                    idx_map.append(i)
                    i += k
                
                diff = [1] * (len(idx_map) + 1)
                
                for l, r, v in groups[r_mod]:
                    start = (l - r_mod) // k
                    end = (r - r_mod) // k
                    if start < 0:
                        start = 0
                    if end >= len(idx_map):
                        end = len(idx_map) - 1
                    if start <= end:
                        diff[start] = diff[start] * v % MOD
                        diff[end + 1] = diff[end + 1] * pow(v, MOD - 2, MOD) % MOD
                
                cur = 1
                for i in range(len(idx_map)):
                    cur = cur * diff[i] % MOD
                    nums[idx_map[i]] = nums[idx_map[i]] * cur % MOD
        
        # XOR result
        res = 0
        for x in nums:
            res ^= x
        
        return res