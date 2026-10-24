class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str,
                          arriveBob: str, leaveBob: str) -> int:
        days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        prefix = [0] * 13
        for i in range(1, 13):
            prefix[i] = prefix[i - 1] + days[i - 1]
        def to_day(date):
            month, day = map(int, date.split('-'))
            return prefix[month - 1] + day
        start = max(to_day(arriveAlice), to_day(arriveBob))
        end = min(to_day(leaveAlice), to_day(leaveBob))
        return max(0, end - start + 1)