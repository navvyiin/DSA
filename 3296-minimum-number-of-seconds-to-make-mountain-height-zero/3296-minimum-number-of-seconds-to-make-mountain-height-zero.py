import math
import heapq

class Solution:
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: list[int]) -> int:
        # Using a priority queue to always pick the worker who can finish 
        # the next unit of work fastest.
        # Heap stores: (next_time_needed, base_time, current_units_reduced)
        pq = []
        for t in workerTimes:
            # First unit of work takes 1 * workerTimes[i]
            heapq.heappush(pq, (t, t, 1))
            
        total_time = 0
        for _ in range(mountainHeight):
            time_needed, base_time, units = heapq.heappop(pq)
            total_time = max(total_time, time_needed)
            
            # Next time needed for this worker to reduce 1 more unit:
            # (units + 1) * base_time
            next_units = units + 1
            next_time = time_needed + next_units * base_time
            heapq.heappush(pq, (next_time, base_time, next_units))
            
        return total_time
