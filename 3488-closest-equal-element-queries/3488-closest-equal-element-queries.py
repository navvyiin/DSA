from collections import defaultdict
import bisect

class Solution:
    def solveQueries(self, nums, queries):
        n = len(nums)
        
        # Map value -> sorted list of indices
        pos = defaultdict(list)
        for i, v in enumerate(nums):
            pos[v].append(i)
        
        res = []
        
        for q in queries:
            v = nums[q]
            indices = pos[v]
            
            # If only one occurrence
            if len(indices) == 1:
                res.append(-1)
                continue
            
            # Find position of q in indices
            i = bisect.bisect_left(indices, q)
            
            # Previous and next indices in circular manner
            prev_idx = indices[i - 1] if i > 0 else indices[-1]
            next_idx = indices[i + 1] if i < len(indices) - 1 else indices[0]
            
            # Circular distances
            d1 = min(abs(q - prev_idx), n - abs(q - prev_idx))
            d2 = min(abs(q - next_idx), n - abs(q - next_idx))
            
            res.append(min(d1, d2))
        
        return res