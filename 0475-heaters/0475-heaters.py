import bisect

class Solution:
    def findRadius(self, houses, heaters):
        heaters.sort()
        radius = 0

        for house in houses:
            i = bisect.bisect_left(heaters, house)

            left = house - heaters[i - 1] if i > 0 else float('inf')
            right = heaters[i] - house if i < len(heaters) else float('inf')

            radius = max(radius, min(left, right))

        return radius