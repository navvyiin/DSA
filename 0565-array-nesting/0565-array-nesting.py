from typing import List

class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        visited = [False] * len(nums)
        max_len = 0

        for i in range(len(nums)):
            if not visited[i]:
                count = 0
                current = i

                while not visited[current]:
                    visited[current] = True
                    current = nums[current]
                    count += 1

                max_len = max(max_len, count)

        return max_len