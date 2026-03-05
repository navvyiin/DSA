class Solution:
    def findRightInterval(self, intervals):
        n = len(intervals)
        starts = sorted((intervals[i][0], i) for i in range(n))
        result = [-1] * n

        import bisect

        for i, (s, e) in enumerate(intervals):
            pos = bisect.bisect_left(starts, (e,))
            if pos < n:
                result[i] = starts[pos][1]

        return result