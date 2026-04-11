class Solution:
    def minimumDistance(self, nums):
        from collections import defaultdict
        
        pos = defaultdict(list)
        
        for i, v in enumerate(nums):
            pos[v].append(i)
        
        ans = float('inf')
        
        for arr in pos.values():
            if len(arr) < 3:
                continue
            
            # sliding window of size 3
            for i in range(len(arr) - 2):
                a = arr[i]
                c = arr[i + 2]
                ans = min(ans, 2 * (c - a))
        
        return ans if ans != float('inf') else -1