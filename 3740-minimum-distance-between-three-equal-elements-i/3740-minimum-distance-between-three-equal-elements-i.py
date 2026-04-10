class Solution:
    def minimumDistance(self, nums):
        from collections import defaultdict
        
        pos = defaultdict(list)
        
        # store indices for each value
        for i, v in enumerate(nums):
            pos[v].append(i)
        
        ans = float('inf')
        
        # process each value group
        for indices in pos.values():
            m = len(indices)
            if m < 3:
                continue
            
            # try consecutive triples (optimal)
            for i in range(m - 2):
                a, b, c = indices[i], indices[i + 1], indices[i + 2]
                dist = 2 * (c - a)  # simplified formula
                ans = min(ans, dist)
        
        return ans if ans != float('inf') else -1