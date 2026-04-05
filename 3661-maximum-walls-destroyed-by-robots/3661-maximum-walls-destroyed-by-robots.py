class Solution:
    def maxWalls(self, robots, distance, walls):
        import bisect
        
        # Sort robots with distances
        robots_with_d = sorted(zip(robots, distance))
        robots = [r for r, _ in robots_with_d]
        distance = [d for _, d in robots_with_d]
        walls.sort()
        
        n = len(robots)
        m = len(walls)
        
        # Precompute intervals
        left_intervals = []
        right_intervals = []
        
        for i in range(n):
            # left interval
            left_limit = robots[i] - distance[i]
            left_block = robots[i-1] if i > 0 else -10**18
            l = max(left_limit, left_block)
            left_intervals.append((l, robots[i]))
            
            # right interval
            right_limit = robots[i] + distance[i]
            right_block = robots[i+1] if i < n-1 else 10**18
            r = min(right_limit, right_block)
            right_intervals.append((robots[i], r))
        
        # DP over robots, tracking last covered wall index
        from functools import lru_cache
        
        @lru_cache(None)
        def dp(i, last_idx):
            if i == n:
                return 0
            
            res = 0
            
            # Try left
            l, r = left_intervals[i]
            li = bisect.bisect_left(walls, l)
            ri = bisect.bisect_right(walls, r)
            
            gain = 0
            new_last = last_idx
            
            for idx in range(li, ri):
                if idx > last_idx:
                    gain += 1
                    new_last = idx
            
            res = max(res, gain + dp(i + 1, new_last))
            
            # Try right
            l, r = right_intervals[i]
            li = bisect.bisect_left(walls, l)
            ri = bisect.bisect_right(walls, r)
            
            gain = 0
            new_last = last_idx
            
            for idx in range(li, ri):
                if idx > last_idx:
                    gain += 1
                    new_last = idx
            
            res = max(res, gain + dp(i + 1, new_last))
            
            return res
        
        return dp(0, -1)