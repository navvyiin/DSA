import heapq
from collections import defaultdict

class Solution:
    def getSkyline(self, buildings: list[list[int]]) -> list[list[int]]:
        events = []
        for left, right, height in buildings:
            events.append((left, -height))   # building starts
            events.append((right, height))   # building ends

        # Sort by x, then by height
        events.sort()

        result = []
        heap = [0]          # max heap (store negative heights)
        height_count = defaultdict(int)
        height_count[0] = 1

        prev_max = 0

        for x, h in events:
            if h < 0:
                # Add building
                heapq.heappush(heap, h)
                height_count[-h] += 1
            else:
                # Remove building
                height_count[h] -= 1

            # Clean up heap
            while heap and height_count[-heap[0]] == 0:
                heapq.heappop(heap)

            curr_max = -heap[0]

            if curr_max != prev_max:
                result.append([x, curr_max])
                prev_max = curr_max

        return result